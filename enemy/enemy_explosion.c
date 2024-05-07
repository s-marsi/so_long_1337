/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_explosion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:31:19 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 09:11:01 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	blow_up(t_data *ptr, int i, int j, int index)
{
	char	*path;

	path = make_path(index, \
	"./textures/player/enemy/dead/");
	if (path)
	{
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		(free(path), check_img(ptr, ptr->enemy.img));
		path = NULL;
	}
	path = make_path(index, \
	"./textures/player/player_sprite/dead/");
	if (path)
	{
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		(free(path), check_img(ptr, ptr->enemy.img));
		path = NULL;
	}
	display_img(ptr, ptr->player.img, i, j);
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->enemy.img, j * 50, i * 50);
	mlx_destroy_image(ptr->mlx, ptr->player.img);
}

void	ft_enemy_bombe(t_data *ptr, int i, int j)
{
	static int	index;
	static int	c;
	int			n;

	if (!ptr->bomb)
		ptr->bomb = 1;
	n = 25;
	if (ptr->size_y_map >= 25 || ptr->size_x_map >= 40)
		n = 10;
	if (c >= n)
	{
		if (index >= 2)
		{
			ptr->map_str[i][j] = '0';
			ptr->kill_all = 1;
			index = 0;
		}
		index++;
		c = 0;
	}
	c++;
	if (index > 2)
		index = 2;
	blow_up(ptr, i, j, index);
}

void	ft_enemy_bombe2(t_data *ptr, int i, int j)
{
	int		index;
	char	*path;

	if (!ptr->bomb)
		ptr->bomb = 1;
	ptr->map_str[i][j] = '0';
	index = 1;
	if (index > 2)
		index = 2;
	path = "./textures/player/enemy/dead/0.xpm";
	ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	check_img(ptr, ptr->enemy.img);
	display_img(ptr, ptr->enemy.img, i, j);
	mlx_destroy_image(ptr->mlx, ptr->enemy.img);
}
