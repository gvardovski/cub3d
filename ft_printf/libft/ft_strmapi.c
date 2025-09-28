/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:52:46 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:52:46 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr;

	ptr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!s || !ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/* char addOne(unsigned int i, char c)
{
	return (i + c);
}

int main(void)
{
    char *s;
	
	s = ft_strmapi("1234", addOne);

    if (!strcmp(s, "1357"))
		printf("CHECK 1 OK\n");
	else
		printf("CHECK 1 KO\n");
	free(s);
	s = ft_strmapi("", addOne);
	if (!strcmp(s, ""))
		printf("CHECK 2 OK\n");
	else
		printf("CHECK 2 KO\n");
	free(s);
	return(0);
} */
