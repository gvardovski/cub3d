/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb3d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:41:46 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/12 20:23:15 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	init_main_struct(t_cmlx *cb3d, char **gv)
{
	cb3d->cng = malloc(sizeof(t_config));
	cb3d->cng->ceiling_color = color((int [3]){229, 228, 226});
	cb3d->cng->floor_color = color((int [3]){169, 169, 169});
	cb3d->map = NULL;
	cb3d->win_data = NULL;
	cb3d->img = NULL;
	cb3d->mlx = NULL;
	cb3d->win = NULL;
	cb3d->gridmap = NULL;
	cb3d->cng->textures[NO].text_path = "./textures/North.ppm";
	add_color_arr(cb3d, NO);
	cb3d->cng->textures[SO].text_path = "./textures/South.ppm";
	add_color_arr(cb3d, SO);
	cb3d->cng->textures[EA].text_path = "./textures/East.ppm";
	add_color_arr(cb3d, EA);
	cb3d->cng->textures[WE].text_path = "./textures/West.ppm";
	add_color_arr(cb3d, WE);
	cb3d->pl_x = 0;
	cb3d->pl_y = 0;
	cb3d->dir_x = 0;
	cb3d->dir_y = 0;
	cb3d->plane_x = 0;
	cb3d->plane_y = 0;
	cb3d->bpp = -1;
	cb3d->endian = -1;
	cb3d->size_line = -1;
	cb3d->fd = open(gv[1], O_RDONLY);
}

int	closewin(t_cmlx *cb3d)
{
	if (cb3d && cb3d->mlx)
		mlx_loop_end(cb3d->mlx);
	return (0);
}

int	handlevent(int keycode, t_cmlx *cb3d)
{
	if (keycode == KEY_ESC)
		closewin(cb3d);
	return (0);
}

void	start_game(t_cmlx *cb3d)
{
	cb3d->mlx = mlx_init();
	if (!cb3d->mlx)
		freeall(cb3d);
	cb3d->win = mlx_new_window(cb3d->mlx, WIDTH, HEIGHT, "CUB3D");
	cb3d->img = mlx_new_image(cb3d->mlx, WIDTH, HEIGHT);
	cb3d->win_data = mlx_get_data_addr(cb3d->img, &cb3d->bpp,
			&cb3d->size_line, &cb3d->endian);
	set_orient(cb3d);
	print_display(cb3d);
	mlx_hook(cb3d->win, 17, 0, closewin, cb3d);
	mlx_key_hook(cb3d->win, handlevent, cb3d);
	mlx_loop(cb3d->mlx);
}

int	main(int gc, char **gv)
{
	t_cmlx	*cb3d;

	if (gc != 2 || (gv[0][0] == '.' && gv[0][1] == '.'))
	{
		ft_printf("Wrong number of arguments\n");
		return (1);
	}
	cb3d = malloc(sizeof(t_cmlx));
	init_main_struct(cb3d, gv);
	map_reader(cb3d);
	check_map_valid_char(cb3d);
	check_wall_path(cb3d);
	cb3d->gridmap = map_to_arr(cb3d->map);
	start_game(cb3d);
	freeall(cb3d);
	return (0);
}
