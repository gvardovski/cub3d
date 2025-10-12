/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:58:17 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/12 20:04:09 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	printmap(t_cmap *map)
{
	while (map)
	{
		printf("%s", map->str);
		map = map->next;
	}
	printf("\n");
}

void	printgridmap(char **map)
{
	int	j;
	int	i;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			printf("%c", map[i][j]);
		printf("\n");
	}
}

void	printcolorarr(t_texture tex)
{
	int	i;

	i = -1;
	while (++i < (tex.width * tex.height))
		printf("index: %d, color: %d\n", i, tex.color_arr[i]);
}

void	error_printer(char *msg, t_cmlx *cb3d)
{
	printf("%s\n", msg);
	freeall(cb3d);
	exit(1);
}
