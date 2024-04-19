/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:30:12 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/17 14:30:24 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    press_key(int keycode, t_data *ptr)
{
    int x;
    int y;

    x = ptr->player.pos_x;
    y = ptr->player.pos_x;
    printf("pressed key is : %d\n", keycode);
    // if (keycode == 53) 
    //     ft_destroy_all(ptr, 1);
    // else if (keycode == 0 || keycode == 2 || keycode == 13 || keycode == 1)
    //     new_image(ptr, keycode);
    // else if (keycode == 2)
    //     new_image(ptr, keycode);
    // else if (keycode == 13 && !(ptr->map_str[y - 1][x] == 'C' || ptr->map_str[y - 1][x] == '1'))
    //     new_image(ptr, keycode);
    // else if (keycode == 1 && !(ptr->map_str[y + 1][x] == 'C' || ptr->map_str[y + 1][x] == '1'))
    //     new_image(ptr, keycode);
    return (0);
}