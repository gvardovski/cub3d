/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcast_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:35:52 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/21 14:54:31 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render(int x, int y, t_cmlx *cb3d, int col)
{
	int	pix;

	pix = (y * cb3d->size_line) + (x * (cb3d->bpp / 8));
	cb3d->win_data[pix] = col & 0xFF;
	cb3d->win_data[pix + 1] = (col >> 8) & 0xFF;
	cb3d->win_data[pix + 2] = (col >> 16) & 0xFF;
}

void	get_delta_dist(t_cmlx *cb3d)
{
	if (cb3d->ray_dirx == 0)
		cb3d->delta_d_x = 1e30;
	else
		cb3d->delta_d_x = fabs(1 / cb3d->ray_dirx);
	if (cb3d->ray_diry == 0)
		cb3d->delta_d_y = 1e30;
	else
		cb3d->delta_d_y = fabs(1 / cb3d->ray_diry);
}

static int	get_texture(t_cmlx *cb3d)
{
	if (cb3d->side == 0)
	{
		if (cb3d->ray_dirx > 0)
			return (EA);
		else
			return (WE);
	}
	else
	{
		if (cb3d->ray_diry > 0)
			return (SO);
		else
			return (NO);
	}
}

static void	set_pos(t_cmlx *cb3d)
{
	double	wall_x;

	if (cb3d->side == 0)
		wall_x = cb3d->pl_y + cb3d->perp_wall_dist * cb3d->ray_diry;
	else
		wall_x = cb3d->pl_x + cb3d->perp_wall_dist * cb3d->ray_dirx;
	wall_x -= floor(wall_x);
	cb3d->tex_x = (int)(wall_x * (double)cb3d->cng->textures[NO].width);
	if (cb3d->side == 0 && cb3d->ray_dirx > 0)
		cb3d->tex_x = cb3d->cng->textures[NO].width - cb3d->tex_x - 1;
	if (cb3d->side == 1 && cb3d->ray_dirx < 0)
		cb3d->tex_x = cb3d->cng->textures[NO].width - cb3d->tex_x - 1;
}

void	draw_object(t_cmlx *cb3d)
{
	double	step;
	double	tex_pos;
	int		color;
	int		text;

	set_pos(cb3d);
	step = 1.0 * cb3d->cng->textures[NO].height / cb3d->line_height;
	tex_pos = (cb3d->draw_start - HEIGHT / 2 + cb3d->line_height / 2) * step;
	while (cb3d->draw_start < cb3d->draw_end)
	{
		cb3d->tex_y = (int)tex_pos & (cb3d->cng->textures[NO].height - 1);
		tex_pos += step;
		text = get_texture(cb3d);
		color = cb3d->cng->textures[text].color_arr[cb3d->cng->textures[text]
			.width * cb3d->tex_y + cb3d->tex_x];
		if (cb3d->side == 1)
			color = (color >> 1) & 8355711;
		render(cb3d->wall_x, cb3d->draw_start, cb3d, color);
		cb3d->draw_start += 1;
	}
	cb3d->wall_x += 1;
}
