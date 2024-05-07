/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:53:02 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 09:10:14 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bombe_animation(t_data *ptr, int i, int j)
{
	char		*path;
	static int	c;
	int			index;

	index = ptr->enemy2.img_indx;
	if (index > 9)
		ptr->enemy2.img_indx = 0;
	if (ptr->size_x_map >= 40 || ptr->size_y_map >= 25)
		ptr->enemy2.speed = 5;
	if (c >= ptr->enemy2.speed)
	{
		if (index >= 9)
			ptr->enemy2.img_indx = 0;
		ptr->enemy2.img_indx++;
		c = 0;
	}
	path = make_path(index, "./textures/player/enemy4/");
	ptr->enemy2.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	if (path)
		free(path);
	check_img(ptr, ptr->enemy2.img);
	display_img(ptr, ptr->enemy2.img, i, j);
	mlx_destroy_image(ptr->mlx, ptr->enemy2.img);
	c++;
}
