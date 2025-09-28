/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:53:54 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:53:54 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == 0)
		return ((char *)str);
	return (NULL);
}

/* int	main(void)
{	
	int i;
	char s[] = "tripouille";
	int c[5] = { 't', 'l', 'z', '0', 't' + 256};

	i = 0;
	while (c[i])
	{
   		printf("Result after finding character ( %c ) in string : %s\n",
		c[i], ft_strchr(s, c[i]));
		i++;
	}
    return (0);
} */

/*
The C Library strchr() function refer to first occurence of a character from 
a given string. 
This function operate the task of null characters(\0) or null-ended string. 
This function is useful in a variety of text processing tasks where user 
need to locate a particular character.
Parameters : 
str − This parameter represent a given string.
search_str − This parameter refers to specific character to be searched 
in a given string.
Return Value : 
This function returns a pointer to the first occurrence of the character i.e.
"search_str" in the string(str), or NULL if the character is not found.
*/