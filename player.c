/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:02:05 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/01 06:21:41 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	right_animation(t_data *ptr, int index)
{
	char	*path;

	path = make_path(index, \
	"./textures/player/player_sprite/idle/right_down/");
	if (index == 3)
		ptr->player.img_indx = 0;
	else
		ptr->player.img_indx++;
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	free(path);
}

static void	left_animation(t_data *ptr, int index)
{
	char	*path;

	path = make_path(index, \
	"./textures/player/player_sprite/idle/left/");
	if (index == 3)
		ptr->player.img_indx = 0;
	else
		ptr->player.img_indx++;
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	free(path);
}

static void	up_animation(t_data *ptr, int index)
{
	char	*path;

	path = make_path(index, \
	"./textures/player/player_sprite/idle/up/");
	if (index == 3)
		ptr->player.img_indx = 0;
	else
		ptr->player.img_indx++;
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	free(path);
}

void	ft_player_animation(t_data *ptr, int i, int j)
{
	static int	c;
	int			index;

	index = ptr->player.img_indx;
	if (c % 10 == 0)
	{
		if (ptr->player.animation == 0)
			right_animation(ptr, index);
		else if (ptr->player.animation <= 2)
			left_animation(ptr, index);
		else if (ptr->player.animation == 3)
			up_animation(ptr, index);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, j * 50, i * 50);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->player.img, j * 50, i * 50);
	}
	c++;
}
