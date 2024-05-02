/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_explosion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:31:19 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/02 10:21:35 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_true(t_data *ptr, int i, int j)
{
	char	c;

	c = ptr->map_str[i][j];
	if (c == 'N' || c == 'n')
	{
		ptr->map_str[i][j] = '0';
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, j * 50, i * 50);
	}
}

static void	ft_bombe_line(t_data *ptr, int i, int j, int index)
{
	char	*path;
	char	*path2;

	int (pl_indx), (ene_indx);
	pl_indx = ptr->player.img_indx;
	ene_indx = ptr->enemy.img_indx;
	if (index % 9000 == 0)
	{
		path = make_path(ene_indx, "./textures/player/enemy/dead/");
		path2 = make_path(pl_indx, "./textures/player/player_sprite/dead/");
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, path2, \
		&ptr->size_x, &ptr->size_y);
		ptr->player.img_indx++;
		ptr->enemy.img_indx++;
		(check_true(ptr, i, j - 1), check_true(ptr, i, j + 1));
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, j * 50, i * 50);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->player.img, j * 50, i * 50);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->enemy.img, j * 50, i * 50);
	}
}

void	ft_enemy_bombe(t_data *ptr, int i, int j)
{
	static int	index;

	ptr->bomb = 1;
	if (ptr->enemy.img_indx > 2)
	{
		ptr->bomb = 2;
		ptr->player.img_indx = 0;
		ptr->enemy.img_indx = 0;
		return ;
	}
	if (ptr->player.img_indx > 2)
		ptr->player.img_indx = 2;
	index++;
	ft_bombe_line(ptr, i, j, index);
}
