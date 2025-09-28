/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:24:49 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/19 18:54:11 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
