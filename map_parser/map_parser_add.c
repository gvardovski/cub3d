/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:01:28 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/12 19:58:51 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
