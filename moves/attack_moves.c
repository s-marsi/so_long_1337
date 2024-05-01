/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 06:34:25 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/01 10:48:03 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	attack_right_helper(t_data *ptr, int i, int x, int y)
{
	char	*path;	

	path = NULL;
	if (i == 4)
	{
		ptr->attack = 0;
		ptr->player.img_indx = 0;
	}
	else if (i == 3 && ptr->map_str[y][x + 1] == 'B')
	{
		ptr->map_str[y][x + 1] = '0';
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->img.img, (x + 1) * 50, y * 50);
	}
	else
		path = make_path(i, "./textures/player/player_sprite/attack/right/");
	ptr->player.img_indx++;
	if (path)
	{
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		free(path);
	}
}

void	attack_right(t_data *ptr, int x, int y)
{
	static int	c;
	int			i;

	if (ptr->attack == 0)
	{
		ptr->player.img_indx = 0;
		ptr->attack = 1;
	}
	i = ptr->player.img_indx;
	c++;
	if (c % 12 == 0)
	{
		attack_right_helper(ptr, i, x, y);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->img.img, x * 50, y * 50);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->player.img, x * 50, y * 50);
	}
}

void	attack_left_helper(t_data *ptr, int i, int x, int y)
{
	char	*path;

	path = NULL;
	if (i == 4)
	{
		ptr->attack = 0;
		ptr->player.img_indx = 0;
	}
	else if (i == 3 && ptr->map_str[y][x - 1] == 'B')
	{
		ptr->map_str[y][x - 1] = '0';
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, (x - 1) * 50, y * 50);
	}
	else
		path = make_path(i, "./textures/player/player_sprite/attack/left/");
	ptr->player.img_indx++;
	if (path)
	{
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		free(path);
	}
}

void	attack_left(t_data *ptr, int x, int y)
{
	static int	c;
	int			i;

	if (ptr->attack == 0)
	{
		ptr->player.img_indx = 0;
		ptr->attack = 1;
	}
	i = ptr->player.img_indx;
	c++;
	if (c % 12 == 0)
	{
		attack_left_helper(ptr, i, x, y);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->img.img, x * 50, y * 50);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->player.img, x * 50, y * 50);
	}
}
