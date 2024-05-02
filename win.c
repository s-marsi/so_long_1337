/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:06:50 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/02 11:02:01 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	call_img(t_data *ptr, char *path, int i)
{
	path = make_path(i, path);
	ptr->exit.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	free(path);
}

static void	draw_player(t_data *ptr, int x, int y)
{
	int		n;
	char	*path;

	if (ptr->player.img_indx > 3)
		ptr->player.img_indx = 0;
	n = ptr->player.img_indx;
	y = ((ptr->size_x_map / 2)) * 50;
	x = ((ptr->size_y_map / 2)) * 50;
	path = make_path(n, "./textures/player/player_sprite/idle/left/");
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, y, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->player.img, y, x);
	ptr->player.img_indx++;
	free(path);
}

static void	draw_win(t_data *ptr)
{
	int (x), (y);
	x = ((ptr->size_y_map / 2)) * 50;
	y = ((ptr->size_x_map / 2) - 3);
	call_img(ptr, "./textures/win/", 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y) * 50, x);
	call_img(ptr, "./textures/win/", 1);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 1) * 50, x);
	call_img(ptr, "./textures/win/", 2);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 2) * 50, x);
	call_img(ptr, "./textures/win/", 3);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 4) * 50, x);
	call_img(ptr, "./textures/win/", 4);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 5) * 50, x);
	call_img(ptr, "./textures/win/", 5);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->exit.img, (y + 6) * 50, x);
	draw_player(ptr, x, y);
}

static void	win_bomb(t_data *ptr, int i, int j)
{
	int		n;
	char	*path;

	if (ptr->enemy2.img_indx > 2)
		ptr->enemy2.img_indx = 0;
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

void	ft_win(t_data *ptr, int i, int j)
{
	static int	c;

	draw_win(ptr);
	c++;
	if (c == 1200)
		ft_destroy_all(ptr, 0, 1);
	if (ptr->map_str[i][j] == 'B' || ptr->map_str[i][j] == 'N'
	|| ptr->map_str[i][j] == 'n')
		win_bomb(ptr, i, j);
	else if (ptr->map_str[i][j] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, j * 50, i * 50);
}
