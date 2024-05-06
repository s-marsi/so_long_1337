/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:05:46 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/06 12:19:41 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_player(t_data *ptr, int x, int y)
{
	int		n;
	char	*path;

	if (ptr->player.img_indx > 2)
		ptr->player.img_indx = 2;
	n = ptr->player.img_indx;
	y = ((ptr->size_x_map / 2)) * 50;
	x = ((ptr->size_y_map / 2)) * 50;
	path = make_path(n, "./textures/player/player_sprite/dead/");
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, y, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->player.img, y, x);
	ptr->player.img_indx++;
	free(path);
}

static void	draw_lose(t_data *ptr)
{
	static int	c;

	int (x), (y);
	x = ((ptr->size_y_map / 2)) * 50;
	y = ((ptr->size_x_map / 2) - 4);
	if (c >= ptr->enemy2.speed)
	{
		game_over(ptr, x, y);
		draw_player(ptr, x, y);
		c = 0;
	}
	else
		game_over_two(ptr, x, y);
	c++;
}

void	lose_bomb(t_data *ptr, int i, int j)
{
	int		n;
	char	*path;

	if (ptr->enemy2.img_indx >= 1)
		ptr->enemy2.img_indx = 2;
	n = ptr->enemy2.img_indx;
	path = make_path(n, "./textures/player/enemy4/dead/");
	ptr->enemy2.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	free(path);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->enemy2.img, j * 50, i * 50);
	ptr->enemy2.img_indx++;
	if (n == 2)
	{
		n = 0;
		ptr->map_str[i][j] = '0';
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, j * 50, i * 50);
	}
}

void	ft_lose(t_data *ptr, int i, int j)
{
	static int	c;

	draw_lose(ptr);
	c++;
	if (ptr->map_str[i][j] == 'C' || ptr->map_str[i][j] == 'E'
	|| ptr->map_str[i][j] == 'P')
	{
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, j * 50, i * 50);
		ptr->map_str[i][j] = '0';
	}
	else if (ptr->map_str[i][j] == 'B' || ptr->map_str[i][j] == 'N'
		|| ptr->map_str[i][j] == 'n')
		lose_bomb(ptr, i, j);
	if (c == (100 * ptr->size_y_map) || c >= 1200)
		ft_destroy_all(ptr, 1, 1);
}
