/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:02:05 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 07:22:47 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	right_animation(t_data *ptr, int index)
{
	char	*path;

	if (index == 4)
	{
		ptr->player.img_indx = 0;
		index = 0;
	}
	path = make_path(index, \
	"./textures/player/player_sprite/idle/right_down/");
	if (path)
	{
		ptr->player.img_indx++;
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		if (path)
			free(path);
		check_img(ptr, ptr->player.img);
	}
	ptr->player.speed = 0;
	ptr->player.speed++;
}

static void	left_animation(t_data *ptr, int index)
{
	char	*path;

	if (index == 4)
	{
		ptr->player.img_indx = 0;
		index = 0;
	}
	path = make_path(index, \
	"./textures/player/player_sprite/idle/left/");
	if (path)
	{
		ptr->player.img_indx++;
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		if (path)
			free(path);
		check_img(ptr, ptr->player.img);
	}
	ptr->player.speed = 0;
	ptr->player.speed++;
}

static void	up_animation(t_data *ptr, int index)
{
	char	*path;

	if (index == 4)
	{
		ptr->player.img_indx = 0;
		index = 0;
	}
	path = make_path(index, \
	"./textures/player/player_sprite/idle/up/");
	if (path)
	{
		ptr->player.img_indx++;
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		if (path)
			free(path);
		check_img(ptr, ptr->player.img);
	}
	ptr->player.speed = 0;
	ptr->player.speed++;
}

void	ft_player_animation(t_data *ptr, int i, int j, int flag)
{
	int			index;

	(void) flag;
	if (ptr->player.speed == 13)
	{
		index = ptr->player.img_indx;
		if (ptr->player.animation == 0)
			right_animation(ptr, index);
		else if (ptr->player.animation <= 2)
			left_animation(ptr, index);
		else if (ptr->player.animation == 3)
			up_animation(ptr, index);
		if (!ptr->player.img)
			ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, \
			"./textures/player/player_sprite/idle/right_down/0.xpm", \
			&ptr->size_x, &ptr->size_y);
		ptr->player.speed = 0;
	}
	ptr->player.speed++;
	display_img(ptr, ptr->player.img, i, j);
}
