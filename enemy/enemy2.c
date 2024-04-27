/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:53:02 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/27 14:35:19 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bombe_animation(t_data *ptr, int i, int j)
{
	char		*path;
	static int	c;

	int (n), (index);
	n = (25 / (ptr->player.item_eaten + 1));
	if (c % n == 0)
	{
		index = ptr->enemy2.img_indx;
		path = make_path(index, "./textures/player/enemy4/");
		if (index == 9)
			ptr->enemy2.img_indx = 0;
		else
			ptr->enemy2.img_indx++;
		ptr->enemy2.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, j * 50, i * 50);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->enemy2.img, j * 50, i * 50);
		free(path);
		mlx_destroy_image(ptr->mlx, ptr->enemy2.img);
	}
	c++;
}
