/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:00:14 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/25 15:00:14 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}

/* int main(void)
{
	t_list *first = ft_lstnew((void *)1);
	t_list *list = first;
	long long unsigned int i;

	i = 2;
	while (i < 5)
		ft_lstadd_back(&list, ft_lstnew((void *)i++));
	while (list)
	{
		printf("Pointer value : %p | Pointer position :
		%p \n", list->content, list->next);
		list = list->next;
	}
	ft_lstclear(&first, &free);
	while (first)
	{
		printf("Pointer value : %p | Pointer position :
		%p \n", first->content, first->next);
		first = first->next;
	}
	return (0);
}	 */