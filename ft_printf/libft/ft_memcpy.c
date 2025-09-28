/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:48:53 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:48:53 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	size_t	i;

	if (n == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)str)[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	int i;
    char dest[100];
	char src[] = { 0, 0};

	memset(dest, 'A', 100);
	ft_memcpy(dest, "Hello", 0);
	if (dest[0] == 'A')
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
	rtn = (char *)ft_memcpy(dest, NULL, 0);
	if (rtn == dest && dest[0] == 'A')
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
	ft_memcpy(dest, src, 2);
	i = 0;
	while(dest[i] == 0)
		i++;
	if (i == 2 && dest[2] == 'A')
		printf("CHECK : OK\n");
	else 
		printf("CHECK : NO\n");
} */

/*
The C library memcpy() function is also known as Copy Memory Block function
/ Memomy to Memory Copy.
It is used to specify the range of characters which could not exceed the size
of the source memory.
Parameters
dest_str − This parameter define a pointer to the destination array where 
the content is to be copied. It is type-casted to a pointer of type void*.
src_str − This parameter is used to define the source of data to be copied. 
It is then type-casted to a pointer of type void*.
n − This parameter refer to number of bytes to be copied.
Return Value :
This function returns a pointer to destination i.e. dest_str.
*/