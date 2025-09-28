/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:19:13 by svolkau           #+#    #+#             */
/*   Updated: 2025/01/10 19:22:50 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	ft_putchar(int c);
int	ft_putstr(const char *s);
int	ft_putptr(unsigned long p);
int	ft_putundec(unsigned int num);
int	ft_putdec(int n);
int	ft_putnumbase(char *b, unsigned long n);
int	ft_puthex(int n);
int	ft_puthexup(int n);
int	ft_puthexp(unsigned long n);
int	ft_printf(const char *s, ...);

#endif
