/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:51:46 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:51:46 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chset(const char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int	st;
	int	fin;

	if (!s1)
		return (NULL);
	st = 0;
	while (ft_chset(s1[st], set) == 1)
		st++;
	fin = ft_strlen(s1) - 1;
	while (ft_chset(s1[fin], set) == 1)
		fin--;
	return (ft_substr(s1, st, fin - st + 1));
}

/* int main(void)
{
	char * s = ft_strtrim("   xxxtripouille", " x");

	if (!strcmp(s, "tripouille"))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strtrim("tripouille   xxx", " x");
	if (!strcmp(s, "tripouille"))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strtrim("   xxxtripouille   xxx", " x");
	if (!strcmp(s, "tripouille"))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strtrim("   xxx   xxx", " x");
	if (!strcmp(s, ""))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strtrim("", "123");
	if (!strcmp(s, ""))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strtrim("123", "");
	if (!strcmp(s, "123"))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strtrim("", "");
	if (!strcmp(s, ""))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strtrim("abcdba", "acb");
	if (!strcmp(s, "d"))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	return (0);
} */
