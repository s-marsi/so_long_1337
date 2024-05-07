/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:52:40 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 09:13:58 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_no_enemy(t_data *ptr)
{
	char	c;

	int (i), (j);
	i = 0;
	while (ptr->map_str[i])
	{
		j = 0;
		while (ptr->map_str[i][j])
		{
			c = ptr->map_str[i][j];
			if (c == 'N' || c == 'n' || c == 'B')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	enemy_speed(t_data *ptr)
{
	int	n;

	n = 15;
	if (ptr->size_x_map >= 40 || ptr->size_y_map >= 25)
	{
		n = 4;
		if (ptr->player.item_eaten > ptr->num_item / 2)
			n = 2;
		return (n);
	}
	else if (ptr->player.item_eaten > ptr->num_item / 2)
		n = 4;
	else if (ptr->player.item_eaten > ptr->num_item / 3)
		n = 6;
	else if (ptr->player.item_eaten > ptr->num_item / 4)
		n = 9;
	return (n);
}

void	right_route(t_data *ptr, int *i, int *j)
{
	char	**map;

	map = ptr->map_str;
	if (map[*i][*j + 1] == '0' || map[*i][*j + 1] == 'P')
	{
		map[*i][*j] = '0';
		if (map[*i][*j + 1] == 'P')
		{
			if (ptr->finish)
				map[*i][*j] = 'n';
			else
				map[*i][*j + 1] = 'P';
			ft_enemy_bombe(ptr, *i, *j);
		}
		else
			map[*i][*j + 1] = 'N';
		(*j)++;
	}
	else
		map[*i][*j] = 'n';
}

void	left_route(t_data *ptr, int *i, int *j)
{
	char	**map;

	map = ptr->map_str;
	if (map[*i][*j - 1] == '0' || map[*i][*j - 1] == 'P')
	{
		map[*i][*j] = '0';
		if (map[*i][*j - 1] == 'P')
		{
			if (ptr->finish)
				map[*i][*j] = 'N';
			else
				map[*i][*j - 1] = 'P';
			ft_enemy_bombe(ptr, *i, *j);
		}
		else
			map[*i][*j - 1] = 'n';
	}
	else
		map[*i][*j] = 'N';
}
