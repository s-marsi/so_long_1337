/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:15:49 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/02 07:10:07 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	blow_up_all(t_data *ptr, int i, int j)
{
	char	*path;
	int		index;

	ptr->kill_all++;
	index = ptr->enemy.img_indx;
	if (ptr->kill_all == 500)
		ft_destroy_all(ptr, 1, 1);
	if (index > 9)
		path = make_path(2, "./textures/background/green_");
	else
		path = make_path(index, "./textures/player/enemy/attack/");
	ptr->enemy.img_indx++;
	mlx_put_image_to_window(ptr->mlx, ptr->win, \
	ptr->img.img, j * 50, i * 50);
	ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	free(path);
	path = NULL;
	mlx_string_put(ptr->mlx, ptr->win, (ptr->size_x_map / 2) * 50, \
	(ptr->size_y_map / 2) * 50, 0x00FF0000, "GAME OVER");
}

static int	check_true(t_data *ptr, int i, int j)
{
	if ((ptr->map_str[i][j] == 'E' || ptr->map_str[i][j] == 'C')
	|| ptr->map_str[i][j] == 'N' || ptr->map_str[i][j] == 'n'
	|| ptr->map_str[i][j] == 'B')
		return (1);
	return (0);
}

static void	ft_collectible_helper(t_data *ptr, int i, int j)
{
	int (x), (y);
	y = i * 50;
	if (ptr->map_str[i][j] == 'C')
	{
		x = j * 50;
		ft_collectible_img(ptr);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, x, y);
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->item.img, x, y);
		ptr->item.img_indx++;
	}
	else if (ptr->map_str[i][j] == 'E')
		ft_exit(ptr, i, j);
	else if (ptr->map_str[i][j] == 'N')
		right_route(ptr, &i, &j);
	else if (ptr->map_str[i][j] == 'n')
		left_route(ptr, &i, &j);
	else if (ptr->map_str[i][j] == 'B')
		bombe_animation(ptr, i, j);
	else if (ptr->map_str[i][j] == 'P')
		ft_player_animation(ptr, i, j);
}

int	ft_collectible_animation(t_data *ptr)
{
	int (i), (j);
	i = 0;
	while (ptr->map_str[i])
	{
		j = 0;
		while (ptr->map_str[i][j])
		{
			if (ptr->bomb == 2 && check_true(ptr, i, j))
				blow_up_all(ptr, i, j);
			else if (ptr->map_str[i][j] == 'P' && ptr->bomb == 1)
				ft_enemy_bombe(ptr, i, j);
			else if (ptr->map_str[i][j] == 'P' && ptr->finish == 1)
				ft_exit_animation(ptr, i, j);
			else if (ptr->finish == 2)
				ft_win(ptr, i, j);
			else if (ptr->map_str[i][j] == 'P' && ptr->attack && !ptr->bomb)
				press_key(3, ptr);
			else if (!ptr->finish && !ptr->bomb)
				ft_collectible_helper(ptr, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
