/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 07:06:50 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 08:18:51 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_finish(t_data *ptr)
{
	char	**str;
	int		i;
	int		j;

	str = ptr->map_str;
	i = 0;
	while (str[i])
	{
		if (i == 0 || !str[i + 1])
		{
			j = 0;
			while (str[i][j] && str[i][j] != '\n')
			{
				if (str[i][j] != '0' && str[i][j] != '1')
					return (0);
				j++;
			}
		}
		i++;
	}
	return (1);
}

void	call_img(t_data *ptr, char *path, int i)
{
	path = make_path(i, path);
	ptr->exit.img = mlx_xpm_file_to_image(ptr->mlx, path, \
	&ptr->size_x, &ptr->size_y);
	free(path);
	check_img(ptr, ptr->exit.img);
}

static void	draw_player(t_data *ptr, int x, int y)
{
	static int	c;

	if (c++ == (100 * ptr->size_y_map) || c >= 1200)
		ft_destroy_all(ptr, 0, 1);
	if (ptr->player.img_indx > 3)
		ptr->player.img_indx = 0;
	y = ((ptr->size_x_map / 2));
	x = ((ptr->size_y_map / 2));
	ptr->player.animation = 0;
	ft_player_animation(ptr, x, y, 1);
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

void	ft_win(t_data *ptr)
{
	static int	c;

	draw_win(ptr);
	c++;
	if (c == 700)
		ft_destroy_all(ptr, 0, 1);
}
