/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcaster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:55:37 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/09 20:10:04 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw(t_cmlx *cb3d)
{
	cb3d->line_height = (int)(HEIGHT / cb3d->perp_wall_dist);
	cb3d->draw_start = -cb3d->line_height / 2 + HEIGHT / 2;
	if (cb3d->draw_start < 0)
		cb3d->draw_start = 0;
	cb3d->draw_end = cb3d->line_height / 2 + HEIGHT / 2;
	if (cb3d->draw_end > HEIGHT)
		cb3d->draw_end = HEIGHT - 1;
	draw_object(cb3d);
}

void	distance(t_cmlx *cb3d)
{
	if (cb3d->side == 0)
		cb3d->perp_wall_dist = cb3d->side_dist_x - cb3d->delta_dist_x;
	else
		cb3d->perp_wall_dist = cb3d->side_dist_y - cb3d->delta_dist_y;
	draw(cb3d);
}

void	move_ray(t_cmlx *cb3d)
{
	while (cb3d->hit == 0)
	{
		if (cb3d->side_dist_x < cb3d->side_dist_y)
		{
			cb3d->side_dist_x += cb3d->delta_dist_x;
			cb3d->map_x += cb3d->step_x;
			cb3d->side = 0;
		}
		else
		{
			cb3d->side_dist_y += cb3d->delta_dist_y;
			cb3d->map_y += cb3d->step_y;
			cb3d->side = 1;
		}
		if ((int)cb3d->gridmap[cb3d->map_y][cb3d->map_x] - 48 == 1)
			cb3d->hit = 1;
	}
	distance(cb3d);
}

static void	set_ray(t_cmlx *cb3d)
{
	cb3d->map_x = (int)cb3d->playerx;
	cb3d->map_y = (int)cb3d->playery;
	cb3d->hit = 0;
	get_delta_dist(cb3d);
	if (cb3d->ray_dirx < 0)
	{
		cb3d->step_x = -1;
		cb3d->side_dist_x = (cb3d->playerx - cb3d->map_x) * cb3d->delta_dist_x;
	}
	else
	{
		cb3d->step_x = 1;
		cb3d->side_dist_x = (cb3d->map_x + 1.0 - cb3d->playerx) * cb3d->delta_dist_x;
	}
	if (cb3d->ray_diry < 0)
	{
		cb3d->step_y = -1;
		cb3d->side_dist_y = (cb3d->playery - cb3d->map_y) * cb3d->delta_dist_y;
	}
	else
	{
		cb3d->step_y = 1;
		cb3d->side_dist_y = (cb3d->map_y + 1.0 - cb3d->playery) * cb3d->delta_dist_y;
	}
	move_ray(cb3d);
}

void	cast_rays(t_cmlx *cb3d)
{
	int	x;

	x = -1;
	cb3d->tex_x = 0;
	cb3d->tex_y = 0;
	cb3d->wall_x = 0;
	while (++x < WIDTH)
	{
		cb3d->camera_x = 2 * x / (double)WIDTH - 1;
		cb3d->ray_dirx = cb3d->dir_x + cb3d->plane_x * cb3d->camera_x;
		cb3d->ray_diry = cb3d->dir_y + cb3d->plane_y * cb3d->camera_x;
		set_ray(cb3d);
	}
}