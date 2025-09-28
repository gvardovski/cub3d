/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:46:15 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:46:15 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int param)
{
	return (param >= 0 && param <= 127);
}

/* int main(void)
{
    int c[5] = { -1, 0, 128, 127};
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_isascii(c[i]))
			printf("Charecter %d if Ascii\n", i);
		else
			printf("Charecter %d if NOT Ascii\n", i);
		i++;
	}
	return (0);
} */

/*
The isascii() function tests if a given character, in the current locale, 
can be represented as a valid 7–bit US-ASCII character.
The isascii() function returns nonzero if c, in the current locale, can be 
represented as a character in the 7–bit US-ASCII character set. Otherwise,
it returns 0.
*/