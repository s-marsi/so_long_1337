/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:45:25 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/03 09:54:01 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_windows(t_data *ptr)
{
	ptr->mlx = mlx_init();
	if (!ptr->mlx)
	{
		ft_free(ptr->map_str);
		write(2, "Error : mlx failed\n", 19);
		exit (1);
	}
	ptr->win = mlx_new_window(ptr->mlx, ptr->size_x_map * 50, \
	ptr->size_y_map * 50, "SO_LONG");
	if (!ptr->win)
	{
		free(ptr->mlx);
		ft_free(ptr->map_str);
		write(2, "Error : windows failed\n", 23);
		exit (1);
	}
	ft_init(ptr);
	ft_draw(ptr);
	mlx_hook(ptr->win, 2, 0, press_key, ptr);
	mlx_hook(ptr->win, 17, 0, close_key, ptr);
	mlx_loop_hook(ptr->mlx, ft_collectible_animation, ptr);
	ft_putstr_fd("MOVES : ", 1);
	ft_putnbr_fd(ptr->moves_number, 1);
	ft_putstr_fd("\n", 1);
	mlx_loop(ptr->mlx);
}

int	main(int ac, char *av[])
{
	t_data	ptr;

	if (ac < 2)
		exit(1);
	check_images();
	is_valid_map(av[1]);
	ptr.map_str = get_map(&ptr, av[1]);
	check_double(&ptr);
	ptr.map_check = get_map(&ptr, av[1]);
	flood_fill(&ptr);
	create_windows(&ptr);
	return (0);
}
