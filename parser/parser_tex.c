/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:07:15 by mdziadko          #+#    #+#             */
/*   Updated: 2025/10/22 16:44:49 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

bool	validate_format(char *file, char *format)
{
	char	*ext;

	if (!file || !file[0] || !format || !format[0])
		return (false);
	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, format, ft_strlen(format)) != 0
		|| ext[ft_strlen(format)] != '\0')
		return (false);
	return (true);
}

int	set_texture(t_config *config, int dir, char *val)
{
	char	*trimmed;
	int		fd;

	if (config->tex_path[dir])
		return (printf("Error\nRepetitive element\n"), 1);
	trimmed = ft_strtrim(val, " \t\r\n\v\f");
	if (!trimmed)
		return (printf("Error\nStrtrim\n"), 1);
	if (!validate_format(trimmed, ".xpm"))
		return (printf("Error\nWrong file format try .xpm\n"),
			free(trimmed), 1);
	fd = open(trimmed, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nOpen file texture\n"), free(trimmed), 1);
	close(fd);
	config->tex_path[dir] = ft_strdup(trimmed);
	free(trimmed);
	if (!config->tex_path[dir])
		return (printf("Error\nStrdup\n"), 1);
	return (0);
}
