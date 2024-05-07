/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:20:37 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 07:19:23 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_right(t_data *ptr)
{
	char	*path;
	int		index;

	if (ptr->enemy.img_indx > 2)
		ptr->enemy.img_indx = 0;
	index = ptr->enemy.img_indx;
	path = make_path(index, \
	"./textures/player/enemy/right/");
	if (path)
	{
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		free(path);
		check_img(ptr, ptr->enemy.img);
		path = NULL;
	}
}

void	enemy_left(t_data *ptr)
{
	char	*path;
	int		index;

	if (ptr->enemy.img_indx > 2)
		ptr->enemy.img_indx = 0;
	index = ptr->enemy.img_indx;
	path = make_path(index, \
	"./textures/player/enemy/left/");
	if (path)
	{
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		free(path);
		check_img(ptr, ptr->enemy.img);
		path = NULL;
	}
}

void	ft_enemy_animation(t_data *ptr, int i, int j, char c)
{
	static int	n;

	if (ptr->player.item_eaten > ptr->num_item / 2)
	{
		if (c == 'N')
			enemy_right2(ptr);
		else
			enemy_left2(ptr);
	}
	else
	{
		if (c == 'N')
			enemy_right(ptr);
		else
			enemy_left(ptr);
	}
	if (n >= (ptr->enemy.speed * 20))
	{
		ptr->enemy.img_indx++;
		n = 0;
	}
	display_img(ptr, ptr->enemy.img, i, j);
	mlx_destroy_image(ptr->mlx, ptr->enemy.img);
	n++;
}

void	enemy_right2(t_data *ptr)
{
	char	*path;
	int		index;

	if (ptr->enemy.img_indx > 1)
		ptr->enemy.img_indx = 0;
	index = ptr->enemy.img_indx;
	path = make_path(index, \
	"./textures/player/enemy/angry/right/");
	if (path)
	{
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		free(path);
		check_img(ptr, ptr->enemy.img);
		path = NULL;
	}
}

void	enemy_left2(t_data *ptr)
{
	char	*path;
	int		index;

	if (ptr->enemy.img_indx > 1)
		ptr->enemy.img_indx = 0;
	index = ptr->enemy.img_indx;
	path = make_path(index, \
	"./textures/player/enemy/angry/left/");
	if (path)
	{
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		free(path);
		check_img(ptr, ptr->enemy.img);
		path = NULL;
	}
}
