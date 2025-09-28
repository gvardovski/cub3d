/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:51:24 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:51:24 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int param)
{
	if (param >= 65 && param <= 90)
		param += 32;
	return (param);
}

/* int main(void)
{
    char c[5] = { 'A', 'A' - 1, 'Z', 'Z' + 1, 0};
	int i;

	i = 0;
	while (c[i])
	{
		printf("Input Charecter : %c | Output Charecter : %c\n",
		c[i], ft_tolower(c[i]));
		i++;
	}
	return (0);
} */

/*
tolower() function in C is used to convert the uppercase alphabet to the
lowercase alphabet. 
It does not affect characters other than uppercase characters. 
It is defined in the <ctype.h> header file in C.
It returns the ASCII value corresponding to the lowercase of the character
passed as the argument.
*/