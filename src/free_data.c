/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:41:04 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/13 14:51:49 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	del(char *str)
{
	if (str)
		free(str);
}

void	mapdelone(t_cmap *map, void (*del)(char *))
{
	if (!del)
		return ;
	if (map)
	{
		(*del)(map->str);
		free(map);
	}
}

void	freemap(t_cmap **map, void (*del)(char *))
{
	t_cmap	*tmp;

	if (!map || !*map)
		return ;
	while (map && *map)
	{
		tmp = (*map)->next;
		mapdelone(*map, del);
		*map = tmp;
	}
	*map = NULL;
}

void	freegridmap(char **grid)
{
	char	**temp;

	temp = grid;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(grid);
}

void	free_color_arr(t_texture *tex)
{
	if (tex[NO].color_arr)
		free(tex[NO].color_arr);
	if (tex[SO].color_arr)
		free(tex[SO].color_arr);
	if (tex[EA].color_arr)
		free(tex[EA].color_arr);
	if (tex[WE].color_arr)
		free(tex[WE].color_arr);
}

void	freeall(t_cmlx *cb3d)
{
	if (!cb3d)
		return ;
	if (cb3d->mlx)
		mlx_loop_end(cb3d->mlx);
	if (cb3d->mlx && cb3d->img)
		mlx_destroy_image(cb3d->mlx, cb3d->img);
	if (cb3d->mlx && cb3d->win)
		mlx_destroy_window(cb3d->mlx, cb3d->win);
	if (cb3d->mlx)
	{
		mlx_destroy_display(cb3d->mlx);
		free(cb3d->mlx);
	}
	if (cb3d->fd > 0)
		close(cb3d->fd);
	if (cb3d->cng)
	{
		free_color_arr(cb3d->cng->textures);
		free(cb3d->cng);
	}
	freemap(&cb3d->map, del);
	if (cb3d->gridmap)
		freegridmap(cb3d->gridmap);
	free(cb3d);
}
