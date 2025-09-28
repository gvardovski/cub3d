/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:07:04 by svolkau           #+#    #+#             */
/*   Updated: 2025/01/12 15:04:03 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_putptr(unsigned long p)
{
	if (!p)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_puthexp(p));
}
