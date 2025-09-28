/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:47:18 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:47:18 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int param)
{
	return (param >= 32 && param <= 126);
}

/* int main(void)
{
   	char c[5] = { ' ', ' ' - 1, '~', '~' + 1, 0};
	int i;

	i = 0;
	while (c[i])
	{
		if (ft_isprint(c[i]))
			printf("Charecter %c if Printable\n", c[i]);
		else
			printf("Charecter %c if NOT Printable\n", c[i]);
		i++;
	}
	return (0);
} */

/*
Function isprint() takes a single argument in the form of an integer
and returns a value of type int. Even though, isprint() takes integer 
as an argument, character is passed to the function. 
Internally, the character is converted to its ASCII value for the check.
If a character passed to isprint() is a printable character, it returns 
non-zero integer, if not it returns 0.
It is defined in <ctype.h> header file.
*/