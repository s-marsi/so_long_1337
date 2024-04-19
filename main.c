/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:45:25 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/17 22:15:23 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_w_h(t_data *ptr, char **str)
{
    unsigned int len;
    int i;
    int j;

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
                    write(2, "MAP NOT VALID\n", 14), ft_free(str), exit(1);
                j++;
            }
        }
        if (len != ft_strlen(str[i]) || str[i][0] != '1' || str[i][len - 2] != '1')
            write(2, "MAP NOT VALID\n", 14), ft_free(str), exit(1);
        i++;
    }
    ptr->size_x = len - 1;
    ptr->size_y = i;
}

char    **get_map(t_data *ptr, char *file_name)
{
    char    *str;
    char    *buf;
    char    **return_str;
    int     fd;

    (void) ptr;
    str = NULL;
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        write(2, "MAP NOT FOUND\n", 14), exit(1);
    while ((buf = get_next_line(fd)))
    {
        str = ft_strjoin(str, buf);
        str = ft_strjoin(str, " ");
        free(buf);
        buf = NULL;
    }
    return_str = ft_split(str, ' ');
    free(buf), free(str), str = NULL;
    get_w_h(ptr, return_str);
    return (return_str);
}

int ft_draw(t_data *ptr)
{
    int i;
    int j;

    i = 0;
    while (ptr->map_str[i])
    {
        j = 0;
        while (ptr->map_str[i][j])
        {
            if (ptr->map_str[i][j] == '0')
                mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, j * 50, i * 50);
            else if (ptr->map_str[i][j] == 'P')
            {
                mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, j * 50, i * 50);
                mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.img, j * 50, i * 50);
                ptr->player.pos_x = j;
                ptr->player.pos_y = i;
            }
            else if (ptr->map_str[i][j] == '1')
                mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall.img, j * 50, i * 50);
            else if (ptr->map_str[i][j] == 'E')
            {
                mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, j * 50, i * 50);
                mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->enemy.img, j * 50, i * 50); 
            }
            j++;
        }
        i++;
    }
    return (0);
}


void    create_windows(t_data *ptr)
{
    ptr->mlx = mlx_init();
    ptr->win = mlx_new_window(ptr->mlx, ptr->size_x  * 50, ptr->size_y * 50, "SO_LONG");
    if (!ptr->win)
    {
        free(ptr->mlx); 
        ft_free(ptr->map_str);
        write(2, "Error : windows failed\n", 23); exit (1);
    }
    ft_init(ptr);
    ft_draw(ptr);
    mlx_key_hook(ptr->win, press_key, ptr);
    mlx_loop_hook(ptr->mlx, ft_collectible_animation, ptr);
    // mlx_loop_hook(ptr->mlx, ft_enemy_animation, ptr);
    mlx_loop(ptr->mlx);
}

int main(int ac, char *av[])
{
    t_data  ptr;
    if (ac < 2)
        exit(-1);
    ptr.map_str = get_map(&ptr, av[1]);
    create_windows(&ptr); 
    return (0);
}