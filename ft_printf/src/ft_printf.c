/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:51:38 by svolkau           #+#    #+#             */
/*   Updated: 2025/01/12 15:02:58 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_findfmt(char f, va_list arg)
{
	if (f == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (f == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (f == 'p')
		return (ft_putptr((unsigned long)va_arg(arg, void *)));
	if (f == 'd' || f == 'i')
		return (ft_putdec(va_arg(arg, int)));
	if (f == 'u')
		return (ft_putundec(va_arg(arg, unsigned int)));
	if (f == 'x')
		return (ft_puthex(va_arg(arg, int)));
	if (f == 'X')
		return (ft_puthexup(va_arg(arg, int)));
	if (f == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *fr, ...)
{
	int		cbytes;
	va_list	ap;

	cbytes = 0;
	va_start(ap, fr);
	while (*fr)
	{
		if (*fr == '%')
			cbytes += ft_findfmt(*++fr, ap);
		else
			cbytes += ft_putchar(*fr);
		fr++;
	}
	va_end(ap);
	return (cbytes);
}
