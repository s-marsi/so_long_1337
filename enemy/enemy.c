/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:52:40 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/06 12:21:52 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	right_route_helper(t_data *ptr, int *i, int *j)
{
	if (ptr->map_str[*i][*j + 1] == '0')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, *j * 50, *i * 50);
		ptr->map_str[*i][*j] = '0';
		ptr->map_str[*i][*j + 1] = 'N';
		(*j)++;
	}
	else
		ptr->map_str[*i][*j] = 'n';
	if (ptr->player.item_eaten > (ptr->num_item / 2))
		ft_enemy_animation2(ptr, *i, *j, 'N');
	else
		ft_enemy_animation(ptr, *i, *j, 'N');
}

void	right_route(t_data *ptr, int *i, int *j)
{
	static int	c;
	int			n;

	n = (ptr->enemy.speed - ptr->player.item_eaten);
	if (n < 6)
		n = 6;
	if (c++ >= n)
	{
		if (ptr->map_str[*i][*j + 1] == 'P')
		{
			ptr->enemy.speed = 3;
			ptr->enemy2.speed = 3;
			ft_enemy_bombe(ptr, *i, *j);
		}
		(right_route_helper(ptr, i, j), c = 0);
	}
}

void	left_route_helper(t_data *ptr, int *i, int *j)
{
	if (ptr->map_str[*i][*j - 1] == '0')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, *j * 50, *i * 50);
		ptr->map_str[*i][*j] = '0';
		ptr->map_str[*i][*j - 1] = 'n';
		(*j)--;
	}
	else
		ptr->map_str[*i][*j] = 'N';
	if (ptr->player.item_eaten > (ptr->num_item / 2))
		ft_enemy_animation2(ptr, *i, *j, 'n');
	else
		ft_enemy_animation(ptr, *i, *j, 'n');
}

void	left_route(t_data *ptr, int *i, int *j)
{
	static int	c;
	int			n;

	c++;
	n = (ptr->enemy.speed - ptr->player.item_eaten);
	if (n < 6)
		n = 6;
	if (c >= n)
	{
		if (ptr->map_str[*i][*j - 1] == 'P')
		{
			ptr->enemy.speed = 3;
			ptr->enemy2.speed = 3;
			ft_enemy_bombe(ptr, *i, *j);
		}
		left_route_helper(ptr, i, j);
		c = 0;
	}
}
