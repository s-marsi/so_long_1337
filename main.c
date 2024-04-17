/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:45:25 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/17 14:20:36 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		free(s[i]);
		s[i++] = NULL;
	}
	free(s);
	s = NULL;
}

void    ft_destroy_all(t_data *ptr, int flag)
{
    if (flag == 0)
        printf("YOU LOSE :(\n");
    else
        printf("YOU WON :)\n");
    mlx_destroy_image(ptr->mlx, ptr->img.img);
    mlx_destroy_image(ptr->mlx, ptr->player.img);
    mlx_destroy_image(ptr->mlx, ptr->wall.img);
    mlx_destroy_image(ptr->mlx, ptr->enemy.img);
    mlx_destroy_image(ptr->mlx, ptr->collec.img);
    mlx_destroy_window(ptr->mlx, ptr->win);
	//mlx_destroy_display(ptr->mlx);
    free(ptr->mlx); ft_free(ptr->map_str);
    exit(0);
}

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

void    ft_init(t_data *ptr)
{
    ptr->player.right = 0;
    ptr->player.left = -1;
    ptr->player.up = -1;
    ptr->player.down = -1;
    ptr->collec.img_indx = 0;
}

void    ft_init_images(t_data *ptr)
{
    // ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/brow1.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/blue2.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/gazo.xpm", &ptr->size_x, &ptr->size_y);
    ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/brow2.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->img.img = mlx_xpm_file_to_image(ptr->mlx, "./images/background/yellow.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "./images/wall/gray.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "./images/wall/red.xpm", &ptr->size_x, &ptr->size_y);
    // ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "./images/wall/rock.xpm", &ptr->size_x, &ptr->size_y);
    ptr->wall.img = mlx_xpm_file_to_image(ptr->mlx, "./images/wall/stone_green.xpm", &ptr->size_x, &ptr->size_y);
    ptr->collec.img = mlx_xpm_file_to_image(ptr->mlx, "./images/collection/0.xpm", &ptr->size_x, &ptr->size_y);
    ptr->player.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/player_sprite/right/0.xpm", &ptr->size_x, &ptr->size_y);
    ptr->enemy.img = mlx_xpm_file_to_image(ptr->mlx, "./images/player/enemy/right/0.xpm", &ptr->size_x, &ptr->size_y);
}

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
            // else if (ptr->map_str[i][j] == 'C')
            // {
            //     mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img.img, j * 50, i * 50);
            //     mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->collec.img, j * 50, i * 50);
            // }
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
    ft_init_images(ptr);
    ft_draw(ptr);
    mlx_key_hook(ptr->win, press_key, ptr);
    mlx_loop_hook(ptr->mlx, ft_collectible_animation, ptr);
    mlx_loop(ptr->mlx);
}

int main(int ac, char *av[])
{
    t_data  ptr;
    if (ac < 2)
        exit(-1);
    ft_init(&ptr);
    ptr.map_str = get_map(&ptr, av[1]);
    create_windows(&ptr); 
    return (0);
}