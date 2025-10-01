/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:57:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/01 13:49:54 by svolkau          ###   ########.fr       */
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

void freeall(t_cmlx *cb3d)
{
	freemap(&cb3d->map, del);
	free(cb3d->map);
	free(cb3d);
}

void error_printer(char *msg, t_cmlx *cb3d)
{
	printf("%s\n", msg);
	freeall(cb3d);
	exit(1);
}

void check_pos(t_cmlx *cb3d, t_cmap *priv, int pos, char *set, char *msg)
{
	if (!cb3d->map->str[pos - 1] || !ft_strchr(set, cb3d->map->str[pos - 1])
		|| !cb3d->map->str[pos + 1] || !ft_strchr(set, cb3d->map->str[pos + 1])
		|| !priv || !ft_strchr(set, priv->str[pos]) || !cb3d->map->next 
		|| !ft_strchr(set, cb3d->map->next->str[pos]))
		error_printer(msg, cb3d);
	
}

void	mapreader(int fd, t_cmlx *cb3d)
{
	char	*line_of_map;
	int		i;

	i = 0;
	line_of_map = get_next_line(fd);
	if (!line_of_map)
		error_printer("Map is empty", cb3d);
	if (line_of_map[0] == '\n')
	{
		free(line_of_map);
		error_printer("Not correct map, too many new lines", cb3d);
	}
	cb3d->map = mapnew(ft_strdup(line_of_map), i);
	while (cb3d->map)
	{
		free(line_of_map);
		line_of_map = get_next_line(fd);
		if (!line_of_map)
			break ;
		if (line_of_map[0] == '\n')
			error_printer("Not correct map, found somthing after map", cb3d);
		mapadd_back(&cb3d->map, mapnew(ft_strdup(line_of_map), ++i));
	}
}

void check_map_valid_char(t_cmlx *cb3d)
{
	int i;
	int c;
	int normalchar;
	t_cmap	*priv = NULL;

	c = 0;
	normalchar = 0;
	while(cb3d->map)
	{
		i = -1;
		while (cb3d->map->str[++i])
		{	
			if (!ft_strchr("EWNS10 \n", cb3d->map->str[i]))
				error_printer("Not correct character in map", cb3d);
			else if (ft_strchr("EWNS10", cb3d->map->str[i]))
				normalchar++;
			if (cb3d->map->str[i] == ' ')
				cb3d->map->str[i] = '2';
			if (cb3d->map->str[i] == '0')
				{check_pos(cb3d, priv, i, "10WESN", "Wall is open, or maybe floor is not correct");}
		/* 	if (map->str[i] == '1')
			{
				if ((!map->str[i - 1] || ft_strchr("2", map->str[i - 1]))
					&& (!map->str[i + 1] || ft_strchr(" \n\0", map->str[i + 1]))
					&& (!priv->str[i] || ft_strchr("2\n", priv->str[i]))
					&& (!map->next || !map->next->str[i] || ft_strchr(" \n\0", map->next->str[i])))
					error_printer("Wall is not correct", map);
			} */
			if (ft_strchr("EWNS", cb3d->map->str[i]))
			{
				if (++c != 1)
					error_printer("Too many players", cb3d);
				check_pos(cb3d, priv, i, "10", "Not correct player start position");
			}	
		}
		priv = cb3d->map;
		cb3d->map = cb3d->map->next;
	}
	if (!normalchar)
			error_printer("Map is empty", cb3d);
	if (c == 0)
			error_printer("No player start position", cb3d);
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

int main(int gc, char **gv)
{
	int fd;
	t_cmlx *cb3d; 
	//char **gridmap;

	if (gc != 2)
		exit(1);
	cb3d = malloc(sizeof(t_cmlx));
	cb3d->map = NULL;
	fd = open(gv[1], O_RDONLY);
	mapreader(fd, cb3d);
	close(fd);
	printmap(cb3d->map);
	//check_map_valid_char(cb3d);
	//gridmap = map_to_arr(cb3d->map);
	//check_path(gridmap);
	//printgridmap(gridmap);
	//freegridmap(gridmap);
	freeall(cb3d); 
}