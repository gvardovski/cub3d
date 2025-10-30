/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <svolkau@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:13:31 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/30 16:13:32 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int main(int argc, char **argv)
{
	t_data g;

	if (argc != 2)
		return (printf("Error\nwrong number of arguments\n"), 1);
	if ((argv[1][0] == '.' && argv[1][1] == '.'))
		return (printf("Error\nrelative path\n"), 1);
	if (init_data(&g, argv[1]))
		return (1);
	render(&g);
	handle_events(&g);
	free_data(&g);
	return (0);
}
