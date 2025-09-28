/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:49:17 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:49:17 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *str, size_t n)
{
	if (str < dest)
	{
		while (n--)
			*(char *)(dest + n) = *(char *)(str + n);
	}
	else
		ft_memcpy(dest, str, n);
	return (dest);
}

/* int	main(void)
{
    char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};
    
    if (ft_memmove(s0, s, 7) == s0 && !memcmp(s, s0, 7))
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
	if (ft_memmove(s, s + 2, 0) && !memcmp(s, sCpy, 7))
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
	if (ft_memmove(s, s + 2, 2) == s && !memcmp(s, sResult, 7))
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
	if (ft_memmove(sResult + 1, sResult, 2) == sResult + 1 
		&& !memcmp(sResult, sResult2, 7))
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");	
    return (0);
} */

/*
The C library memchr() function is used to copy a block memory from one 
location to another. Typically, this function state the count bytes of 
data from a source location to the destination.
Parameters
*dest_str − This is a pointer for destination array where the content 
is to be copied. 
It is type-casted to a pointer of type void*.
*src_str − The is a second pointer that denote the source of data to be copied 
It is also type-casted to a pointer of type void*.
numBytes − This parameter refer to number of bytes to be copied.
Return Value
This function returns a pointer to the destination i.e *dest_str.
*/