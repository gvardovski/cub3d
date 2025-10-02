/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:31:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/02 20:29:02 by svolkau          ###   ########.fr       */
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
	int				fd;
	struct s_map	*map;
}					t_cmlx;

void	freemap(t_cmap **map, void (*del)(char *));
void	del(char *str);
void	error_printer(char *msg, t_cmlx *cb3d);
void	printmap(t_cmap *map);
void	printgridmap(char **map);
void	freegridmap(char **grid);
char	**map_to_arr(t_cmap *map);
void	check_path(char **grid, int y, int x);
void	check_map_valid_char(t_cmlx *cb3d);
int		check_pos(t_cmap *map, t_cmap *priv, int pos, char *set);
t_cmap	*mapnew(char *str, int index);
void	mapadd_back(t_cmap **map, t_cmap *mapnew);
t_cmap	*maplast(t_cmap *map);
void	freemap(t_cmap **map, void (*del)(char *));
void	mapdelone(t_cmap *map, void (*del)(char *));
void	del(char *str);
void	mapcheckvalidpath(t_cmlx *cb3d);

#endif
