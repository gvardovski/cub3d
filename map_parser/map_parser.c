/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:57:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/02 21:01:12 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\f'
		|| c == '\r' || c == '\v' || c == '\n')
		return (1);
	return (0);
}

void freeall(t_cmlx *cb3d)
{
	if (cb3d->fd > 0)
		close(cb3d->fd);
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

int	check_pos(t_cmap *map, t_cmap *priv, int pos, char *set)
{
	if (!map->str[pos - 1] || !ft_strchr(set, map->str[pos - 1])
		|| !map->str[pos + 1] || !ft_strchr(set, map->str[pos + 1])
		|| !priv || !ft_strchr(set, priv->str[pos]) 
		|| !map->next || !map->next->str[pos] || !ft_strchr(set, map->next->str[pos]))
		return (0);
	return(1);
}

void	check_map_valid_char(t_cmlx *cb3d)
{
	int i;
	int c;
	int normalchar;
	t_cmap	*priv = NULL;
	t_cmap	*head = NULL;

	c = 0;
	normalchar = 0;
	head = cb3d->map;
	while(head)
	{
		i = -1;
		while (head->str[++i])
		{	
			if (!ft_strchr("EWNS10 \t\n", head->str[i]))
				error_printer("Not correct character in map", cb3d);
			else if (ft_strchr("EWNS10", head->str[i]))
				normalchar++;
			if (head->str[i] == ' ')
				head->str[i] = '2';
			if (head->str[i] == '0')
			{
				if (!check_pos(head, priv, i, "EWNS10"))
					error_printer("Wall is open, or maybe floor is not correct", cb3d);
			}
		/* 	if (map->str[i] == '1')
			{
				if ((!map->str[i - 1] || ft_strchr("2", map->str[i - 1]))
					&& (!map->str[i + 1] || ft_strchr(" \n\0", map->str[i + 1]))
					&& (!priv->str[i] || ft_strchr("2\n", priv->str[i]))
					&& (!map->next || !map->next->str[i] || ft_strchr(" \n\0", map->next->str[i])))
					error_printer("Wall is not correct", map);
			} */
			if (ft_strchr("EWNS", head->str[i]))
			{
				if (++c != 1)
					error_printer("Too many players", cb3d);
				else
					{
						cb3d->playerx = i;
						cb3d->playery = head->index;
					}
				if (!check_pos(head, priv, i, "10"))
					error_printer("Not correct player start position", cb3d);;
			}	
		}
		priv = head;
		head = head->next;
	}
	if (!normalchar)
			error_printer("Map is empty", cb3d);
	if (c == 0)
			error_printer("No player start position", cb3d);
}

void check_new_line(char *line, char *msg, t_cmlx *cb3d, int fd)
{
	if (line[0] == '\n')
	{
		close(fd);
		free(line);
		error_printer(msg, cb3d);
	}
}

int empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if(ft_isspace(line[i]))
			i++;
		else
			return(0);
	}
	return(1);
}

/* void	mapreader(int fd, t_cmlx *cb3d)
{
	char	*line_of_map = NULL;
	int		i;

	i = 0;
	line_of_map = get_next_line(fd);
	if (!line_of_map)
	{
		close(fd);
		error_printer("Map is empty", cb3d);
	}
	while (line_of_map && empty_line(line_of_map))
	{
		free(line_of_map);
		line_of_map = get_next_line(fd);
	}
	if (line_of_map)
		cb3d->map = mapnew(ft_strdup(line_of_map), i);
	else
	{
		close(fd);
		error_printer("Map is empty", cb3d);
	}
	while (cb3d->map)
	{
		free(line_of_map);
		line_of_map = get_next_line(fd);
		if (!line_of_map || empty_line(line_of_map))
			break ;
		mapadd_back(&cb3d->map, mapnew(ft_strdup(line_of_map), ++i));
	}
	while (line_of_map && empty_line(line_of_map))
	{
		free(line_of_map);
		line_of_map = get_next_line(fd);
	}
	if (line_of_map && !empty_line(line_of_map))
	{
		free(line_of_map);
		error_printer("Not correct map, found something after map", cb3d);
	}
	else
		free(line_of_map);
} */

void	mapreader(t_cmlx *cb3d)
{
	char	*line_of_map = NULL;
	int		i;

	i = -1;
	line_of_map = get_next_line(cb3d->fd);
	if (!line_of_map)
		error_printer("Map is empty", cb3d);
	while (line_of_map)
	{
		if (!empty_line(line_of_map))
			mapadd_back(&cb3d->map, mapnew(ft_strdup(line_of_map), ++i));
		free(line_of_map);
		line_of_map = get_next_line(cb3d->fd);
	}
	if (i == -1)
		error_printer("Map is empty", cb3d);
}

int main(int gc, char **gv)
{
	t_cmlx *cb3d; 

	if (gc != 2)
		exit(1);
	cb3d = malloc(sizeof(t_cmlx));
	cb3d->map = NULL;
	cb3d ->fd = open(gv[1], O_RDONLY);
	mapreader(cb3d);
	//check_map_valid_char(cb3d);
	printmap(cb3d->map);
	freeall(cb3d);
	return(0);
}