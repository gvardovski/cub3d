/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:26:48 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/12 20:11:22 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	color(int rgb[3])
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	get_size(t_cmlx *cb3d, int fd, int texture)
{
	char	*line;
	char	**splited;

	line = get_next_line(fd);
	line[ft_strlen(line) - 1] = '\0';
	splited = NULL;
	if (line)
	{
		splited = ft_split(line, ' ');
		cb3d->cng->textures[texture].width = ft_atoi(splited[0]);
		cb3d->cng->textures[texture].height = ft_atoi(splited[1]);
	}
	freegridmap(splited);
	free(line);
}

void	valid_texture(int fd, int width, int height)
{
	int		count;
	char	*line;

	line = get_next_line(fd);
	free(line);
	count = 0;
	line = get_next_line(fd);
	while (line && line[0] != '\n')
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (count != height * width * 3)
	{
		close(fd);
		error_printer("Not valid texture", NULL);
	}
	close(fd);
}

int	*init_text_arr(int fd, int width, int height)
{
	int		i;
	int		j;
	int		rgb[3];
	int		*rez;
	char	*line;

	rez = malloc(sizeof(int) * height * width);
	i = -1;
	while (++i < height * width)
	{
		j = -1;
		while (++j < 3)
		{
			line = get_next_line(fd);
			if (line && line[0] != '\n')
				rgb[j] = ft_atoi(line);
			free(line);
		}
		rez[i] = color(rgb);
	}
	return (rez);
}

void	add_color_arr(t_cmlx *cb3d, int text)
{
	int		fd;
	int		i;
	char	*line;

	cb3d->cng->textures[text].type = text;
	fd = open(cb3d->cng->textures[text].text_path, O_RDONLY);
	line = get_next_line(fd);
	free(line);
	get_size(cb3d, fd, text);
	valid_texture(fd, cb3d->cng->textures[text].width,
		cb3d->cng->textures[text].height);
	fd = open(cb3d->cng->textures[text].text_path, O_RDONLY);
	i = -1;
	while (++i < 3)
	{
		line = get_next_line(fd);
		free(line);
	}
	cb3d->cng->textures[text].color_arr = init_text_arr(fd,
			cb3d->cng->textures[text].width, cb3d->cng->textures[text].height);
	close(fd);
}
