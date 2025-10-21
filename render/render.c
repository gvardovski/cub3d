/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:15:22 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/21 20:12:59 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_orient_values(t_cmlx *cb3d, double x, double y, double px, double py)
{
	cb3d->dir_x = x;
	cb3d->dir_y = y;
	cb3d->plane_x = px;
	cb3d->plane_y = py;
}

void	set_orient(t_cmlx *cb3d)
{
	if (cb3d->orient == 'N')
		set_orient_values(cb3d, 0, -1, 0.66, 0);
	else if (cb3d->orient == 'S')
		set_orient_values(cb3d, 0, 1, -0.66, 0);
	else if (cb3d->orient == 'E')
		set_orient_values(cb3d, 1, 0, 0, 0.66);
	else if (cb3d->orient == 'W')
		set_orient_values(cb3d, -1, 0, 0, -0.66);
}

void	set_pixel(t_cmlx *cb3d, int x, int y, int color)
{
	int	pix;

	pix = (y * cb3d->size_line) + (x * (cb3d->bpp / 8));
	cb3d->win_data[pix] = color & 0xFF;
	cb3d->win_data[pix + 1] = (color >> 8) & 0xFF;
	cb3d->win_data[pix + 2] = (color >> 16) & 0xFF;
	if (cb3d->bpp == 32)
		cb3d->win_data[pix + 3] = 0x00;
}

void	draw_cf(t_cmlx *cb3d, char flag)
{
	int	x;
	int	y;
	int	color;
	int	size;

	if (flag == 'f')
	{
		y = 0;
		size = HEIGHT / 2;
		color = cb3d->cng->ceiling_color;
	}
	if (flag == 'c')
	{
		y = (HEIGHT / 2) - 1;
		size = HEIGHT;
		color = cb3d->cng->floor_color;
	}
	while (++y < size)
	{
		x = -1;
		while (++x < WIDTH)
			set_pixel(cb3d, x, y, color);
	}
}

void	print_display(t_cmlx *cb3d)
{
	mlx_destroy_image(cb3d->mlx, cb3d->img);
	cb3d->img = mlx_new_image(cb3d->mlx, WIDTH, HEIGHT);
	cb3d->win_data = mlx_get_data_addr(cb3d->img, &cb3d->bpp,
			&cb3d->size_line, &cb3d->endian);
	draw_cf(cb3d, 'f');
	draw_cf(cb3d, 'c');
	cast_rays(cb3d);
	mlx_put_image_to_window(cb3d->mlx, cb3d->win, cb3d->img, 0, 0);
}
