/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:22:20 by svolkau           #+#    #+#             */
/*   Updated: 2025/01/12 15:04:02 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_putnumbase(char *b, unsigned long n)
{
	int				count;
	unsigned long	lenb;

	lenb = ft_strlen(b);
	count = 0;
	if (n >= lenb)
		count += ft_putnumbase(b, n / lenb);
	ft_putchar(b[n % lenb]);
	count++;
	return (count);
}
