/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:46:27 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 07:01:20 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_items(t_data *ptr, int x, int y)
{
	char	c;

	c = ptr->map_str[y][x];
	if (c == 'C')
	{
		ptr->player.item_eaten++;
		ptr->map_str[y][x] = '0';
	}
	else if (c == 'E')
		ft_exit_animation(ptr, y, x);
	else if (c == 'N' || c == 'n' || c == 'B')
		ft_enemy_bombe(ptr, x, y);
}

void	move_right(t_data *ptr, int x, int y, int flag)
{
	int	i;

	ptr->player.animation = 0;
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/player/player_sprite/idle/right_down/1.xpm", \
	&ptr->size_x, &ptr->size_y);
	check_img(ptr, ptr->player.img);
	if (flag)
		ft_enemy_bombe(ptr, x + 1, y);
	else if (flag == 2)
		ft_destroy_all(ptr, 1, 1);
	check_items(ptr, x + 1, y);
	ptr->map_str[y][x] = '0';
	ptr->map_str[y][x + 1] = 'P';
	ptr->player.pos_x += 1;
	x++;
	i = ptr->player.img_indx;
	ptr->moves_number++;
}

void	move_left(t_data *ptr, int x, int y, int flag)
{
	int	i;

	ptr->player.animation = 1;
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/player/player_sprite/idle/left/1.xpm", \
	&ptr->size_x, &ptr->size_y);
	check_img(ptr, ptr->player.img);
	if (flag)
		ft_enemy_bombe(ptr, x - 1, y);
	else if (flag == 2)
		ft_destroy_all(ptr, 1, 1);
	check_items(ptr, x - 1, y);
	ptr->map_str[y][x] = '0';
	ptr->map_str[y][x - 1] = 'P';
	ptr->player.pos_x -= 1;
	x--;
	i = ptr->player.img_indx;
	ptr->moves_number++;
}
