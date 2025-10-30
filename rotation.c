/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:13:56 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/30 16:13:57 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void turn_right(t_data *g)
{
	float old_dir_x;
	float o_x;

	old_dir_x = g->player.dir[X];
	g->player.dir[X] = g->player.dir[X] * cos(-0.027777778) - g->player.dir[Y] * sin(-0.027777778);
	g->player.dir[Y] = old_dir_x * sin(-0.027777778) + g->player.dir[Y] * cos(-0.027777778);
	o_x = g->player.plane[X];
	g->player.plane[X] = g->player.plane[X] * cos(-0.027777778) - g->player.plane[Y] * sin(-0.027777778);
	g->player.plane[Y] = o_x * sin(-0.027777778) + g->player.plane[Y] * cos(-0.027777778);
}

void turn_left(t_data *g)
{
	float old_dir_x;
	float o_x;

	old_dir_x = g->player.dir[X];
	g->player.dir[X] = g->player.dir[X] * cos(0.027777778) - g->player.dir[Y] * sin(0.027777778);
	g->player.dir[Y] = old_dir_x * sin(0.027777778) + g->player.dir[Y] * cos(0.027777778);
	o_x = g->player.plane[X];
	g->player.plane[X] = g->player.plane[X] * cos(0.027777778) - g->player.plane[Y] * sin(0.027777778);
	g->player.plane[Y] = o_x * sin(0.027777778) + g->player.plane[Y] * cos(0.027777778);
}
