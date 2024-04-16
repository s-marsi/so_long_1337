/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:25:47 by smarsi            #+#    #+#             */
/*   Updated: 2024/02/25 09:52:19 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	searche_value(int search, char const *set)
{
	while (*set)
	{
		if (*set == search)
			return (1);
		set++;
	}
	return (0);
}

static char	*start_trim(char const *s1, char const *set)
{
	while (searche_value(*s1, set))
		s1++;
	return ((char *) s1);
}

static int	end_trim(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1) - 1;
	while (len && searche_value(s1[len], set))
		len--;
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*return_str;
	int		i;

	if (!s1 || !set)
		return (NULL);
	if (!*s1)
		return (ft_strdup(""));
	str = start_trim(s1, set);
	if (*str == '\0')
		return (ft_strdup(""));
	i = end_trim(str, set);
	return_str = ft_calloc(i + 1, sizeof(char));
	if (!return_str)
		return (NULL);
	ft_strlcpy(return_str, str, i + 1);
	return (return_str);
}
