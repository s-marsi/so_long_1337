/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:57:14 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/01 06:13:34 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_moves(t_data *ptr)
{
	ptr->moves_number++;
	ft_putstr_fd("MOVES : ", 1);
	ft_putnbr_fd(ptr->moves_number, 1);
	ft_putstr_fd("\n", 1);
}

void	print_moves2(t_data *ptr)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(ptr->moves_number);
	str = ft_strjoin2("moves : ", tmp);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, 2 * 50, 0);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall.img, 2 * 50, 0);
	mlx_string_put(ptr->mlx, ptr->win, 25, 15, 0x00FF0000, str);
	free(tmp);
	free(str);
}
