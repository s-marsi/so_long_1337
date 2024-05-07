/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:18:02 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 07:23:22 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collectible_img(t_data *ptr)
{
	char	*path;

	int (x), (y), (index);
	if (ptr->item.img_indx > 5)
		ptr->item.img_indx = 0;
	index = ptr->item.img_indx;
	path = make_path(index, "./textures/collection/");
	if (path)
	{
		ptr->item.img = mlx_xpm_file_to_image(ptr->mlx, path, &x, &y);
		free(path);
		check_img(ptr, ptr->item.img);
		path = NULL;
	}
}

int	ft_collectible_animation(t_data *ptr, int x, int y)
{
	if (ptr->item.speed == 10)
	{
		ft_collectible_img(ptr);
		ptr->item.speed = 0;
		ptr->item.img_indx++;
	}
	ptr->item.speed++;
	display_img(ptr, ptr->item.img, x, y);
	return (0);
}
