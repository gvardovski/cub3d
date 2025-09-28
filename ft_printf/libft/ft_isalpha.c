/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:43:11 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:43:11 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int param)
{
	return ((param >= 65 && param <= 90) || (param >= 97 && param <= 122));
}

/* int main(void)
{
    char c[9] = { 'a', 'a' - 1, 'z', 'z' + 1, 'A', 'A' - 1, 'Z', 'Z' + 1, 0};
	int i;

	i = 0;
	while (c[i])
	{
		if (ft_isalpha(c[i]))
			printf("Charecter %c if Alphabetic\n", c[i]);
		else
			printf("Charecter %c if NOT Alphabetic\n", c[i]);
		i++;
	}
	return (0);
}  */

/*
In C programming, isalpha() function checks whether a character is an alphabet
(a to z and A to Z) or not. If a character passed to isalpha() is an alphabet,
it returns a non-zero integer, if not it returns 0. he isalpha() function is 
defined in <ctype.h> header file.
Function isalpha() takes a single argument in the form of an integer and
returns an integer value. Even though, isalpha() takes integer as an argument,
character is passed to isalpha() function. Internally, the character is 
converted into the integer value corresponding to its ASCII value when passed.
isalpha() Return Value :
Zero (0)	If the parameter isn't an alphabet.
Non-zero number	If the parameter is an alphabet.
*/