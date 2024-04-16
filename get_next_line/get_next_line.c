/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:52:23 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/31 14:43:48 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:52:20 by smarsi            #+#    #+#             */
/*   Updated: 2024/03/05 10:52:47 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*read_line(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src || src[i] == '\0')
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] && src[i] == '\n')
		i++;
	dst = malloc((i + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, src, i + 1);
	return (dst);
}

static char	*move_last(char *src)
{
	char	*left;
	int		i;
	int		len;

	i = 0;
	if (!src || !src[i])
		return (NULL);
	while (src[i] && src[i] != '\n')
		i++;
	if (!src[i])
		return (NULL);
	len = ((ft_strlen(src) - i) + 1);
	left = malloc(len * sizeof(char));
	if (!left)
		return (NULL);
	else
		ft_strlcpy(left, src + i + 1, len);
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*last;
	char		*return_line;
	char		*tmp_all;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmp_all = read_all(fd, last);
	return_line = read_line(tmp_all);
	last = move_last(tmp_all);
	free(tmp_all);
	return (return_line);
}
