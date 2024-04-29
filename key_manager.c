/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:30:12 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/29 11:15:06 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_enemy(t_data *ptr, int x, int y)
{
	if (ptr->map_str[y][x] == 'N' || ptr->map_str[y][x] == 'n')
		return (1);
	if (ptr->map_str[y][x] == 'B')
		return (2);
	return (0);
}

static int	can_move(t_data *ptr, int x, int y)
{
	int	items;
	int	eaten_items;

	items = ptr->num_item;
	eaten_items = ptr->player.item_eaten;
	if (!ptr->map_str[y][x] || ptr->map_str[y][x] == '1'
	|| (ptr->map_str[y][x] == 'E' && items != eaten_items))
		return (0);
	if (ptr->finish || ptr->bomb)
		return (0);
	return (1);
}

static void	new_image(t_data *ptr, int keycode)
{
	int	x;
	int	y;

	x = ptr->player.pos_x;
	y = ptr->player.pos_y;
	if (keycode == 0 && can_move(ptr, x - 1, y))
		move_left(ptr, x, y, is_enemy(ptr, x - 1, y));
	else if (keycode == 2 && can_move(ptr, x + 1, y))
		move_right(ptr, x, y, is_enemy(ptr, x + 1, y));
	else if (keycode == 13 && can_move(ptr, x, y - 1))
		move_up(ptr, x, y, is_enemy(ptr, x, y - 1));
	else if (keycode == 1 && can_move(ptr, x, y + 1))
		move_down(ptr, x, y, is_enemy(ptr, x, y + 1));
}

int	press_key(int keycode, t_data *ptr)
{
	if (keycode == 53)
		ft_destroy_all(ptr, NULL, 1);
	else if (keycode == 17)
		ft_destroy_all(ptr, NULL, 1);
	else if (keycode == 0 || keycode == 2
		|| keycode == 13 || keycode == 1)
		new_image(ptr, keycode);
	return (0);
}
