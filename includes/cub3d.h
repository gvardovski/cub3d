/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:31:12 by svolkau           #+#    #+#             */
/*   Updated: 2025/09/28 18:32:21 by svolkau          ###   ########.fr       */
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
}					t_smap;

void	freemap(t_smap **map, void (*del)(char *));
void	del(char *str);
void	error_printer(char *msg, t_smap *map);

#endif
