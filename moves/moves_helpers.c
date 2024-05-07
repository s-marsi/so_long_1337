/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:57:14 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 08:59:03 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_moves(t_data *ptr)
{
	char	*tmp;
	char	*str;

	tmp = ft_itoa(ptr->moves_number);
	str = ft_strjoin2("moves : ", tmp);
	mlx_string_put(ptr->mlx, ptr->win, 25, 15, 0x00FF0000, str);
	free(tmp);
	free(str);
}

void	is_enemy2(t_data *ptr, int x, int y)
{
	if (ptr->map_str[y][x] == 'N' || ptr->map_str[y][x] == 'n'
	|| ptr->map_str[y][x] == 'B')
		ptr->map_str[y][x] = 'R';
}

int	moves_speed(t_data *ptr)
{
	int	n;

	n = 12;
	if (ptr->size_y_map >= 25 || ptr->size_x_map >= 50)
		n = 3;
	return (n);
}
