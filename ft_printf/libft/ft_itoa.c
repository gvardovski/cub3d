/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:47:50 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:47:50 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		i++;
		nb = n * -1;
	}
	else
		nb = n;
	if (nb == 0)
		i = 1;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	nb;
	unsigned int	lt;

	lt = ft_intlen(n);
	ptr = (char *)malloc(sizeof(char) * (lt + 1));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		nb = n * -1;
		ptr[0] = '-';
	}
	else
		nb = n;
	if (nb == 0)
		ptr[0] = '0';
	while (nb > 0)
	{
		ptr[--lt] = (nb % 10) + '0';
		nb /= 10;
	}
	ptr[ft_intlen(n)] = '\0';
	return (ptr);
}

/* int	main(void)
{
    char *s = ft_itoa(2147483647);

	if (!strcmp(s, "2147483647"))
		printf("CHECK 1 OK\n");
	else
		printf("CHECK 1 KO\n");
	free(s);
	s = ft_itoa(-2147483648);
	if (!strcmp(s, "-2147483648"))
		printf("CHECK 2 OK\n");
	else
		printf("CHECK 2 KO\n");
	free(s);
	s = ft_itoa(0);
	if (!strcmp(s, "0"))
		printf("CHECK 3 OK\n");
	else
		printf("CHECK 3 KO\n");
	free(s);
	s = ft_itoa(1);
	if (!strcmp(s, "1"))
		printf("CHECK 4 OK\n");
	else
		printf("CHECK 4 KO\n");
	free(s);
	s = ft_itoa(-1);
	if (!strcmp(s, "-1"))
		printf("CHECK 5 OK\n");
	else
		printf("CHECK 5 KO\n");
	free(s);
	s = ft_itoa(42);
	if (!strcmp(s, "42"))
		printf("CHECK 6 OK\n");
	else
		printf("CHECK 6 KO\n");
	free(s);
    return (0);
} */
