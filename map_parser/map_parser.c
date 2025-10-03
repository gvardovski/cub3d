/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:57:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/03 21:13:43 by svolkau          ###   ########.fr       */
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

void	check_player_pos(t_cmlx *cb3d, t_cmap *head, t_cmap *priv, int pos)
{
	int c;

	c = 0;
	if (++c != 1)
		error_printer("Too many players", cb3d);
	else
	{
		cb3d->playerx = pos;
		cb3d->playery = head->index;
	}
	if (!check_pos(head, priv, pos, "10"))
		error_printer("Not correct player start position", cb3d);
}

void	check_map_valid_char(t_cmlx *cb3d)
{
	int i;
	t_cmap	*priv = NULL;
	t_cmap	*head = NULL;

	head = cb3d->map;
	while(head)
	{
		i = -1;
		while (head->str[++i])
		{	
			if (!ft_strchr("EWNS10", head->str[i]) && !ft_isspace(head->str[i]))
				error_printer("Not correct character in map", cb3d);
			if (head->str[i] == ' ')
				head->str[i] = '2';
			if (head->str[i] == '0' && !check_pos(head, priv, i, "EWNS10"))
				error_printer("Wall is open, or maybe floor is not correct", cb3d);
			if (ft_strchr("EWNS", head->str[i]))
				check_player_pos(cb3d, head, priv, i);
		}
		priv = head;
		head = head->next;
	}
	if (cb3d->playerx == 0 && cb3d->playery == 0)
		error_printer("No player start position", cb3d);
}

int empty_line(char *line)
{
	while (*line)
	{
		if(ft_isspace(*line))
			line++;
		else
			return(0);
	}
	return(1);
}

void	mapreader(t_cmlx *cb3d)
{
	char	*line_of_map = NULL;
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	line_of_map = get_next_line(cb3d->fd);
	if (!line_of_map)
		error_printer("Map is empty", cb3d);
	while (line_of_map)
	{
		if (empty_line(line_of_map) && i != -1)
			flag = 1;
		if (!empty_line(line_of_map) && flag == 0)
			mapadd_back(&cb3d->map, mapnew(ft_strdup(line_of_map), ++i));
		else if (!empty_line(line_of_map) && flag == 1)
		{
			free(line_of_map);
			error_printer("Not correct map, found something after map", cb3d); //1 byte error
		}
		free(line_of_map);
		line_of_map = get_next_line(cb3d->fd);
	}
	if (i == -1)
		error_printer("Map is empty", cb3d);
}

void init_main_struct(t_cmlx *cb3d, char **gv)
{
	cb3d->map = NULL;
	cb3d->playerx = 0;
	cb3d->playery = 0;
	cb3d->fd = open(gv[1], O_RDONLY);
}

int main(int gc, char **gv)
{
	t_cmlx *cb3d; 

	if (gc != 2)
		exit(1);
	cb3d = malloc(sizeof(t_cmlx));
	init_main_struct(cb3d, gv);
	mapreader(cb3d);
	check_map_valid_char(cb3d);
	//printmap(cb3d->map);
	mapcheckvalidpath(cb3d);
	freeall(cb3d);
	return(0);
}