/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:03:25 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/27 15:31:51 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_draw_helper(t_data *ptr, int i, int j)
{
	if (ptr->map_str[i][j] == 'P')
	{
		mlx_put_image_to_window(ptr->mlx, \
		ptr->win, ptr->player.img, j * 50, i * 50);
		ptr->player.pos_x = j;
		ptr->player.pos_y = i;
	}
	else if (ptr->map_str[i][j] == '1')
		mlx_put_image_to_window(ptr->mlx, \
		ptr->win, ptr->wall.img, j * 50, i * 50);
	else if (ptr->map_str[i][j] == 'N' || ptr->map_str[i][j] == 'n')
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->enemy.img, j * 50, i * 50);
	else if (ptr->map_str[i][j] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->exit.img, j * 50, i * 50);
	else if (ptr->map_str[i][j] == 'C')
		ptr->num_item++;
	else if (ptr->map_str[i][j] == 'B')
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->enemy2.img, j * 50, i * 50);
}

int	ft_draw(t_data *ptr)
{
	int (i), (j);
	i = 0;
	while (ptr->map_str[i])
	{
		j = 0;
		while (ptr->map_str[i][j])
		{
			mlx_put_image_to_window(ptr->mlx, ptr->win, \
			ptr->img.img, j * 50, i * 50);
			ft_draw_helper(ptr, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
