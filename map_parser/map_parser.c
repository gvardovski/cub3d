/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:57:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/09/29 20:05:14 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	del(char *str)
{
	if (str)
		free(str);
}

void	mapdelone(t_smap *map, void (*del)(char *))
{
	if (!del)
		return ;
	if (map)
	{
		(*del)(map->str);
		free(map);
	}
}

void	freemap(t_smap **map, void (*del)(char *))
{
	t_smap	*tmp;

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

t_smap	*maplast(t_smap *map)
{
	if (map == NULL)
		return (NULL);
	while (map->next != NULL)
		map = map->next;
	return (map);
}

void	mapadd_back(t_smap **map, t_smap *mapnew)
{
	t_smap	*last;

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

t_smap	*mapnew(char *str, int index)
{
	t_smap	*mapnew;

	mapnew = malloc(sizeof(t_smap));
	if (!mapnew)
		return (NULL);
	mapnew->str = str;
	mapnew->index = index;
	mapnew->next = NULL;
	return (mapnew);
}

void error_printer(char *msg, t_smap *map)
{
	printf("%s\n", msg);
	freemap(&map, del);
	free(map);
	exit(1);
}

void check_pos(t_smap *map, t_smap *priv, int pos, char *set, char *msg)
{
	if (!map->str[pos - 1] || !ft_strchr(set, map->str[pos - 1]) || !map->str[pos + 1] || !ft_strchr(set, map->str[pos + 1])
		|| !priv || !ft_strchr(set, priv->str[pos]) || !map->next || !ft_strchr(set, map->next->str[pos]))
		error_printer(msg, map);
	
}

t_smap	*mapreader(int fd, t_smap *map)
{
	char	*line_of_map;
	int		i;

	i = 0;
	line_of_map = get_next_line(fd);
	if (!line_of_map)
		error_printer("Map is empty", map);
	if (line_of_map[0] == '\n')
			error_printer("Not correct map, too many new lines", map);
	map = mapnew(ft_strdup(line_of_map), i);
	while (map)
	{
		free(line_of_map);
		line_of_map = get_next_line(fd);
		if (!line_of_map)
			break ;
		if (line_of_map[0] == '\n')
			error_printer("Not correct map, found somthing after map", map);
		mapadd_back(&map, mapnew(ft_strdup(line_of_map), ++i));
	}
	return(map);
}

void check_map_valid_char(t_smap *map)
{
	int i;
	int c;
	int normalchar;
	t_smap	*priv = NULL;

	c = 0;
	normalchar = 0;
	while(map)
	{
		i = -1;
		while (map->str[++i])
		{	
			if (!ft_strchr("EWNS10 \n", map->str[i]))
				error_printer("Not correct character in map", map);
			else if (ft_strchr("EWNS10", map->str[i]))
				normalchar++;
			if (map->str[i] == ' ')
				map->str[i] = '2';
			if (map->str[i] == '0')
				{check_pos(map, priv, i, "10WESN", "Wall is open, or maybe floor is not correct");}
			if (map->str[i] == '1')
			{
				if ((!map->str[i - 1] || ft_strchr("2", map->str[i - 1]))
					&& (!map->str[i + 1] || ft_strchr(" \n\0", map->str[i + 1]))
					&& (!priv->str[i] || ft_strchr("2\n", priv->str[i]))
					&& (!map->next || !map->next->str[i] || ft_strchr(" \n\0", map->next->str[i])))
					error_printer("Wall is not correct", map);
			}
			if (ft_strchr("EWNS", map->str[i]))
			{
				if (++c != 1)
					error_printer("Too many players", map);
				check_pos(map, priv, i, "10", "Not correct player start position");
			}	
		}
		priv = map;
		map = map->next;
	}
	if (!normalchar)
			error_printer("Map is empty", map);
	if (c == 0)
			error_printer("No player start position", map);
}

int main(int gc, char **gv)
{
	int fd;
	t_smap *map = NULL;
	t_smap *head = NULL;

	if (gc != 2)
		exit(1);
	fd = open(gv[1], O_RDONLY);
	map = mapreader(fd, map);
	close(fd);
	check_map_valid_char(map);
	head = map;
	while(head)
	{
		printf("%s", head->str);
		head = head->next;
	}
	freemap(&map, del);
	free(map);
}