/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:50:07 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/18 19:50:10 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/* int main(void)
{
	t_list *l;
	t_list *tmp;
	t_list *smp;
	long long unsigned int i;

	l = ft_lstnew((void *)'S');
	i = 5;
	while (i > 0)
		ft_lstadd_front(&l, ft_lstnew((void *)i--));
	smp = l; 
	tmp = ft_lstlast(l);
	printf("%p\n\n", tmp->content);
	while (smp)
	{
		printf("%p\n", smp->content);
		printf("%p\n", smp->next);
		smp = smp->next;
		free(l);
		l = smp;
	}
	return (0);
} */