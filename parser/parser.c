/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:25:45 by mdziadko          #+#    #+#             */
/*   Updated: 2025/10/22 16:49:48 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

int	parse_line(t_data *g, char *line)
{
	char	*trimmed;
	int		exit_code;

	trimmed = ft_strtrim(line, " ");
	if (!trimmed)
		return (printf("Error\nStrtrim\n"), 1);
	if (empty_line(trimmed))
		return (free(trimmed), -1);
	exit_code = 1;
	if (!ft_strncmp(trimmed, "NO ", 3))
		exit_code = set_texture(&g->c, NO, trimmed + 2);
	else if (!ft_strncmp(trimmed, "SO ", 3))
		exit_code = set_texture(&g->c, SO, trimmed + 2);
	else if (!ft_strncmp(trimmed, "WE ", 3))
		exit_code = set_texture(&g->c, WE, trimmed + 2);
	else if (!ft_strncmp(trimmed, "EA ", 3))
		exit_code = set_texture(&g->c, EA, trimmed + 2);
	else if (!ft_strncmp(trimmed, "C ", 2))
		exit_code = set_color(&g->c, CEILING, trimmed + 1);
	else if (!ft_strncmp(trimmed, "F ", 2))
		exit_code = set_color(&g->c, FLOOR, trimmed + 1);
	else
		exit_code = (printf("Error\nUnknown directive or no directive\n"), 1);
	free(trimmed);
	return (exit_code);
}

int	parse_config(t_data *g, int fd)
{
	char	*line;
	int		count;
	int		exit_code;

	count = 0;
	while (count < 6)
	{
		line = get_next_line(fd);
		if (!line)
			return (printf("Error\nIncomplete config\n"), 1);
		exit_code = parse_line(g, line);
		free(line);
		if (exit_code == -1)
			continue ;
		else if (exit_code == 1)
			return (1);
		count++;
	}
	return (0);
}

void	parse_map(t_data *g, int fd)
{
	map_reader(g, fd);
	check_map_valid_char(g);
	check_wall_path(g);
}

int	parse_file(t_data *g)
{
	int	fd;

	fd = open(g->file, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nOpen file\n"), free_data(g), 1);
	if (parse_config(g, fd))
		return (close(fd), free_data(g), 1);
	parse_map(g, fd);
	close(fd);
	return (0);
}
