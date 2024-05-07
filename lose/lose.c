/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lose.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:05:46 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 08:18:49 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_player(t_data *ptr, int x, int y, int c)
{
	char	*path;

	y = ((ptr->size_x_map / 2)) * 50;
	x = ((ptr->size_y_map / 2)) * 50;
	if (c < 250)
		path = make_path(1, "./textures/player/player_sprite/dead/");
	else
		path = make_path(2, "./textures/player/player_sprite/dead/");
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	if (path)
		free(path);
	check_img(ptr, ptr->player.img);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, y, x);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->player.img, y, x);
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
	if (path)
		free(path);
	check_img(ptr, ptr->enemy2.img);
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

void	ft_lose(t_data *ptr)
{
	static int	c;

	int (x), (y);
	c++;
	x = ((ptr->size_y_map / 2)) * 50;
	y = ((ptr->size_x_map / 2) - 4);
	if (c <= 450)
		game_over(ptr, x, y);
	else
		game_over_two(ptr, x, y);
	draw_player(ptr, x, y, c);
	if (c == 700)
		ft_destroy_all(ptr, 1, 1);
}
