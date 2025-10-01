/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:31:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/01 13:17:22 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define	CUB3D_H

# include "../get_next_line/get_next_line.h"
# include <errno.h>

typedef struct s_map
{
	char			*str;
	int				index;	
	struct s_map	*next;	
}					t_cmap;

typedef struct s_mlx
{
	int				playerx;
	int				playery;
	struct s_map	*map;
}					t_cmlx;

void	freemap(t_cmap **map, void (*del)(char *));
void	del(char *str);
void	error_printer(char *msg, t_cmlx *cb3d);
void	printmap(t_cmap *map);
void	printgridmap(char **map);
void	freegridmap(char **grid);

#endif
