/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:53:10 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:53:10 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t n)
{
	size_t	c;
	size_t	i;

	c = 0;
	while (str[c])
		c++;
	if (!n)
		return (c);
	i = 0;
	while (str[i] && i < n -1)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (c);
}

/* int	main(void)
{
    char src[] = "helloo";
	char dest[10]; 
	
	memset(dest, 'A', 10);
	if (ft_strlcpy(dest, src, 0) == strlen(src) && dest[0] == 'A')
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_strlcpy(dest, src, 1) == strlen(src)
		 && dest[0] == 0 && dest[1] == 'A')
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'h' 
		&& dest[1] == 0  && dest[2] == 'A')
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");	
	if (ft_strlcpy(dest, src, -1) == strlen(src) && !strcmp(src, dest)
		&& dest[strlen(src) + 1] == 'A')
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 'A', 10);
	if (ft_strlcpy(dest, src, 6) == strlen(src) && !memcmp(src, dest, 5)
	&& dest[5] == 0)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 'A', 10);
	if (ft_strlcpy(dest, src, 7) == strlen(src) && !memcmp(src, dest, 7))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 'A', 10);
	if (ft_strlcpy(dest, src, 8) == strlen(src) && !memcmp(src, dest, 7))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	memset(dest, 'A', 10);
	if (ft_strlcpy(dest, "", 42) == 0 && !memcmp("", dest, 1))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");	
	memset(dest, 0, 10);
	if (ft_strlcpy(dest, "1", 0) == 1 && dest[0] == 0)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	return (0);	
} */

/*
Defined in string.h, the strlcpy() function copies up to -1 characters from the 
NUL-terminated string to .srcdst 
strlcpy() takes the full size of the buffer, not only the length, and terminates
the result with NUL as long as is greater than 0. Include a byte for the NUL in
your value.sizesize 
The strlcpy() function returns the total length of the string that would have 
been copied 
if there was unlimited space. This might or might not be equal to the length 
of the string actually copied, depending on whether there was enough space. 
This means that you can call strlcpy() once to find out how much space is 
required, then allocate it if you do not have enough, and finally call 
strlcpy() a second time to do the required copy.
The strlcpy() and strlcat() functions return the total length of the string 
they tried to create. For strlcpy() that means the length of src. 
*/