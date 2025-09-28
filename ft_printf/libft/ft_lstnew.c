/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:23:05 by svolkau           #+#    #+#             */
/*   Updated: 2024/12/19 18:33:42 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}

/* int main(void)
{
	t_list *r;
	t_list *temp;

	r = ft_lstnew((void *)"");
	temp = r;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		printf("%p\n", temp->next);
		temp = temp->next;
		free(r);
		r = temp;
	}
	return(0); 
} */