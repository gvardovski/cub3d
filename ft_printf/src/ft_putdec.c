/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:25:00 by svolkau           #+#    #+#             */
/*   Updated: 2025/01/12 15:03:58 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_putdec(int n)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (n < 0)
	{
		count++;
		num = n * -1;
		ft_putchar('-');
	}
	else
		num = n;
	return (count + ft_putundec(num));
}
