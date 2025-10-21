/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:35:29 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/21 18:42:04 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	turn_left(t_cmlx *cb3d)
{
	float	old_dir_x;
	float	oldplane_x;

	old_dir_x = cb3d->dir_x;
	cb3d->dir_x = cb3d->dir_x * cos(-0.027777778) - cb3d->dir_y * sin(-0.027777778);
	cb3d->dir_y = old_dir_x * sin(-0.027777778) + cb3d->dir_y * cos(-0.027777778);
	oldplane_x = cb3d->plane_x;
	cb3d->plane_x = cb3d->plane_x * cos(-0.027777778) - cb3d->plane_y * sin(-0.027777778);
	cb3d->plane_y = oldplane_x * sin(-0.027777778) + cb3d->plane_y * cos(-0.027777778);

}

void	turn_right(t_cmlx *cb3d)
{
	float	old_dir_x;
	float	oldplane_x;

	old_dir_x = cb3d->dir_x;
	cb3d->dir_x = cb3d->dir_x * cos(0.027777778) - cb3d->dir_y * sin(0.027777778);
	cb3d->dir_y = old_dir_x * sin(0.027777778) + cb3d->dir_y * cos(0.027777778);
	oldplane_x = cb3d->plane_x;
	cb3d->plane_x = cb3d->plane_x * cos(0.027777778) - cb3d->plane_y * sin(0.027777778);
	cb3d->plane_y = oldplane_x * sin(0.027777778) + cb3d->plane_y * cos(0.027777778);

}
