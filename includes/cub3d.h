/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:31:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/06 14:15:35 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define	CUB3D_H

# include "../get_next_line/get_next_line.h"
# include "../ft_printf/include/printf.h"
# include "../minilibx-linux/mlx.h"
# include <errno.h>
# include <math.h>

# define HEIGHT 768
# define WIDTH 1024

typedef enum e_type
{
	NO,
	SO,
	EA,
	WE
}					t_type;

typedef struct s_texture
{	
	enum e_type			type;
	int					width;
	int					height;
	char				*text_path;
}						t_texture;

typedef struct s_config
{
	struct s_texture	textures[4];
	int					floor_color;
	int					ceiling_color;
}						t_config;

typedef struct s_map
{
	char			*str;
	int				index;	
	struct s_map	*next;	
}					t_cmap;

typedef struct s_mlx
{
	int 			endian;
	int 			size_line;
	int 			bpp;
	int				playerx;
	int				playery;
	char 			orient;
	int				fd;
	char 			*win_data;
	void			*mlx;
	void			*win;
	void			*img;
	struct s_config *cng;
	struct s_map	*map;
}					t_cmlx;

void	freemap(t_cmap **map, void (*del)(char *));
void	del(char *str);
void	error_printer(char *msg, t_cmlx *cb3d);
void	printmap(t_cmap *map);
void	printgridmap(char **map);
void	freegridmap(char **grid);
char	**map_to_arr(t_cmap *map);
int		check_path(char **grid, int y, int x, int rows);
void	check_map_valid_char(t_cmlx *cb3d);
int		check_pos(t_cmap *map, t_cmap *priv, int pos, char *set);
t_cmap	*mapnew(char *str, int index);
void	mapadd_back(t_cmap **map, t_cmap *mapnew);
t_cmap	*maplast(t_cmap *map);
void	freemap(t_cmap **map, void (*del)(char *));
void	mapdelone(t_cmap *map, void (*del)(char *));
void	del(char *str);
void	check_wall_path(t_cmlx *cb3d);
void	freeall(t_cmlx *cb3d);
void	map_reader(t_cmlx *cb3d);

#endif
