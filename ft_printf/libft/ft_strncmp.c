/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:52:29 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:52:29 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*s1 - *s2);
}

/* int main(void)
{  
	int i;
	char *set[] = { "t", "1234", "1234", "1234" , "", "Tripouille", "Tripouille",
	"Tripouille", "Tripouille", "Tripouille", "Tripouille", "", "1", "", "1",
	""};
	char *set1[] = { "", "1235", "1235", "1235" , "", "Tripouille", "tripouille",
	"TriPouille", "TripouillE", "TripouilleX", "Tripouill", "1", "", "1", "",
	""};
	int set2[16] = { 0, 3, 4, -1, 42, 42, 42, 42, 42, 42, 42, 0, 0, 1, 1, 1};

	i = 0;
	while (set[i])
	{
		printf ("Compare ( %s ) with ( %s ) for ( %d ) charecters. Result | 
		%d\n", set[i], set1[i], set2[i], ft_strncmp( set[i], set1[i], set2[i]));
		i++;
	}
    return(0);
} */

/*
The strncmp() function compares the first n characters of two strings and 
returns an integer indicating which one is greater.
For this comparison characters at the same position from both strings are 
compared one by one, starting from the left until one of them does not match, 
n comparisons have been made or the end of a string has been reached.
There are four possible scenarios:
If n comparisons have been made without any mismatches then the function
returns zero.
If the end of both strings has been reached without any mismatches then
the function returns zero.
At the first mismatch, if the ASCII value of the character in the first
string is greater then the function returns a positive number.
At the first mismatch, if the ASCII value of the character in the second
string is greater then the function returns a negative number.
The strncmp() function is defined in the <string.h> header file.
Parameter Values :
str1	Required. One of the strings to be compared.
str2	Required. One of the strings to be compared.
n Required. A positive integer that limits the number of characters to be
compared.
Returns :	
An int value which is positive if the first string is greater, 
negative if the second string is greater and 0 if the two strings are equal.
*/