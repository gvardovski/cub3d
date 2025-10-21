/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 14:13:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/21 14:55:31 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_cmlx *cb3d)
{
	if ((int)cb3d->gridmap[(int)(cb3d->pl_y)][(int)(cb3d->pl_x + cb3d->dir_x * 0.15)] - 48 != 1)
		cb3d->pl_x += cb3d->dir_x * 0.15;
	if ((int)cb3d->gridmap[(int)(cb3d->pl_y + cb3d->dir_y * 0.15)][(int)(cb3d->pl_x)] - 48 != 1)
		cb3d->pl_y += cb3d->dir_y * 0.15;
}