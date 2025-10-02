/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:06:32 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/02 16:49:02 by svolkau          ###   ########.fr       */
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
	char	**grid;
	t_cmap	*temp;
	int		j;

	j = 0;
	temp = map;
	grid = malloc(sizeof(char *) * (maplast(map)->index + 2));
	while (temp)
	{
		grid[j] = ft_strdup(temp->str);
		j++;
		temp = temp->next;
	}
	grid[j] = NULL;
	return (grid);
}

void	check_path(char **grid, int y, int x)
{
	if (grid[y][x] == '1' || grid[y][x] == '2' )
		return ;
	grid[y][x] = '1';
	check_path(grid, y + 1, x);
	check_path(grid, y - 1, x);
	check_path(grid, y, x + 1);
	check_path(grid, y, x - 1);
}

int	validate_path(char **gridmap, t_cmlx *cb3d)
{
	int		y;
	int		x;

	y = -1;
	while (++y < mapsize(cb3d->map))
	{
		x = -1;
		while (++x < (int)ft_strlen(cb3d->map->str))
		{
			if (gridmap[y][x] != '1' && gridmap[y][x] != '2' && gridmap[y][x] != '\n' && gridmap[y][x] != '\0')
			{
				printf("Y = %d | X = %d | %c\n", y, x, gridmap[y][x]);
				return (0);
			}
		}
	}
	return (1);
}

void	mapcheckvalidpath(t_cmlx *cb3d)
{
	char	**gridmap;

	gridmap = map_to_arr(cb3d->map);
	check_path(gridmap, cb3d->playery, cb3d->playerx);
	printgridmap(gridmap);
	if (!validate_path(gridmap, cb3d))
	{
		freegridmap(gridmap);
		error_printer("Map is not valid", cb3d);
	}
	freegridmap(gridmap);
}