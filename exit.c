/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:09:21 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/27 17:00:47 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_data *ptr, int i, int j)
{
	if (ptr->num_item == 0)
		ptr->exit.img = mlx_xpm_file_to_image(ptr->mlx, \
		"./textures/exit/0.xpm", &ptr->size_x, &ptr->size_y);
	else if (ptr->player.item_eaten == (ptr->num_item / 2))
		ptr->exit.img = mlx_xpm_file_to_image(ptr->mlx, \
		"./textures/exit/1.xpm", &ptr->size_x, &ptr->size_y);
	else if (ptr->player.item_eaten == ptr->num_item)
		ptr->exit.img = mlx_xpm_file_to_image(ptr->mlx, \
		"./textures/exit/2.xpm", &ptr->size_x, &ptr->size_y);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, j * 50, i * 50);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, j * 50, i * 50);
}

void	ft_exit_helper(t_data *ptr, int index)
{
	if (index == 120)
		ft_destroy_all(ptr, "YOU WIN :)", 1);
	else if (index == 20)
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, \
		"./textures/player/player_sprite/down/0.xpm"\
		, &ptr->size_x, &ptr->size_y);
	else if (index == 40)
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, \
		"./textures/player/player_sprite/up/4.xpm", &ptr->size_x, &ptr->size_y);
	else if (index == 60)
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, \
		"./textures/player/player_sprite/up/5.xpm", &ptr->size_x, &ptr->size_y);
	else if (index == 80)
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, \
		"./textures/player/player_sprite/up/6.xpm", &ptr->size_x, &ptr->size_y);
	else if (index == 100)
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, \
		"./textures/player/player_sprite/up/7.xpm", &ptr->size_x, &ptr->size_y);
}

void	ft_exit_animation(t_data *ptr, int x, int y)
{
	static int	index;

	ptr->finish = 1;
	ft_exit_helper(ptr, index);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, y * 50, x * 50);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, y * 50, x * 50);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->player.img, y * 50, x * 50);
	mlx_string_put(ptr->mlx, ptr->win, (ptr->size_x_map / 2) * 50, \
	(ptr->size_y_map / 2) * 50, 0x0000FF00, "YOU WIN");
	index++;
}
