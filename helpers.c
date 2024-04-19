/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:24:40 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/17 16:55:41 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		s[i++] = NULL;
	}
	free(s);
	s = NULL;
}

void    ft_destroy_all(t_data *ptr, int flag)
{
    if (flag == 0)
        printf("YOU LOSE :(\n");
    else
        printf("YOU WON :)\n");
    mlx_destroy_image(ptr->mlx, ptr->img.img);
    mlx_destroy_image(ptr->mlx, ptr->player.img);
    mlx_destroy_image(ptr->mlx, ptr->wall.img);
    mlx_destroy_image(ptr->mlx, ptr->enemy.img);
    mlx_destroy_image(ptr->mlx, ptr->item.img);
    mlx_destroy_window(ptr->mlx, ptr->win);
	//mlx_destroy_display(ptr->mlx);
    free(ptr->mlx); ft_free(ptr->map_str);
    exit(0);
}


void    ft_init(t_data *ptr)
{
    ptr->player.right = 0;
    ptr->player.left = -1;
    ptr->player.up = -1;
    ptr->player.down = -1;
    ptr->item.img_indx = 0;
     ptr->enemy.right = 0;
    ptr->enemy.left = -1;
      // ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/brow1.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/blue2.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/gazo.xpm", &ptr->size_x, &ptr->size_y);
    ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/brow2.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/yellow.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "./images/wall/gray.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "./images/wall/red.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "./images/wall/rock.xpm", &ptr->size_x, &ptr->size_y);
    ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "./images/wall/stone_green.xpm", &ptr->size_x, &ptr->size_y);
    ptr->item.img = mlx_xpm_file_to_image(ptr->mlx, "./images/collection/0.xpm", &ptr->size_x, &ptr->size_y);
    ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/player_sprite/right/0.xpm", &ptr->size_x, &ptr->size_y);
    ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/0.xpm", &ptr->size_x, &ptr->size_y);
}