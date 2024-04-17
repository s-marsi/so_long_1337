/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:18:02 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/17 14:20:12 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_collectible_img(t_data *ptr)
{
    if (ptr->collec.img_indx <= 25)
        ptr->collec.img = mlx_xpm_file_to_image(ptr->mlx, "./images/collection/0.xpm", &ptr->size_x, &ptr->size_y);
    else if (ptr->collec.img_indx <= 50)
        ptr->collec.img = mlx_xpm_file_to_image(ptr->mlx, "./images/collection/1.xpm", &ptr->size_x, &ptr->size_y);
    else if (ptr->collec.img_indx <= 75)
        ptr->collec.img = mlx_xpm_file_to_image(ptr->mlx, "./images/collection/2.xpm", &ptr->size_x, &ptr->size_y);
    else if (ptr->collec.img_indx <= 100)
        ptr->collec.img = mlx_xpm_file_to_image(ptr->mlx, "./images/collection/3.xpm", &ptr->size_x, &ptr->size_y);
    else if (ptr->collec.img_indx <= 125)
        ptr->collec.img = mlx_xpm_file_to_image(ptr->mlx, "./images/collection/4.xpm", &ptr->size_x, &ptr->size_y);
    else if (ptr->collec.img_indx <= 150)
    {
        ptr->collec.img = mlx_xpm_file_to_image(ptr->mlx, "./images/collection/5.xpm", &ptr->size_x, &ptr->size_y);
        ptr->collec.img_indx = 0;
    }
}

int ft_collectible_animation(t_data *ptr)
{
    int i;
    int j;

    i = 0;
    while (ptr->map_str[i])
    {
        j = 0;
        while (ptr->map_str[i][j])
        {
            if (ptr->map_str[i][j] == 'C')
            {
                ft_collectible_img(ptr);
                mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, j * 50, i * 50);
                mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->collec.img, j * 50, i * 50);
                ptr->collec.img_indx++;
            }
            j++;
        }
        i++;
    }
    return (0);
}