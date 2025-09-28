/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:34:55 by svolkau           #+#    #+#             */
/*   Updated: 2025/01/12 15:04:00 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_puthex(int n)
{
	char	*b;
	long	num;

	b = "0123456789abcdef";
	num = (unsigned int)n;
	return (ft_putnumbase(b, num));
}
