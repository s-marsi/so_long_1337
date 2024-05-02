/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:24:40 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/01 11:41:57 by smarsi           ###   ########.fr       */
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

void	blow_up(t_data *ptr, int i, int j)
{
	static int	index;
	char		*path;

	if (ptr->enemy.img_indx == 9)
		ptr->enemy.img_indx = 0;
	index++;
	if (index % 20000 == 0)
	{
		path = make_path(ptr->enemy.img_indx, "./images/player/enemy/attack/");
		ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, path, \
		&ptr->size_x, &ptr->size_y);
		ptr->enemy.img_indx++;
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->img.img, j * 50, i * 50);
		mlx_put_image_to_window(ptr->mlx, ptr->win, \
		ptr->enemy.img, j * 50, i * 50);
		mlx_destroy_image(ptr->mlx, ptr->enemy.img);
	}
}

void	ft_destroy_all(t_data *ptr, int flag, int fd)
{
	if (flag == 1)
		ft_putstr_fd("YOU LOSE :(\n", fd);
	else if (flag == 0)
		ft_putstr_fd("YOU WIN :(\n", fd);
	ft_putstr_fd("Thanks for playing!\n", fd);
	mlx_clear_window(ptr->map_str, ptr->win);
	mlx_destroy_window(ptr->mlx, ptr->win);
	free(ptr->mlx);
	ft_free(ptr->map_str);
	exit(0);
}

static void	ft_init_images(t_data *ptr)
{
	ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/background/green_2.xpm", &ptr->size_x, &ptr->size_y);
	ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/wall/stone.xpm", &ptr->size_x, &ptr->size_y);
	ptr->item.img = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/collection/0.xpm", &ptr->size_x, &ptr->size_y);
	ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/player/player_sprite/down/0.xpm", &ptr->size_x, &ptr->size_y);
	ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/player/enemy/right/0.xpm", &ptr->size_x, &ptr->size_y);
	ptr->enemy2.img = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/player/enemy4/0.xpm", &ptr->size_x, &ptr->size_y);
	ptr->exit.img = mlx_xpm_file_to_image(ptr->mlx, \
	"./textures/exit/0.xpm", &ptr->size_x, &ptr->size_y);
}

void	ft_init(t_data *ptr)
{
	ptr->item.img_indx = 0;
	ptr->player.img_indx = 0;
	ptr->enemy.img_indx = 0;
	ptr->enemy2.img_indx = 0;
	ptr->bomb = 0;
	ptr->player.animation = 0;
	ptr->player.item_eaten = 0;
	ptr->num_item = 0;
	ptr->finish = 0;
	ptr->kill_all = 0;
	ptr->moves_number = 0;
	ptr->attack = 0;
	ft_init_images(ptr);
}
