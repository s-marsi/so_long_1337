/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:04:47 by smarsi            #+#    #+#             */
/*   Updated: 2024/02/28 21:46:35 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int content, int index)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	head->content = content;
	head->index = index;
	head->next = NULL;
	return (head);
}
