/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:50:42 by svolkau           #+#    #+#             */
/*   Updated: 2025/03/18 12:30:12 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mfree(char **str, int n)
{
	while (n--)
		free(str[n]);
	return (1);
}

static int	ft_elemcount(const char *str, char c)
{
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (str[i])
	{
		if ((str[i + 1] == c || str[i + 1] == '\0')
			&& !(str[i] == c || str[i] == '\0'))
			e++;
		i++;
	}
	return (e);
}

static void	ft_melem(char *dest, const char *str, char c)
{
	int	i;

	i = 0;
	while (!(str[i] == c || str[i] == '\0'))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_msplit(char **ptr, const char *str, char c)
{
	int		i;
	int		j;
	int		e;

	e = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c || str[i] == '\0')
			i++;
		else
		{
			j = 0;
			while (!(str[i + j] == c || str[i + j] == '\0'))
				j++;
			ptr[e] = (char *)malloc(sizeof(char) * (j + 1));
			if (!ptr)
				return (ft_mfree(ptr, e - 1));
			ft_melem(ptr[e], str + i, c);
			i += j;
			e++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	int		nfw;
	char	**ptr;

	nfw = ft_elemcount(str, c);
	ptr = (char **)malloc(sizeof(char *) * (nfw + 1));
	if (!ptr)
		return (0);
	ptr[nfw] = 0;
	if (ft_msplit(ptr, str, c))
		return (0);
	return (ptr);
}

/* void freeTab(char **tab)
{
	int i;
	
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	main(void)
{
    char **tab = ft_split("  tripouille  42  ", ' ');
	
	if (!strcmp(tab[0], "tripouille"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (!strcmp(tab[1], "42"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	if (tab[2] == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	freeTab(tab);
	tab = ft_split("tripouille", 0);
	if (!strcmp(tab[0], "tripouille") && tab[1] == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	freeTab(tab);
	tab = ft_split("     ", ' ');
	if (tab[0] == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	freeTab(tab);
	tab = ft_split("chinimala", ' ');
	if (!strcmp(tab[0], "chinimala"))
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	freeTab(tab);
	tab = ft_split("", ' ');
	if (tab[0] == NULL)
		printf("CHECK OK\n");
	else
		printf("CHECK KO\n");
	freeTab(tab);
    return (0);
} */
