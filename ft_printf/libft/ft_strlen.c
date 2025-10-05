/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 20:32:13 by svolkau           #+#    #+#             */
/*   Updated: 2025/10/05 16:19:16 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
			i++;
	}
	return (i);
}

/* int main(void)
{
	char *c[2] = { "123", ""};
	int i;

	i = 0;
	while (c[i])
	{
		printf("Lenght of the string ( %s ) is : %lld\n", c[i], ft_strlen(c[i]));
		i++;
	}
	return (0);
} */

/*
The strlen() function in C calculates the length of a given string. 
The strlen() function is defined in string.h header file. It doesn’t 
count the null character \0.
This function returns the integral length of the string passed.
*/