/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:53:38 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:53:38 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		while (*s)
			f(i++, (char *)s++);
	}
}

/* void iter (unsigned int i, char * s) 
{
	*s += i;
}

int main(void)
{
    char s[] = "";

    ft_striteri(s, iter);
	if (!strcmp(s, ""))
		printf("CHECK 1 OK\n");
	else
		printf("CHECK 1 KO\n");
	char s1[] = "0";
	ft_striteri(s1, iter);
	if (!strcmp(s1, "0"))
		printf("CHECK 2 OK\n");
	else
		printf("CHECK 2 KO\n");
	char s2[]= "0000000000";
	ft_striteri(s2, iter);
	if (!strcmp(s2, "0123456789"))
		printf("CHECK 3 OK\n");
	else
		printf("CHECK 3 KO\n");
    return(0);
} */