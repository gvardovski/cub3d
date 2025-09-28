/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:41:45 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:41:45 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	i;

	if (n != 0 && (n * size) / n != size)
		return (NULL);
	ptr = (void *)malloc(size * n);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (ptr);
	i = 0;
	while (i < (n * size))
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}

/* int main(void)
{
	void *ptr = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	if (!memcmp(ptr, e, 4))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	free(ptr);
	if (ft_calloc(4294967295, 4294967295) == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_calloc(2147483647, 2147483647) == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_calloc(-2147483648, -2147483648) == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	ptr = ft_calloc(0, 0);
	if (ptr != NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	free(ptr);
	ptr = ft_calloc(0, 5);
	if (ptr != NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	free(ptr);
	ptr = ft_calloc(5, 0);
	if (ptr != NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	free(ptr);
	if (ft_calloc(-5, -5) == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	ptr = ft_calloc(0, -5);
	if (ptr != NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	free(ptr);
	ptr = ft_calloc(-5, 0);
	if (ptr != NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	free(ptr);
	if (ft_calloc(3, -5) == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_calloc(-5, 3) == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	return (0);
} */

/*
The calloc() function in C is used to allocate a specified amount 
of memory and then initialize it to zero. The function returns a
void pointer to this memory location, which can then be cast to the desired type.
The function takes in two parameters that collectively specify the amount of
memory ​​to be allocated.
*/