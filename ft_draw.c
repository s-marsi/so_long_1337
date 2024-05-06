/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:03:25 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/06 12:19:01 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	enemy_img(t_data *ptr)
{
	int (i), (j), (n);
	n = 10;
	if (ptr->num_item / 3 < ptr->player.item_eaten)
		n = 6;
	if (ptr->num_item / 2 < ptr->player.item_eaten)
		n = 4;
	i = 0;
	if (ptr->enemy.speed == n)
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
	if (ptr->map_str[i][j] == 'P')
		ft_player_animation(ptr, i, j, 0);
	else if (ptr->map_str[i][j] == '0')
		display_img(ptr, NULL, i, j);
	else if (ptr->map_str[i][j] == '1')
		display_img(ptr, ptr->wall.img, i, j);
	if (ptr->map_str[i][j] == 'N')
		display_img(ptr, "./textures/player/enemy/right/0.xpm", i, j);
	else if (ptr->map_str[i][j] == 'n')
		display_img(ptr, "./textures/player/enemy/left/0.xpm", i, j);
	else if (ptr->map_str[i][j] == 'E')
		ft_exit(ptr, i, j);
	else if (ptr->map_str[i][j] == 'C')
		ft_collectible_animation(ptr, i, j);
	else if (ptr->map_str[i][j] == 'B')
		display_img(ptr, "./textures/player/enemy4/0.xpm", i, j);
}

int	ft_draw(t_data *ptr)
{
	i = 0;
	while (ptr->map_str[i])
	{
		j = 0;
		while (ptr->map_str[i][j])
		{
			ft_draw_helper(ptr, i, j);
			j++;
		}
		i++;
	}
	print_moves2(ptr);
	return (0);
}
