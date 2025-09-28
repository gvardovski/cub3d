/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:48:06 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:48:06 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	while (n--)
	{
		if (*(char *)str == (char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

/* int main(void)
{
    char s[] = {0, 1, 2 ,3 ,4 ,5};
	
	printf ("Result of memchr : %s\n", (char *)ft_memchr(s, 0, 0));
	printf ("Result of memchr : %s\n", (char *)ft_memchr(s, 0, 1));
	printf ("Result of memchr : %s\n", (char *)ft_memchr(s, 2, 3));
	printf ("Result of memchr : %s\n", (char *)ft_memchr(s, 6, 6));
	printf ("Result of memchr : %s\n", (char *)ft_memchr(s, 2 + 256, 3));
    return (0);
} */

/*
The C library memchr() function of type void accepts three agruments 
that searches for the first occurrence of the character c (an unsigned char)
in the first n bytes of the string pointed to, by the argument str.
Parameters :
str − This is the pointer to the memory block where the search is performed.
c − This is the value to be passed as an int, but the function performs 
a byte per byte search using the unsigned char conversion of this value.
n − This is the number of bytes to be analyzed.
Return Value :
This function returns a pointer to the matching byte or
NULL if the character does not occur in the given memory area.
*/