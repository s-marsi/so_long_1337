/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:08:55 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 07:28:38 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_img(t_data *ptr, void *img)
{
	if (!img)
		ft_destroy_all(ptr, 3, 1);
}

void	count_item(t_data *ptr)
{
	char	**map;

	int (i), (j);
	map = ptr->map_str;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				ptr->num_item++;
			j++;
		}
		i++;
	}
}

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

void	display_img(t_data *ptr, void *img, int i, int j)
{
	if (!img)
		check_img(ptr, ptr->player.img);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, j * 50, i * 50);
	if (img)
		mlx_put_image_to_window(ptr->mlx, ptr->win, img, j * 50, i * 50);
}
