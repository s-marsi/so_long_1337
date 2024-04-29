/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_right_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:46:27 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/29 16:44:48 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_moves(t_data *ptr)
{
	ptr->moves_number++;
	ft_putstr_fd("MOVES : ", 1);
	ft_putnbr_fd(ptr->moves_number, 1);
	ft_putstr_fd("\n", 1);
}

static void	print_moves2(t_data *ptr)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(ptr->moves_number);
	str = ft_strjoin2("moves : ", tmp);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, 2 * 50, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall.img, 2 * 50, 0);
	mlx_string_put(ptr->mlx, ptr->win, 25 , 15, 0x00FF0000, str);
	free(tmp);
	free(str);
}

static void	check_items(t_data *ptr, int x, int y)
{
	if (ptr->map_str[y][x] == 'C')
	{
		ptr->player.item_eaten++;
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, x * 50, y * 50);
		ptr->map_str[y][x] = '0';
	}
	else if (ptr->map_str[y][x] == 'E')
		ft_exit_animation(ptr, y, x);
}

void	move_right_helper(t_data *ptr, int x, int y, int i)
{
	char	*path;

	path = NULL;
	if (ptr->map_str[y][x + 1] == 'C' || ptr->map_str[y][x + 1] == '1')
		path = "./textures/player/player_sprite/right/0.xpm";
	else if (i < 2)
	{
		if (i == 0)
			path = "./textures/player/player_sprite/right/1.xpm";
		else
			path = "./textures/player/player_sprite/right/2.xpm";
		ptr->player.img_indx++;
	}
	else if (i == 2)
	{
		path = "./textures/player/player_sprite/right/0.xpm";
		ptr->player.img_indx = 0;
	}
	if (path)
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
}

void	move_right(t_data *ptr, int x, int y, int flag)
{
	int	i;

	ptr->player.animation = 0;
	if (flag == 1)
		ft_enemy_bombe(ptr, x + 1, y);
	else if (flag == 2)
		ft_destroy_all(ptr, "YOU LOSE :(", 1);
	check_items(ptr, x + 1, y);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, x * 50, y * 50);
	ptr->map_str[y][x] = '0';
	ptr->map_str[y][x + 1] = 'P';
	ptr->player.pos_x += 1;
	x++;
	i = ptr->player.img_indx;
	move_right_helper(ptr, x, y, i);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->player.img, x * 50, y * 50);
	print_moves(ptr);
	print_moves2(ptr);
}

void	move_left_helper(t_data *ptr, int x, int y, int i)
{
	char	*path;

	path = NULL;
	if (ptr->map_str[y][x - 1] == 'C' || ptr->map_str[y][x - 1] == '1')
		path = "./textures/player/player_sprite/left/0.xpm";
	else if (i < 2)
	{
		if (i == 0)
			path = "./textures/player/player_sprite/left/1.xpm";
		else
			path = "./textures/player/player_sprite/left/2.xpm";
		ptr->player.img_indx++;
	}
	else
	{
		path = "./textures/player/player_sprite/left/0.xpm";
		ptr->player.img_indx = 0;
	}
	if (path)
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
}

void	move_left(t_data *ptr, int x, int y, int flag)
{
	int	i;

	ptr->player.animation = 1;
	if (flag == 1)
		ft_enemy_bombe(ptr, x - 1, y);
	else if (flag == 2)
		ft_destroy_all(ptr, "YOU LOSE :(", 1);
	check_items(ptr, x - 1, y);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, x * 50, y * 50);
	ptr->map_str[y][x] = '0';
	ptr->map_str[y][x - 1] = 'P';
	ptr->player.pos_x -= 1;
	x--;
	i = ptr->player.img_indx;
	move_left_helper(ptr, x, y, i);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->player.img, x * 50, y * 50);
	print_moves(ptr);
	print_moves2(ptr);
}
