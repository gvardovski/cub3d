/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:01:28 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/01 13:17:41 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void printmap(t_cmap *map)
{
	while(map)
	{
		printf("%s", map->str);
		map = map->next;
	}
	printf("\n");
}

void printgridmap(char **map)
{
	int i = -1, j;

	while(map[++i])
	{
		j = -1;
		while(map[i][++j])
			printf("%c", map[i][j]);
	}
	printf("\n");
}