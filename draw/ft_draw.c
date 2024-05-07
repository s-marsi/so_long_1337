/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:03:25 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 07:31:30 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	enemy_img(t_data *ptr)
{
	int (i), (j);
	i = 0;
	if (ptr->enemy.speed >= enemy_speed(ptr))
	{
		while (ptr->map_str[i])
		{
			j = 0;
			while (ptr->map_str[i][j])
			{
				if (ptr->map_str[i][j] == 'N')
					right_route(ptr, &i, &j);
				else if (ptr->map_str[i][j] == 'n')
					left_route(ptr, &i, &j);
				j++;
			}
			i++;
		}
		ptr->enemy.speed = 0;
	}
	ptr->enemy.speed++;
}

static void	ft_draw_helper(t_data *ptr, int i, int j)
{
	char	c;

	c = ptr->map_str[i][j];
	if (c == 'B' || c == 'n' || c == 'N')
		enemy_draw(ptr, i, j);
	else if (c == 'R')
	{
		attack_enemy(ptr, i, j);
		display_img(ptr, ptr->enemy2.img, i, j);
	}
	else if (c == 'P')
		player_draw(ptr, i, j);
	else if (c == 'E')
		exit_draw(ptr, i, j);
	else if (c == 'C')
		collection_draw(ptr, i, j);
	else if (c == '0')
		display_img(ptr, NULL, i, j);
	else if (c == '1')
		display_img(ptr, ptr->wall.img, i, j);
	lose_win(ptr);
}

int	ft_draw(t_data *ptr)
{
	int (i), (j);
	enemy_img(ptr);
	mlx_clear_window(ptr->mlx, ptr->win);
	i = 0;
	while (ptr->map_str[i])
	{
		j = 0;
		if (check_no_enemy(ptr) && (ptr->bomb || ptr->winer))
			ptr->finish++;
		while (ptr->map_str[i][j])
		{
			ft_draw_helper(ptr, i, j);
			j++;
		}
		i++;
	}
	print_moves(ptr);
	return (0);
}
