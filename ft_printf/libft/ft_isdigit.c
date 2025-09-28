/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:46:59 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:46:59 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int param)
{
	return (param >= 48 && param <= 57);
}

/* int main(void)
{
    char c[5] = { '0', '0' - 1, '9', '9' + 1, 0};
	int i;

	i = 0;
	while (c[i])
	{
		if (ft_isdigit(c[i]))
			printf("Charecter %c if Digit\n", c[i]);
		else
			printf("Charecter %c if NOT Digit\n", c[i]);
		i++;
	}
	return (0);
} */

/*
Function isdigit() takes a single argument in the form of an integer 
and returns the value of type int. Even though, isdigit() takes integer 
as an argument, character is passed to the function. Internally, the 
character is converted to its ASCII value for the check.
It is defined in <ctype.h> header file.
Return Value
Non-zero integer ( x > 0 )	Argument is a numeric character.
Zero (0)	Argument is not a numeric character.
*/