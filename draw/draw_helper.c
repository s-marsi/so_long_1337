/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 07:24:56 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 08:17:54 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	lose_win(t_data *ptr)
{
	if (check_no_enemy(ptr) && ptr->finish >= 100 && !ptr->winer)
		ft_lose(ptr);
	else if (check_no_enemy(ptr) && ptr->finish >= 100 && ptr->winer == 2)
		ft_win(ptr);
}

void	player_draw(t_data *ptr, int i, int j)
{
	if (ptr->winer == 1)
		ft_exit_animation(ptr, i, j);
	else if (ptr->bomb == 1)
		ft_enemy_bombe(ptr, i, j);
	else if (ptr->attack)
	{
		press_key(3, ptr);
		display_img(ptr, ptr->player.img, i, j);
	}
	else
		ft_player_animation(ptr, i, j, 0);
}

void	exit_draw(t_data *ptr, int i, int j)
{
	char	c;

	c = ptr->map_str[i][j];
	if (ptr->bomb == 1)
		ptr->player.item_eaten = 0;
	ft_exit(ptr, i, j);
}

void	enemy_draw(t_data *ptr, int i, int j)
{
	char	c;

	c = ptr->map_str[i][j];
	if (ptr->kill_all == 1)
		ft_enemy_bombe2(ptr, i, j);
	else if (c == 'N' || c == 'n')
		ft_enemy_animation(ptr, i, j, c);
	else if (c == 'B')
		bombe_animation(ptr, i, j);
}

void	collection_draw(t_data *ptr, int i, int j)
{
	char	c;

	c = ptr->map_str[i][j];
	if (ptr->bomb == 1)
		ptr->map_str[i][j] = '0';
	ft_collectible_animation(ptr, i, j);
}
