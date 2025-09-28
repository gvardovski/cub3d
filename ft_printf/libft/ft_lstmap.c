/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:27:02 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/25 16:27:02 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;

	list = ft_lstnew((*f)(lst->content));
	if (!list)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&list, new);
		lst = lst->next;
	}
	return (list);
}

/* void	*plus_ten(void *content)
{
	if (ft_isdigit((char *)content))
		content = (char *)content - 48;
}

int main(void)
{
	int *first = ft_lstnew((void *)1);
	long long unsigned int i = 2;

	while (i < 5)
		ft_lstadd_back(&first, (void *)i++);
	ft_lstmap(first, );
	return (0);
} */
