/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:40:47 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:40:47 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	while (n--)
		*(char *)str++ = 0;
}

/* int main(void)
{
	char tab[100];
	int i;

	memset(tab, 'A', 100);
	ft_bzero( tab, 0);
	if (tab[0] == 'A')
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
	ft_bzero( tab, 42);
	i = 0;
	while (tab[i] == 0)
		i++;
	if (tab[i] == 'A' && i == 42)
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
	memset( tab, 'A', 100);
	tab[0] = 0;
	ft_bzero( tab, 42);
	i = 0;
	while (tab[i] == 0)
		i++;
	if (i == 42)
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
	return (0);
} */

/*
The bzero() function erases the data in the n bytes of the memory
starting at the location pointed to by s, by writing zeros (bytes
containing '\0') to that area.
Returned value : 
bzero() returns no values.
There are no errno values defined for bzero().
*/