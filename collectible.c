/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:18:02 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/27 12:06:18 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collectible_img(t_data *ptr)
{
	char	*path;
	int		*x;
	int		*y;

	path = NULL;
	if (ptr->item.img_indx <= 25)
		path = ft_strjoin2("./textures/collection/", "0.xpm");
	else if (ptr->item.img_indx <= 50)
		path = ft_strjoin2("./textures/collection/", "1.xpm");
	else if (ptr->item.img_indx <= 75)
		path = ft_strjoin2("./textures/collection/", "2.xpm");
	else if (ptr->item.img_indx <= 100)
		path = ft_strjoin2("./textures/collection/", "3.xpm");
	else if (ptr->item.img_indx <= 125)
		path = ft_strjoin2("./textures/collection/", "4.xpm");
	else if (ptr->item.img_indx <= 150)
	{
		path = ft_strjoin2("./textures/collection/", "5.xpm");
		ptr->item.img_indx = 0;
	}
	x = &ptr->size_x;
	y = &ptr->size_y;
	ptr->item.img = mlx_xpm_file_to_image(ptr->mlx, path, x, y);
	free(path);
	path = NULL;
}
