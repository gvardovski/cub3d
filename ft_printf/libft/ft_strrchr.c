/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:52:01 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/18 16:08:14 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*rez;

	rez = NULL;
	if (!c)
		return ((char *)str + ft_strlen(str));
	while (*str)
	{
		if (*str == (char)c)
			rez = ((char *)str);
		str++;
	}
	if (!rez)
		return (NULL);
	else
		return (rez);
}

/* int main(void)
{  
	int i;
	char s[] = "tripouille";
	char s2[] = "ltripouiel";
	char s3[] = "";
	int c[5] = { 't', 'l', 'z', '0', 't' + 256};

	i = 0;
	while (i < 5)
	{
   		printf("Result after finding last character ( %c ) in string : %s\n",
		c[i], ft_strrchr(s, c[i]));
		i++;
	}
	printf("Result after finding last character ( %c ) in string : %s\n",
	c[1], ft_strrchr(s2, c[1]));
	printf("Result after finding last character ( %c ) in string : %s\n",
	c[3], ft_strrchr(s3, c[3]));
	printf("\n");
    return (0);
} */

/*
The C library strrchr() function accepts two argument − searches for the 
last occurrence of the character c (an unsigned char) in the string pointed
to, by the argument str.
Here are some key point which highlights its importance −
This function is used to set for finding the last occurence of a specified
characters. The main operation is file path manipulation, parsing URL's and
handling the data formats. It saves the time and reduce error.
Parameters : 
str − This is the C string.
c − This is the character to be located. It is passed as its int promotion, 
but it is internally converted back to char.
Return : 
This function returns a pointer to the last occurrence of character in str. 
If the value is not found, the function returns a null pointer.
*/