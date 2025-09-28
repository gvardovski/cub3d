/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:51:35 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/18 16:45:45 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	fstrlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (0);
	if (fstrlen(s) < start)
		return (ft_strdup(""));
	if (fstrlen(s + start) < len)
		len = fstrlen(s + start);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* int	main(void)
{
	char * s = ft_substr("tripouille", 0, 42000);

	if (!strcmp(s, "tripouille"))
		printf("CHECK 1 OK\n");
	else
		printf("CHECK 1 KO\n");
	free(s);
	s = ft_substr("tripouille", 1, 1);
	if (!strcmp(s, "r"))
		printf("CHECK 2 OK\n");
	else
		printf("CHECK 2 KO\n");
	free(s);
	s = ft_substr("tripouille", 100, 1);
	if (!strcmp(s, ""))
		printf("CHECK 3 OK\n");
	else
		printf("CHECK 3 KO\n");
	free(s);
	char * str = strdup("1");
	s = ft_substr(str, 42, 42000000);
	if (!strcmp(s, ""))
		printf("CHECK 4 OK\n");
	else
		printf("CHECK 4 KO\n");
	free(s);
	str = strdup("0123456789");
	s = ft_substr(str, 9, 10);
	if (!strcmp(s, "9"))
		printf("CHECK 5 OK\n");
	else
		printf("CHECK 5 KO\n");
	free(s);
	s = ft_substr("42", 0, 0);
	if (!strcmp(s, ""))
		printf("CHECK 6 OK\n");
	else
		printf("CHECK 6 KO\n");
	free(s);
	s = ft_substr("BONJOUR LES HARICOTS !", 8, 14);
	if (!strcmp(s, "LES HARICOTS !"))
		printf("CHECK 7 OK\n");
	else
		printf("CHECK 7 KO\n");
	free(s);
	s = ft_substr("test", 1, 2);
	if (!strcmp(s, "es"))
		printf("CHECK 8 OK\n");
	else
		printf("CHECK 8 KO\n");
	free(s);
	return(0);
} */
