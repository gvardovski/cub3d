/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:06:32 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/05 16:44:09 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mapsize(t_cmap *map)
{
	int	i;

	i = 0;
	while (map)
	{
		map = map->next;
		i++;
	}
	return (i);
}

char	**map_to_arr(t_cmap *map)
{
	char	**gr;
	t_cmap	*temp;
	int		j;

	j = 0;
	temp = map;
	gr = malloc(sizeof(char *) * (maplast(map)->index + 2));
	while (temp)
	{
		gr[j] = ft_strdup(temp->str);
		j++;
		temp = temp->next;
	}
	gr[j] = NULL;
	return (gr);
}

int	check_path(char **gr, int y, int x, int rows)
{
	int	c;

	c = 0;
	gr[y][x] = '3';
	if (y < 0 || y >= rows || x < 0 || x >= ft_strlen(gr[y]))
		return (0);
	if (y + 1 < rows && x < ft_strlen(gr[y + 1])
		&& ft_strchr("0WSEN", gr[y + 1][x]))
		return (1);
	else if (y + 1 < rows && x < ft_strlen(gr[y + 1]) && gr[y + 1][x] == '1')
		c += check_path(gr, y + 1, x, rows);
	if (y - 1 >= 0 && x < ft_strlen(gr[y - 1])
		&& ft_strchr("0WSEN", gr[y - 1][x]))
		return (1);
	else if (y - 1 >= 0 && x < ft_strlen(gr[y - 1]) && gr[y - 1][x] == '1')
		c += check_path(gr, y - 1, x, rows);
	if (x + 1 < ft_strlen(gr[y]) && ft_strchr("0WSEN", gr[y][x + 1]))
		return (1);
	else if (x + 1 < ft_strlen(gr[y]) && gr[y][x + 1] == '1')
		c += check_path(gr, y, x + 1, rows);
	if (x - 1 >= 0 && ft_strchr("0WSEN", gr[y][x - 1]))
		return (1);
	else if (x - 1 >= 0 && gr[y][x - 1] == '1')
		c += check_path(gr, y, x - 1, rows);
	return (c);
}

int	validate_path(char **gridmap, t_cmlx *cb3d)
{
	int		y;
	int		x;
	int		rows;

	y = -1;
	rows = mapsize(cb3d->map);
	while (++y < rows)
	{
		x = -1;
		while (++x < (int)ft_strlen(gridmap[y]))
		{
			if (gridmap[y][x] == '1')
			{
				if (!check_path(gridmap, y, x, rows))
					return (0);
			}
		}
	}
	return (1);
}

void	check_wall_path(t_cmlx *cb3d)
{
	char	**gridmap;

	gridmap = map_to_arr(cb3d->map);
	if (!validate_path(gridmap, cb3d))
	{
		freegridmap(gridmap);
		error_printer("Map is not correct", cb3d);
	}
	freegridmap(gridmap);
}
