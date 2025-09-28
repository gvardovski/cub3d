/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:49:33 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:49:33 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)ptr)[i++] = (unsigned char)c;
	return (ptr);
}

/* int main(void)
{
    char tab[100];
	int i;

	memset(tab, 0, 100);
	ft_memset(tab, 'A', 0);
	if (tab[0] == 0)
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
	ft_memset(tab, 'A', 42);
	i = 0;
	while (tab[i] == 'A')
		i++;
	if (tab[i] == 0 && i == 42)
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
    return(0);
} */

/*
The C library memset() function of type void accepts three variable as parameters
that copies the character c (an unsigned char) to the first n characters of the
string pointed to, by the argument str.
This function is used to fill a contiguous block of memory with a specific value 
It also converts the value of a character to unsigned character and copies it 
into each of first n character of the object pointed by the given string. 
If the n is larger than string size, it will be undefined.
Parameters : 
str − This is a pointer to the block of memory to fill.
c − This is a second parameter of type integer and converts it to 
an unsigned char before using it to fill a block of memory.
n − This is the number of bytes to be set to the value.
Return Value :
This function returns a pointer to the memory area str.
*/