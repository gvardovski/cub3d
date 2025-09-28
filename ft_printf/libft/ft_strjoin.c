/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:53:28 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:53:28 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dstr, const char *str)
{
	while (*str)
		*dstr++ = *str++;
	*dstr = '\0';
	return (dstr);
}

static char	*ft_strcat(char *dstr, const char *str)
{
	while (*dstr)
		dstr++;
	while (*str)
		*dstr++ = *str++;
	*dstr = '\0';
	return (dstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !ptr)
		return (NULL);
	ft_strcpy(ptr, s1);
	ft_strcat(ptr, s2);
	return (ptr);
}

/* int main(void)
{
	char *s = ft_strjoin("tripouille", "42");

	if (!strcmp(s, "tripouille42"))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strjoin("", "42");
	if (!strcmp(s, "42"))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strjoin("42", "");
	if (!strcmp(s, "42"))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	s = ft_strjoin("", "");
	if (!strcmp(s, ""))
		printf("CHECH OK\n");
	else
		printf("CHECH KO\n");
	free(s);
	return (0);
} */
