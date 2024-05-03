/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 10:02:14 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/03 09:36:38 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	change_map(t_data *ptr, int i, int j)
{
	int	len_i;
	int	len_j;

	len_i = ptr->size_y_map;
	len_j = ptr->size_x_map;
	if (i < 0 || j < 0 || i >= len_i || j >= len_j
		|| ptr->map_check[i][j] == '1' || ptr->map_check[i][j] == '2')
		return ;
	else if (ptr->map_check[i][j] == 'E')
	{
		ptr->map_check[i][j] = '2';
		return ;
	}
	else
	{
		ptr->map_check[i][j] = '2';
		change_map(ptr, i, j + 1);
		change_map(ptr, i, j - 1);
		change_map(ptr, i + 1, j);
		change_map(ptr, i - 1, j);
	}
}

void	check_map(t_data *ptr)
{
	int	i;
	int	j;

	i = 0;
	while (ptr->map_check[i])
	{
		j = 0;
		while (ptr->map_check[i][j])
		{
			if (ptr->map_check[i][j] == 'C' || ptr->map_check[i][j] == 'E')
			{
				ft_free(ptr->map_check);
				ft_putstr_fd("player cannot eat all items or exit.\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	get_player_position(t_data *ptr, int *x, int *y)
{
	int	i;
	int	j;

	i = *x;
	j = *y;
	while (ptr->map_check[i])
	{
		j = 0;
		while (ptr->map_check[i][j])
		{
			if (ptr->map_check[i][j] == 'P')
				break ;
			j++;
		}
		if (ptr->map_check[i][j] == 'P')
			break ;
		i++;
	}
	*x = i;
	*y = j;
}

void	flood_fill(t_data *ptr)
{
	int (i), (j);
	i = 0;
	get_player_position(ptr, &i, &j);
	change_map(ptr, i, j);
	check_map(ptr);
}
