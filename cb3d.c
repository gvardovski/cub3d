/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb3d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:41:46 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/06 14:17:50 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	init_main_struct(t_cmlx *cb3d, char **gv)
{
	cb3d->cng = malloc(sizeof(t_config));
	cb3d->cng->ceiling_color = (225 << 16) | (30 << 8) | 0;
	cb3d->cng->floor_color = (220 << 16) | (100 << 8) | 0;
	cb3d->cng->textures[NO].text_path = "./textures/North.ppm";
	cb3d->cng->textures[SO].text_path = "./textures/South.ppm";
	cb3d->cng->textures[EA].text_path = "./textures/East.ppm";
	cb3d->cng->textures[WE].text_path = "./textures/West.ppm";
	cb3d->map = NULL;
	cb3d->playerx = 0;
	cb3d->playery = 0;
	cb3d->fd = open(gv[1], O_RDONLY);
}

void start_game(t_cmlx *cb3d)
{
	cb3d->mlx = mlx_init();
	if (!cb3d->mlx)
		freeall(cb3d);
	cb3d->win = mlx_new_window(cb3d->mlx, WIDTH, HEIGHT, "CUB3D");
	cb3d->img = mlx_new_image(cb3d->mlx, WIDTH, HEIGHT);
	cb3d->win_data = mlx_get_data_addr(cb3d->img, &cb3d->bpp,
			&cb3d->size_line, &cb3d->endian);
}

int	main(int gc, char **gv)
{
	t_cmlx	*cb3d;

	if (gc != 2 || (gv[0][0] == '.' && gv[0][1] == '.'))
	{
		ft_printf("Wrong number of arguments\n");
		return(1);
	}
	cb3d = malloc(sizeof(t_cmlx));
	init_main_struct(cb3d, gv);
	map_reader(cb3d);
	check_map_valid_char(cb3d);
	check_wall_path(cb3d);
	start_game(cb3d);
	freeall(cb3d);
	return (0);
}
