/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_vpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:06:32 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/03 21:31:00 by svolkau          ###   ########.fr       */
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

int	check_path(char **grid, int y, int x, int rows)
{
    int c;

    c = 0;
	grid[y][x] = '3';
    if (y < 0 || y >= rows || x < 0 || x >= (int)ft_strlen(grid[y]))
        return 0;
    if (y + 1 < rows && x >= 0 && x < (int)ft_strlen(grid[y + 1])) {
        if (ft_strchr("0WSEN", grid[y + 1][x]))
            return 1;
        else if (grid[y + 1][x] == '1')
            c += check_path(grid, y + 1, x, rows);
    }
    if (y - 1 >= 0 && x >= 0 && x < (int)ft_strlen(grid[y - 1])) {
        if (ft_strchr("0WSEN", grid[y - 1][x]))
            return 1;
        else if (grid[y - 1][x] == '1')
            c += check_path(grid, y - 1, x, rows);
    }
    if (x + 1 < (int)ft_strlen(grid[y])) {
        if (ft_strchr("0WSEN", grid[y][x + 1]))
            return 1;
        else if (grid[y][x + 1] == '1')
            c += check_path(grid, y, x + 1, rows);
    }
    if (x - 1 >= 0) {
        if (ft_strchr("0WSEN", grid[y][x - 1]))
            return 1;
        else if (grid[y][x - 1] == '1')
            c += check_path(grid, y, x - 1, rows);
    }
    return c;
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

void	mapcheckvalidpath(t_cmlx *cb3d)
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