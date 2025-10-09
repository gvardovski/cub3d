/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:01:28 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/09 19:57:07 by svolkau          ###   ########.fr       */
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

t_cmap	*maplast(t_cmap *map)
{
	if (map == NULL)
		return (NULL);
	while (map->next != NULL)
		map = map->next;
	return (map);
}

void	mapadd_back(t_cmap **map, t_cmap *mapnew)
{
	t_cmap	*last;

	if (!mapnew)
		return ;
	if (*map)
	{
		last = maplast(*map);
		last->next = mapnew;
	}
	else
		*map = mapnew;
}

t_cmap	*mapnew(char *str, int index)
{
	t_cmap	*mapnew;

	mapnew = malloc(sizeof(t_cmap));
	if (!mapnew)
		return (NULL);
	mapnew->str = str;
	mapnew->index = index;
	mapnew->next = NULL;
	return (mapnew);
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

void	printmap(t_cmap *map)
{
	while (map)
	{
		printf("%s", map->str);
		map = map->next;
	}
	printf("\n");
}

void	printgridmap(char **map)
{
	int	j;
	int	i;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			printf("%c", map[i][j]);
		printf("\n");
	}
}
