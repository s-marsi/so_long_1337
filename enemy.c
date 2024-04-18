/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:52:40 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/17 16:25:04 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static char	*ft_strjoin2(char *s1, char *s2)
// {
// 	char	*str;
// 	int		len;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	else if (!s1)
// 		return (ft_strdup(s2));
// 	else if (!s2)
// 		return (ft_strdup(s1));
// 	len = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	str = malloc(len * sizeof(char));
// 	if (!str)
// 		return (str);
// 	str[0] = '\0';
// 	ft_strlcat(str, s1, ft_strlen(s1) + 1);
// 	ft_strlcat(str, s2, len);
// 	return (str);
// }

// static void	ft_collectible_img(t_data *ptr)
// {
// 	char	*path;
// 	int		*x;
// 	int		*y;

// 	path = NULL;
// 	if (ptr->enemy.right <= 25)
// 		path = ft_strjoin2("./images/collection/", "0.xpm");
// 	else if (ptr->enemy.right <= 50)
// 		path = ft_strjoin2("./images/collection/", "1.xpm");
// 	else if (ptr->enemy.right <= 75)
// 		path = ft_strjoin2("./images/collection/", "2.xpm");
// 	else if (ptr->enemy.right <= 100)
// 		path = ft_strjoin2("./images/collection/", "3.xpm");
// 	else if (ptr->enemy.right <= 125)
// 		path = ft_strjoin2("./images/collection/", "4.xpm");
// 	else if (ptr->item.img_indx <= 150)
// 	{
// 		path = ft_strjoin2("./images/collection/", "5.xpm");
// 		ptr->item.img_indx = 0;
// 	}
// 	x = &ptr->size_x;
// 	y = &ptr->size_y;
// 	ptr->item.img = mlx_xpm_file_to_image(ptr->mlx, path, x, y);
// 	free(path);
// 	path = NULL;
// }

// void    move_right(t_data *ptr, int *x, int *y)
// {
//     int i;

//     mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, *x * 50, *y * 50);
//     ptr->enemy.pos_x += 1;
//     i = ptr->enemy.right;
//     ptr->enemy.left = -1;
//     if (ptr->map_str[*y][*x + 1] == 'C' || ptr->map_str[*y][*x] == '1')
//         ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/0.xpm", &ptr->size_x, &ptr->size_y);
//     if (i <= 50)
//         ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/1.xpm", &ptr->size_x, &ptr->size_y);
//     else if (i <= 100)
//        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/2.xpm", &ptr->size_x, &ptr->size_y);
//     else if (i <= 150)
//        ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/3.xpm", &ptr->size_x, &ptr->size_y);
//     else if (i <= 200)
//         ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/4.xpm", &ptr->size_x, &ptr->size_y);
//     else if (i <= 250)
//         ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/5.xpm", &ptr->size_x, &ptr->size_y);
//     else if (i <= 300)
//     {
//         ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/6.xpm", &ptr->size_x, &ptr->size_y);
//         ptr->enemy.right = -1;
//         ptr->enemy.left = 0;
//     }
// }

// int	ft_enemy_animation(t_data *ptr)
// {
// 	int	i;
// 	int	y;

// 	i = ptr->enemy.pos_x;
//     y = ptr->enemy.pos_y;

//     if (ptr->map_str[y][i + 1] == '0' &&  ptr->enemy.right >= 0)
//     {
//         move_right(ptr,  &ptr->enemy.pos_x,  &ptr->enemy.pos_y);
// 		// ft_collectible_img(ptr);
//         i = ptr->enemy.pos_x;
//         y = ptr->enemy.pos_y;
// 		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, i * 50, y * 50);
// 		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->enemy.img, i * 50, y * 50);
//         ptr->enemy.right++;
// 	}
// 	return (0);
// }

