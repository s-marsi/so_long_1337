/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:09:03 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/27 12:05:01 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_valid_map(char *name)
{
	size_t	len;

	len = ft_strlen(name) - 4;
	if (ft_strcmp(&name[len], ".ber"))
	{
		ft_putstr_fd("Map names should terminate with .ber\n", 1);
		exit (1);
	}
}

static void	ft_error(char **str)
{
	write(2, "MAP NOT VALID\n", 14);
	ft_free(str);
	exit(1);
}

static void	get_w_h(t_data *ptr, char **str)
{
	size_t	len;
	int		i;
	int		j;

	i = 0;
	len = ft_strlen(str[0]);
	while (str[i] != NULL)
	{
		if (i == 0 || !str[i + 1])
		{
			j = 0;
			while (str[i][j] && str[i][j] != '\n')
			{
				if (str[i][j] != '1')
					ft_error(str);
				j++;
			}
		}
		if (len != ft_strlen(str[i]) || str[i][0] != '1'
			|| str[i][len - 2] != '1')
			ft_error(str);
		i++;
	}
	ptr->size_x_map = len - 1;
	ptr->size_y_map = i;
}

static char	**map_to_str(int fd)
{
	char	*str;
	char	*buf;
	char	**return_str;

	str = NULL;
	buf = get_next_line(fd);
	while (buf)
	{
		str = ft_strjoin(str, buf);
		str = ft_strjoin(str, " ");
		free(buf);
		buf = NULL;
		buf = get_next_line(fd);
	}
	free(buf);
	return_str = ft_split(str, ' ');
	free(str);
	str = NULL;
	return (return_str);
}

char	**get_map(t_data *ptr, char *file_name)
{
	char	**return_str;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Map does not exist.\n", 2);
		exit(1);
	}
	return_str = map_to_str(fd);
	get_w_h(ptr, return_str);
	if (ptr->size_x_map == ptr->size_y_map)
		ft_error(return_str);
	return (return_str);
}
