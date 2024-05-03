/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:30:24 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/02 15:12:53 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_error(char **str)
{
	write(2, "MAP NOT VALID\n", 14);
	ft_free(str);
	exit(1);
}

static int	check_in_str(char c, int *tab)
{
	char	*str;
	int		i;

	str = "EPC01NB";
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			tab[i] += 1;
			return (0);
		}
		else if (c == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	fill_arr(t_data *ptr, int *tab)
{
	char	**map;

	int (i), (j);
	map = ptr->map_str;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_in_str(map[i][j], tab))
				ft_error(ptr->map_str);
			j++;
		}
		i++;
	}
}

void	check_double(t_data *ptr)
{
	int (tab[7]), (i);
	i = 0;
	while (i <= 6)
		tab[i++] = 0;
	fill_arr(ptr, tab);
	i = 0;
	while (i <= 5)
	{
		if (tab[i] == 0)
			ft_error(ptr->map_str);
		else if (i < 2 && tab[i] > 1)
			ft_error(ptr->map_str);
		i++;
	}
}
