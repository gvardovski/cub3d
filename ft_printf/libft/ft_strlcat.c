/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:53:18 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:53:18 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t n)
{
	size_t	ld;
	size_t	ls;
	size_t	i;
	size_t	j;

	ld = ft_strlen(dest);
	ls = ft_strlen(str);
	if (!n)
		return (ls + n);
	if (n < ld)
		ls += n;
	else
		ls += ld;
	i = ft_strlen(dest);
	j = 0;
	while (str[j] && i < n - 1)
		dest[i++] = str[j++];
	dest[i] = '\0';
	return (ls);
}

/* int	main(void)
{
    char dest[30];
	char * src = (char *)"AAAAAAAAA";

	memset(dest, 0, 30);
	dest[0] = 'B';
	if (ft_strlcat(dest, src, 0) == strlen(src) && !strcmp(dest, "B"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	dest[0] = 'B';
	if (ft_strlcat(dest, src, 1) == 10 && !strcmp(dest, "B"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 'B', 4);
	if (ft_strlcat(dest, src, 3) == 3 + strlen(src) && !strcmp(dest, "BBBB"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");	
	if (ft_strlcat(dest, src, 6) == 13 && !strcmp(dest, "BBBBA"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 'C', 5);
	if (ft_strlcat(dest, src, -1) == 14 && !strcmp(dest, "CCCCCAAAAAAAAA"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 'C', 15);
	if (ft_strlcat(dest, src, 17) == 24 && !strcmp(dest, "CCCCCCCCCCCCCCCA"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30);
	if (ft_strlcat(dest, src, 1) == strlen(src) && !strcmp(dest, ""))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30); 
	memset(dest, '1', 10);
	if (ft_strlcat(dest, src, 5) == strlen(src) + 5 
		&& !strcmp(dest, "1111111111"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");	
	memset(dest, 0, 30); 
	memset(dest, '1', 10);
	if (ft_strlcat(dest, src, 5) == strlen(src) + 5 
		&& !strcmp(dest, "1111111111"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30); 
	memset(dest, '1', 10);
	if (ft_strlcat(dest, "", 15) == 10 && !strcmp(dest, "1111111111"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30); 
	if (ft_strlcat(dest, "", 42) == 0 && !strcmp(dest, ""))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30);
	if (ft_strlcat(dest, "", 0) == 0 && !strcmp(dest, ""))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30);
	if (ft_strlcat(dest, "123", 1) == 3 && !strcmp(dest, ""))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30);
	if (ft_strlcat(dest, "123", 2) == 3 && !strcmp(dest, "1"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30);
	if (ft_strlcat(dest, "123", 3) == 3 && !strcmp(dest, "12"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30);
	if (ft_strlcat(dest, "123", 4) == 3 && !strcmp(dest, "123"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 0, 30);
	if (ft_strlcat(dest, "123", 0) == 3 && !strcmp(dest, ""))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
    return (0);
} */

/*
The strlcat() function appends the NUL-terminated string src to the end of dst. 
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.
Return Values
The strlcat() function return the total length of the string they tried to create
For strlcat() that means the initial length of dst plus the length of src. 
While this may seem somewhat confusing, it was done to make truncation detection 
simple.
Note, however, that if strlcat() traverses size characters without finding a NUL 
the length of the string is considered to be size and the destination string 
will not be NUL-terminated (since there was no space for the NUL). This keeps
strlcat() from running off the end of a string. In practice this should not 
happen (as it means that either size is incorrect or that dst is not a proper
''C'' string). The check exists to prevent potential security problems in 
incorrect code.
*/