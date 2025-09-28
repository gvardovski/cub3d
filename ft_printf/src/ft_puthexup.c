/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:48:45 by svolkau           #+#    #+#             */
/*   Updated: 2025/01/12 15:04:01 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_puthexup(int n)
{
	char	*b;
	long	num;

	b = "0123456789ABCDEF";
	num = (unsigned int)n;
	return (ft_putnumbase(b, num));
}
