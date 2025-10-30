/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 08:23:39 by mdziadko          #+#    #+#             */
/*   Updated: 2025/10/30 16:14:18 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int extract_rgb_val(char *val)
{
	char *trimmed;
	int num;

	trimmed = ft_strtrim(val, " ");
	if (!trimmed)
		return (printf("Error\nstrtrim\n"), -1);
	if (!ft_isnum(trimmed))
		return (printf("Error\nrgb is not a number\n"), free(trimmed), -1);
	num = ft_atoi(trimmed);
	free(trimmed);
	if (num < 0 || num > 255)
		return (printf("Error\nwrong rgb code\n"), -1);
	return (num);
}

int set_color(t_config *config, int dir, char *val)
{
	char **split;
	int rgb[3];
	int i;

	if (config->color[dir] != -1)
		return (printf("Error\nrepetitive element\n"), 1);
	split = ft_split(val, ',');
	if (!split)
		return (printf("Error\nsplit\n"), 1);
	i = 0;
	while (split[i])
	{
		if (i >= 3)
			return (printf("Error\nwrong rgb code\n"), free_arr(split), 1);
		rgb[i] = extract_rgb_val(split[i]);
		if (rgb[i] < 0)
			return (free_arr(split), 1);
		i++;
	}
	free_arr(split);
	if (i != 3)
		return (printf("Error\nwrong rgb code\n"), 1);
	config->color[dir] = create_trgb(0, rgb[0], rgb[1], rgb[2]);
	return (0);
}
