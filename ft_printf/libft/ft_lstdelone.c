/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:13:52 by svolkau           #+#    #+#             */
/*   Updated: 2025/04/04 12:56:37 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

/* int main(void)
{
	t_list *first;

	first = ft_lstnew((void *)1);
	printf("%p\n", first->content);
	printf("%p\n", first->next);
	ft_lstdelone(first, &free);
	printf("%p\n", first->content);
	printf("%p\n", first->next);
	return (0);
} */