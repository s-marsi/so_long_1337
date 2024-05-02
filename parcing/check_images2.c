/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 08:34:44 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/02 08:36:13 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_access(char *path)
{
	if (access(path, R_OK) == -1)
	{
		free(path);
		ft_putstr_fd("Error : Image not found\n", 2);
		exit (1);
	}
	free(path);
	path = NULL;
	return (0);
}
