/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:57:08 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/02 11:16:18 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    game_over_two_(t_data *ptr, int x, int y)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, (y) * 50, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, (y + 1) * 50, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, (y + 2) * 50, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, (y + 3) * 50, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, (y + 5) * 50, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, (y + 6) * 50, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, (y + 7) * 50, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, (y + 8) * 50, x);
}

void    game_over(t_data *ptr, int x, int y)
{
    game_over_two_(ptr, x, y);
    call_img(ptr, "./textures/lose/1/", 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y) * 50, x);
	call_img(ptr, "./textures/lose/1/", 1);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 1) * 50, x);
	call_img(ptr, "./textures/lose/1/", 2);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 2) * 50, x);
	call_img(ptr, "./textures/lose/1/", 3);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 3) * 50, x);
	call_img(ptr, "./textures/lose/1/", 4);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 5) * 50, x);
	call_img(ptr, "./textures/lose/1/", 5);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 6) * 50, x);
	call_img(ptr, "./textures/lose/1/", 6);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 7) * 50, x);
	call_img(ptr, "./textures/lose/1/", 7);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 8) * 50, x);
}

void    game_over_two(t_data *ptr, int x, int y)
{
    game_over_two_(ptr, x, y);
    call_img(ptr, "./textures/lose/2/", 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y) * 50, x);
	call_img(ptr, "./textures/lose/2/", 1);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 1) * 50, x);
	call_img(ptr, "./textures/lose/2/", 2);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 2) * 50, x);
	call_img(ptr, "./textures/lose/2/", 3);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 3) * 50, x);
	call_img(ptr, "./textures/lose/2/", 4);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 5) * 50, x);
	call_img(ptr, "./textures/lose/2/", 5);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 6) * 50, x);
	call_img(ptr, "./textures/lose/2/", 6);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 7) * 50, x);
	call_img(ptr, "./textures/lose/2/", 7);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 8) * 50, x);
}