/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:01:41 by smarsi            #+#    #+#             */
/*   Updated: 2024/02/28 21:55:43 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, int (*f)(int), void (*del)(int))
{
	t_stack	*head;
	t_stack	*new;

	head = NULL;
	if (!lst)
		return (NULL);
	if (f && del)
	{
		while (lst)
		{
			new = ft_lstnew(f(lst->content), 0);
			if (!new)
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, new);
			lst = lst->next;
		}
	}
	return (head);
}
