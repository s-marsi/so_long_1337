/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:57:17 by smarsi            #+#    #+#             */
/*   Updated: 2023/11/16 20:52:44 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1_dup;
	int		len;

	len = ft_strlen(s1);
	s1_dup = ft_calloc(len + 1, sizeof(char));
	if (!s1_dup)
		return (NULL);
	ft_strlcpy(s1_dup, s1, len + 1);
	return (s1_dup);
}
