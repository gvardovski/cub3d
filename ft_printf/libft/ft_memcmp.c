/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:48:27 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:48:27 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*(unsigned char *)s1 == *(unsigned char *)s2 && --n)
	{
		s1++;
		s2++;
	}
	return ((int)(*(unsigned char *)s1 - *(unsigned char *)s2));
}

/* int	main(void)
{
    char s[] = {-128, 0, 127, 0};
	char sCpy[] = {-128, 0, 127, 0};
	char s2[] = {0, 0, 127, 0};
	char s3[] = {0, 0, 42, 0};
    
    printf("Result of memcmp : %d\n", ft_memcmp(s, sCpy, 4));
	printf("Result of memcmp : %d\n", ft_memcmp(s, s2, 0));
	printf("Result of memcmp : %d\n", ft_memcmp(s, s2, 1));
	printf("Result of memcmp : %d\n", ft_memcmp(s2, s, 1));
	printf("Result of memcmp : %d\n", ft_memcmp(s2, s3, 4));
    return (0);
} */

/*
The C library memcmp() function can be used to compare two blocks of memory. 
In general, it is used to compare the binary data or raw data.
Here, memcmp() accepts three variable as parameters that compares the first 
n bytes of memory area str1 and memory area str2.
Parameters
str1 − This is the pointer to a block of memory.
str2 − This parameter define a pointer to the block of memory.
n − This parameter define the number of bytes to be compared.
Return Value
If the return value < 0, it indicates str1 is less than str2.
If the return value > 0, it indicates str2 is less than str1.
If the return value == 0, it represents str1 is equivalent to the str2.
*/