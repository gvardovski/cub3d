/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:52:13 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:52:13 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	char	*p1;
	char	*p2;

	if (!*str2)
		return ((char *)str1);
	while (n-- && *str1)
	{
		if (*str1 == *str2)
		{
			i = n;
			p1 = (char *)str1 + 1;
			p2 = (char *)str2 + 1;
			while (i-- && *p1 && *p2 && *p2 == *p1)
			{
				p1++;
				p2++;
			}
			if (!(*p2))
				return ((char *)str1);
		}
		str1++;
	}
	return (NULL);
}

/* int	main(void)
{
    char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char * empty = (char*)"";

	printf("Result String of (haystack, needle, 0) : %s\n",
	ft_strnstr(haystack, needle, 0));
	printf("Result String of (haystack, needle, -1) : %s\n",
	ft_strnstr(haystack, needle, -1));
	printf("Result String of (haystack, a, -1) : %s\n",
	ft_strnstr(haystack, "a", -1));
	printf("Result String of (haystack, c, -1) : %s\n",
	ft_strnstr(haystack, "c", -1));
	printf("Result String of (empty, , -1) : %s\n", ft_strnstr(empty, "", -1));
	printf("Result String of (empty, , 0) : %s\n", ft_strnstr(empty, "", 0));
	printf("Result String of (empty, hello, -1) : %s\n",
	ft_strnstr(empty, "hello", -1));
	printf("Result String of (haystack, aaabc, 5) : %s\n",
	ft_strnstr(haystack, "aaabc", 5));
	printf("Result String of (empty, 12345, 5) : %s\n",
	ft_strnstr(empty, "12345", 5));
	printf("Result String of (haystack, abcd, 9) : %s\n",
	ft_strnstr(haystack, "abcd", 9));
	printf("Result String of (haystack, cd, 8) : %s\n",
	ft_strnstr(haystack, "cd", 8));
	printf("Result String of (haystack, a, 1) : %s\n",
	ft_strnstr(haystack, "a", 1));
	printf("Result String of (1, a, 1) : %s\n", ft_strnstr("1", "a", 1));
	printf("Result String of (22, b, 2) : %s\n", ft_strnstr("22", "b", 2));
    return (0);
} */

/*
The strnstr function locates the first occurrence of the null-terminated 
string \c little in the string \c big, where not more than \c len characters
are searched. Characters that appear after a \0 character are not searched.
Since the strnstr function is a FreeBSD specific API, it should only be used
when portability is not a concern.
Return Values
If little is an empty string, big is returned;
if little occurs nowhere in big, NULL is returned; 
otherwise a pointer to the first character of the first occurrence of little
is returned.
*/