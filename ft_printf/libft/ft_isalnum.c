/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:42:40 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:42:40 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ftisdigit(int param)
{
	return (param >= 48 && param <= 57);
}

static int	ftisalpha(int param)
{
	return ((param >= 65 && param <= 90) || (param >= 97 && param <= 122));
}

int	ft_isalnum(int param)
{
	return (ftisalpha(param) || ftisdigit(param));
}

/* int main(void)
{
   char c[9] = { 'a', 'a' - 1, 'z', 'z' + 1, '0', '0' - 1, '9', '9' + 1, 0};
	int i;

	i = 0;
	while (c[i])
	{
		if (ft_isalnum(c[i]))
			printf("Charecter %c if Alphanumeric\n", c[i]);
		else
			printf("Charecter %c if NOT Alphanumeric\n", c[i]);
		i++;
	}
	return (0);
} */

/*
The isalnum() function returns a non-zero value (equivalent to boolean true) 
if a character is alphanumeric, meaning an alphabet letter (a-z) or a number.
The isalnum() function is defined in the <ctype.h> header file.
Parameter Required. The ASCII value of a character or an actual character
Returns:	
An int value which is non-zero (equivalent to boolean true) if the character 
is alphanumeric.
Otherwise it returns 0 (equivalent to boolean false).
*/