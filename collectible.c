/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:18:02 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/18 07:07:40 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (str);
	str[0] = '\0';
	ft_strlcat(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, len);
	return (str);
}

static void	ft_collectible_img(t_data *ptr)
{
	char	*path;
	int		*x;
	int		*y;

	path = NULL;
	if (ptr->item.img_indx <= 25)
		path = ft_strjoin2("./images/collection/", "0.xpm");
	else if (ptr->item.img_indx <= 50)
		path = ft_strjoin2("./images/collection/", "1.xpm");
	else if (ptr->item.img_indx <= 75)
		path = ft_strjoin2("./images/collection/", "2.xpm");
	else if (ptr->item.img_indx <= 100)
		path = ft_strjoin2("./images/collection/", "3.xpm");
	else if (ptr->item.img_indx <= 125)
		path = ft_strjoin2("./images/collection/", "4.xpm");
	else if (ptr->item.img_indx <= 150)
	{
		path = ft_strjoin2("./images/collection/", "5.xpm");
		ptr->item.img_indx = 0;
	}
	x = &ptr->size_x;
	y = &ptr->size_y;
	ptr->item.img = mlx_xpm_file_to_image(ptr->mlx, path, x, y);
	free(path);
	path = NULL;
}

void    move_right(t_data *ptr, int *x, int *y)
{
    int i;

    mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, *y * 50, *x * 50);
    *y += 1;
    i = ptr->enemy.right;
    ptr->enemy.left = -1;
    if (ptr->map_str[*x][*y + 1] == 'C' || ptr->map_str[*x][*y + 1] == '1')
	{
        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/0.xpm", &ptr->size_x, &ptr->size_y);
		ptr->enemy.right = -1;
        ptr->enemy.left = 0;
	}
    if (i <= 30)
        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/1.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 60)
       ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/2.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 90)
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/3.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 120)
        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/4.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 150)
        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/5.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 180)
	{
        ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/6.xpm", &ptr->size_x, &ptr->size_y);
		ptr->enemy.right = 0;
	}
}
void    move_left(t_data *ptr, int *x, int *y)
{
    int i;
	
    mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, *y * 50, *x * 50);
    *y -= 1;
    i = ptr->enemy.left;
    ptr->enemy.right = -1;
    if (ptr->map_str[*x][*y - 1] == 'C' || ptr->map_str[*x][*y - 1] == '1')
	{
        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/left/0.xpm", &ptr->size_x, &ptr->size_y);
		ptr->enemy.right = 0;
        ptr->enemy.left = -1;
	}
    if (i <= 30)
        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/left/1.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 60)
       ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/left/2.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 90)
       ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/left/3.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 120)
        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/left/4.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 150)
        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/left/5.xpm", &ptr->size_x, &ptr->size_y);
    else if (i <= 180)
	{
        ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/left/6.xpm", &ptr->size_x, &ptr->size_y);
		ptr->enemy.left = 0;
	}
}

int	ft_enemy_animation(t_data *ptr, int i, int j)
{
	int	y;
	int	n;

    if (ptr->map_str[i][j + 1] == '0' &&  ptr->enemy.right >= 0)
    {
		n = ptr->enemy.right;
		if (n == 30 || n == 60 || n == 90 || n == 120 || n == 150 || n == 180)
		{
			ptr->map_str[i][j] = '0';
			move_right(ptr,  &i,  &j);
			ptr->map_str[i][j] = 'E';	
		}
        ptr->enemy.right++;
	}
	else if (ptr->map_str[i][j - 1] == '0'&&  ptr->enemy.left >= 0)
	{
		n = ptr->enemy.left;
		if (n == 30 || n == 60 || n == 90 || n == 120 || n == 150 || n == 180)
		{
			ptr->map_str[i][j] = '0';
			move_left(ptr,  &i,  &j);
			ptr->map_str[i][j] = 'E';
		}
		ptr->enemy.left++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, j * 50, i * 50);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->enemy.img, j * 50, i * 50);
	return (0);
}

int	ft_collectible_animation(t_data *ptr)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	t;

	i = 0;
	while (ptr->map_str[i])
	{
		j = 0;
		while (ptr->map_str[i][j])
		{
			y = i * 50;
			if (ptr->map_str[i][j] == 'C')
			{
				x = j * 50;
				ft_collectible_img(ptr);
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, x, y);
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->item.img, x, y);
				ptr->item.img_indx++;
			}
			if (ptr->map_str[i][j] == 'E')
				ft_enemy_animation(ptr, i, j);
			j++;
		}
		i++;
	}
	return (0);
}



