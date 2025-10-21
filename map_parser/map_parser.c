/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:57:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/15 10:58:28 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_pos(t_cmap *map, t_cmap *priv, int pos, char *set)
{
	if (!map->str[pos - 1] || !ft_strchr(set, map->str[pos - 1])
		|| !map->str[pos + 1] || !ft_strchr(set, map->str[pos + 1])
		|| !priv || !ft_strchr(set, priv->str[pos])
		|| !map->next || !map->next->str[pos]
		|| !ft_strchr(set, map->next->str[pos]))
		return (0);
	return (1);
}

void	check_player_pos(t_cmlx *cb3d, t_cmap *head, t_cmap *priv, int pos)
{
	int	c;

	c = 0;
	if (++c != 1)
		error_printer("Too many players", cb3d);
	else
	{
		cb3d->orient = head->str[pos];
		cb3d->pl_x = pos;
		cb3d->pl_y = head->index;
	}
	if (!check_pos(head, priv, pos, "10"))
		error_printer("Not correct player start position", cb3d);
}

void	check_map_valid_char(t_cmlx *cb3d)
{
	int		i;
	t_cmap	*priv;
	t_cmap	*head;

	priv = NULL;
	head = cb3d->map;
	while (head)
	{
		i = -1;
		while (head->str[++i])
		{
			if (!ft_strchr("EWNS10", head->str[i]) && !ft_isspace(head->str[i]))
				error_printer("Not correct character in map", cb3d);
			/* if (head->str[i] == ' ')
				head->str[i] = '2'; */
			if (head->str[i] == '0' && !check_pos(head, priv, i, "EWNS10"))
				error_printer("Wall or floor is not correct", cb3d);
			if (ft_strchr("EWNS", head->str[i]))
				check_player_pos(cb3d, head, priv, i);
		}
		priv = head;
		head = head->next;
	}
	if (cb3d->pl_x == 0 && cb3d->pl_y == 0)
		error_printer("No player start position", cb3d);
}

int	empty_line(char *line)
{
	while (*line)
	{
		if (ft_isspace(*line))
			line++;
		else
			return (0);
	}
	return (1);
}

void	map_reader(t_cmlx *cb3d)
{
	char	*line_of_map;
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
			error_printer("Not correct map, something after map", cb3d);
		}
		free(line_of_map);
		line_of_map = get_next_line(cb3d->fd);
	}
	if (i == -1)
		error_printer("Map is empty", cb3d);
}
