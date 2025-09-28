/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:54:16 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/19 18:35:10 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

/* int main(void)
{
	t_list *t = NULL;
	t_list *tmp;
	long long unsigned int i;

	i = 1;
	while (i < 5)
		ft_lstadd_back(&t, ft_lstnew((void *)i++));
	tmp = t;
	while (tmp)
	{
		printf("%p\n", tmp->content);
		tmp = tmp->next;
		free(t);
		t = tmp;
	}
	return (0);
} */