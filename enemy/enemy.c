/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:52:40 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/02 08:29:44 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	right_route_helper(t_data *ptr, int *i, int *j)
{
	if (ptr->player.item_eaten > (ptr->num_item / 2))
		ft_enemy_animation2(ptr, *i, *j, 'N');
	else
		ft_enemy_animation(ptr, *i, *j, 'N');
}

void	right_route(t_data *ptr, int *i, int *j)
{
	static int	c;
	int			n;

	c++;
	n = (25 / (ptr->player.item_eaten + 1));
	if (n < 10)
		n = 10;
	if (c % n == 0)
	{
		if (ptr->map_str[*i][*j + 1] == 'P')
			ft_enemy_bombe(ptr, *i, *j);
		else if (ptr->map_str[*i][*j + 1] == '0')
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->img.img, *j * 50, *i * 50);
			ptr->map_str[*i][*j] = '0';
			ptr->map_str[*i][*j + 1] = 'N';
			(*j)++;
		}
		else
			ptr->map_str[*i][*j] = 'n';
		right_route_helper(ptr, i, j);
	}
}

void	left_route_helper(t_data *ptr, int *i, int *j)
{
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
	n = (25 / (ptr->player.item_eaten + 1));
	if (c % n == 0)
	{
		if (ptr->map_str[*i][*j - 1] == 'P')
			ft_enemy_bombe(ptr, *i, *j - 1);
		else if (ptr->map_str[*i][*j - 1] == '0')
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->img.img, *j * 50, *i * 50);
			ptr->map_str[*i][*j] = '0';
			ptr->map_str[*i][*j - 1] = 'n';
			(*j)--;
		}
		else
			ptr->map_str[*i][*j] = 'N';
		left_route_helper(ptr, i, j);
	}
}
