/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:25:06 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/19 18:59:57 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/* int main(void)
{
	t_list *l;
	t_list *tmp;
	long long unsigned int i;

	l = ft_lstnew((void *)'S');
	i = 5;
	while (i > 0)
		ft_lstadd_front(&l, ft_lstnew((void *)i--));
	tmp = l;
	printf("%d\n", ft_lstsize(l));
	while (l)
	{
		printf("%p\n", tmp->content);
		printf("%p\n", tmp->next);
		tmp = tmp->next;
		free(l);
		l = tmp;
	}
	return (0);
} */