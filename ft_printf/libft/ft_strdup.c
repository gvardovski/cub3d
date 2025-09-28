/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:53:46 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:53:46 by svolkau          ###   ########.fr       */
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

char	*ft_strdup(const char *str)
{
	char	*dstr;

	dstr = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dstr || !str)
		return (NULL);
	ft_strcpy(dstr, str);
	return (dstr);
}

/* int main(void)
{
	char * s = ft_strdup((char*)"helloo");

	if (!strcmp(s, "helloo"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	s = ft_strdup((char*)"");
	if (!strcmp(s, ""))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	return(0);
} */

/*
strdup() : 
Syntax : char *strdup(const char *s); 
This function returns a pointer to a null-terminated byte string, which
is a duplicate of the string pointed to by s. 
The memory obtained is done dynamically using malloc and hence it can 
be freed using free(). 
It returns a pointer to the duplicated string s.
*/