/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:51:00 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:51:00 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int param)
{
	if (param >= 97 && param <= 122)
		param -= 32;
	return (param);
}

/* int	main(void)
{
    char c[5] = { 'a', 'a' - 1, 'z', 'z' + 1, 0};
	int i;

	i = 0;
	while (c[i])
	{
		printf("Input Charecter : %c | Output Charecter : %c\n",
		c[i], ft_toupper(c[i]));
		i++;
	}
	return (0);
}  */

/*
The toupper() function is used to convert lowercase alphabet to uppercase.
If the character passed is a lowercase alphabet then the toupper() function
converts a lowercase alphabet to an uppercase alphabet. 
It is defined in the ctype.h header file.
Returns: This function returns the uppercase character.
*/