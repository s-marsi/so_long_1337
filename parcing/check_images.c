/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:22:06 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 06:54:38 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_access2(char *path)
{
	if (access(path, F_OK) == -1)
	{
		ft_putstr_fd("Error : Image not found\n", 2);
		exit (1);
	}
	return (0);
}

static void	enemy_2_images(void)
{
	char	*path;
	int		i;

	i = 0;
	while (i <= 9)
	{
		path = make_path(i, "./textures/player/enemy/angry/attack/");
		check_access(path);
		if (i < 2)
		{
			path = make_path(i, "./textures/player/enemy/angry/left/");
			check_access(path);
			path = make_path(i, "./textures/player/enemy/angry/right/");
			check_access(path);
		}
		i++;
	}
}

static void	enemy_images(void)
{
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	while (i <= 9)
	{
		path = make_path(i, "./textures/player/enemy/attack/");
		check_access(path);
		path = make_path(i, "./textures/player/enemy4/");
		check_access(path);
		if (i <= 2)
		{
			path = make_path(i, "./textures/player/enemy/left/");
			check_access(path);
			path = make_path(i, "./textures/player/enemy/right/");
			check_access(path);
		}
		i++;
	}
}

static void	coll_exit_images(void)
{
	char	*path;
	char	*path2;
	int		i;

	i = 0;
	path = NULL;
	while (i <= 5)
	{
		path = make_path(i, "./textures/collection/");
		check_access(path);
		path2 = make_path(i, "./textures/win/");
		check_access(path2);
		i++;
	}
	i = 0;
	while (i <= 2)
	{
		path = make_path(i, "./textures/exit/");
		check_access(path);
		path2 = make_path(i, "./textures/player/enemy4/dead/");
		check_access(path2);
		i++;
	}
}

void	check_images(void)
{
	check_access2("./textures/background/green_2.xpm");
	check_access2("./textures/wall/stone.xpm");
	enemy_images();
	enemy_2_images();
	coll_exit_images();
}
