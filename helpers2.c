/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:08:55 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/27 15:26:49 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (str);
	str[0] = '\0';
	ft_strlcat(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, len);
	return (str);
}

int	check_access(char *path)
{
	if (access(path, R_OK) == -1)
	{
		free(path);
		ft_putstr_fd("Error : Image not found\n", 2);
		exit (1);
	}
	free(path);
	path = NULL;
	return (0);
}

char	*make_path(int nb, char *path)
{
	char	*all_path;
	char	*str;

	str = ft_itoa(nb);
	path = ft_strjoin2(path, str);
	free(str);
	all_path = ft_strjoin(path, ".xpm");
	return (all_path);
}