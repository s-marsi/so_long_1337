/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:34:25 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 08:59:49 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	attack_enemy(t_data *ptr, int x, int y)
{
	char		*path;
	static int	c;

	if (ptr->enemy2.animation > 2)
		ptr->enemy2.animation = 2;
	path = make_path(ptr->enemy2.animation, "./textures/player/enemy4/dead/");
	ptr->enemy2.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
	if (path)
		free(path);
	check_img(ptr, ptr->enemy2.img);
	if (c++ >= moves_speed(ptr))
	{
		ptr->enemy2.animation++;
		c = 0;
	}
	if (ptr->enemy2.animation >= 3)
	{
		ptr->attack = 0;
		c = 0;
		ptr->player.img_indx = 0;
		ptr->enemy2.animation = 0;
		ptr->map_str[x][y] = '0';
	}
}

void	attack_right_helper(t_data *ptr, int i, int x, int y)
{
	char	*path;

	path = NULL;
	if (i >= 2)
	{
		(is_enemy2(ptr, x - 1, y), is_enemy2(ptr, x + 1, y));
		(is_enemy2(ptr, x, y - 1), is_enemy2(ptr, x, y + 1));
	}
	if (i >= 4)
	{
		i = 3;
		ptr->attack = 0;
		ptr->player.img_indx = 0;
	}
	else
		path = make_path(i, "./textures/player/player_sprite/attack/right/");
	ptr->player.img_indx++;
	if (path)
	{
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		if (path)
			free(path);
		check_img(ptr, ptr->player.img);
	}
}

void	attack_right(t_data *ptr, int x, int y)
{
	static int	c;
	int			i;
	int			n;

	if (ptr->attack == 0)
	{
		ptr->player.img_indx = 0;
		ptr->attack = 1;
	}
	i = ptr->player.img_indx;
	c++;
	n = 7;
	if (ptr->size_y_map >= 25 || ptr->size_x_map >= 50)
		n = 3;
	if (c == n)
	{
		attack_right_helper(ptr, i, x, y);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->img.img, x * 50, y * 50);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->player.img, x * 50, y * 50);
		c = 0;
	}
}

void	attack_left_helper(t_data *ptr, int i, int x, int y)
{
	char	*path;

	path = NULL;
	is_enemy2(ptr, x - 1, y);
	is_enemy2(ptr, x + 1, y);
	is_enemy2(ptr, x, y - 1);
	is_enemy2(ptr, x, y + 1);
	if (i >= 4)
	{
		i = 3;
		ptr->attack = 0;
		path = make_path(0, "./textures/player/player_sprite/left/");
		ptr->player.img_indx = 0;
	}
	else
		path = make_path(i, "./textures/player/player_sprite/attack/left/");
	ptr->player.img_indx++;
	if (path)
	{
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		if (path)
			free(path);
		check_img(ptr, ptr->player.img);
	}
}

void	attack_left(t_data *ptr, int x, int y)
{
	static int	c;
	int			i;
	int			n;

	if (ptr->attack == 0)
	{
		ptr->player.img_indx = 0;
		ptr->attack = 1;
	}
	i = ptr->player.img_indx;
	c++;
	n = 7;
	if (ptr->size_y_map >= 25 || ptr->size_x_map >= 50)
		n = 3;
	if (c >= moves_speed(ptr))
	{
		attack_left_helper(ptr, i, x, y);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->img.img, x * 50, y * 50);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->player.img, x * 50, y * 50);
		c = 0;
	}
}
