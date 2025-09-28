/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:13:15 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/08 22:13:15 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	n;
	int	r;

	i = 0;
	n = 0;
	r = 0;
	while (*s == ' ' || *s == '\t' || *s == '\f'
		|| *s == '\v' || *s == '\n' || *s == '\r')
		s++;
	if (*s == '-')
		n = 1;
	if (*s == '-' || s[i] == '+')
		s++;
	while (*s >= 48 && *s <= 57)
	{
		r = (r * 10) + (*s - 48);
		s++;
	}
	if (n == 1)
		r *= -1;
	return (r);
}

/* int main(void)
{
	if (ft_atoi("1") == 1)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("a1") == 0)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("--1") == 0)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");	
	if (ft_atoi("++1") == 0)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("+1") == 1)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("-1") == -1)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("0") == 0)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("+42lyon") == 42)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");	
	if (ft_atoi("+101") == 101)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("2147483647") == 2147483647)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("-2147483648") == -2147483648)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("-+42") == 0)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (ft_atoi("+-42") == 0)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
    return (0);
} */

/*
The C stdlib library atoi() function is used to convert a numeric string into an 
integer value.
Return Value :
This function returns an integral number, represents int value. 
If the input string is not a valid string's number, it returns 0.
*/