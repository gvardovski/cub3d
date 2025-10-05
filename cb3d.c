/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb3d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:41:46 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/05 18:26:34 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	init_main_struct(t_cmlx *cb3d, char **gv)
{
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
}

int	main(int gc, char **gv)
{
	t_cmlx	*cb3d;

	if (gc != 2 || (gv[0][0] == '.' && gv[0][1] == '.'))
	{
		ft_printf("Wrong number of arguments\n");
		exit(1);
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