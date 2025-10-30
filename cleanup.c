/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:13:06 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/30 16:13:07 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void del(char *str)
{
	if (str)
		free(str);
}

void free_map(t_map **map, void (*del)(char *))
{
	t_map *tmp;

	if (!map || !*map)
		return;
	while (map && *map)
	{
		tmp = (*map)->next;
		map_delone(*map, del);
		*map = tmp;
	}
	*map = NULL;
}

void free_arr(char **arr)
{
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void free_config(t_data *g)
{
	int dir;

	dir = 0;
	while (dir < 4)
	{
		if (g->mlx && g->c.tex[dir].img)
		{
			mlx_destroy_image(g->mlx, g->c.tex[dir].img);
			g->c.tex[dir].img = NULL;
		}
		if (g->c.tex_path[dir])
		{
			free(g->c.tex_path[dir]);
			g->c.tex_path[dir] = NULL;
		}
		dir++;
	}
}

void free_data(t_data *g)
{
	if (!g)
		return;
	if (g->file)
		free(g->file);
	free_config(g);
	free_map(&g->map, del);
	free_arr(g->mapa);
	if (g->mlx && g->img.img)
	{
		mlx_destroy_image(g->mlx, g->img.img);
		g->img.img = NULL;
	}
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
}
