/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:20:37 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/29 14:43:19 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	right_animation(t_data *ptr, int *a, char c, int *index)
{
	char	*path;

	int (i), (j);
	i = a[0];
	j = a[1];
	path = NULL;
	if (ptr->map_str[i][j] == 'C' || ptr->map_str[i][j] == '1')
		path = "./textures/player/enemy/right/0.xpm";
	else if (*index <= 1)
		path = "./textures/player/enemy/right/0.xpm";
	else if (*index <= 2)
		path = "./textures/player/enemy/right/1.xpm";
	else if (*index <= 5)
	{
		path = "./textures/player/enemy/right/2.xpm";
		*index = 0;
	}
	if (path)
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
}

void	ft_enemy_animation(t_data *ptr, int i, int j, char c)
{
	static int	index;
	char		*path;
	int			a[2];

	a[0] = i;
	a[1] = j;
	path = NULL;
	if (c == 'n')
	{
		if (ptr->map_str[i][j] == 'C' || ptr->map_str[i][j] == '1')
			path = "./textures/player/enemy/left/0.xpm";
		else if (index <= 1)
			path = "./textures/player/enemy/left/0.xpm";
		else if (index <= 2)
			path = "./textures/player/enemy/left/1.xpm";
		else if (index <= 5)
		{
			path = "./textures/player/enemy/left/2.xpm";
			index = 0;
		}
		if (path)
			ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
			&ptr->size_x, &ptr->size_y);
	}
	else
		right_animation(ptr, a, c, &index);
	index++;
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, j * 50, i * 50);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->enemy.img, j * 50, i * 50);
}

void	right_animation2(t_data *ptr, int *a, char c, int *index)
{
	char		*path;

	int (i), (j);
	i = a[0];
	j = a[1];
	path = NULL;
	if (ptr->map_str[i][j] == 'C' || ptr->map_str[i][j] == '1')
		path = "./textures/player/enemy/angry/right/0.xpm";
	else if (*index <= 1)
		path = "./textures/player/enemy/angry/right/0.xpm";
	else if (*index <= 2)
	{
		path = "./textures/player/enemy/angry/right/1.xpm";
		*index = 0;
	}
	if (path)
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
}

void	ft_enemy_animation2(t_data *ptr, int i, int j, char c)
{
	static int	index;
	char		*path;
	int			a[2];

	a[0] = i;
	a[1] = j;
	path = NULL;
	if (c == 'n')
	{
		if (ptr->map_str[i][j] == 'C' || ptr->map_str[i][j] == '1')
			path = "./textures/player/enemy/angry/left/0.xpm";
		else if (index <= 1)
			path = "./textures/player/enemy/angry/left/0.xpm";
		else if (index <= 2)
		{
			path = "./textures/player/enemy/angry/left/1.xpm";
			index = 0;
		}
		if (path)
			ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
			&ptr->size_x, &ptr->size_y);
	}
	else
		right_animation2(ptr, a, c, &index);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, j * 50, i * 50);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->enemy.img, j * 50, i * 50);
	index++;
}
