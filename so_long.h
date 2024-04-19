/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:38:18 by smarsi            #+#    #+#             */
/*   Updated: 2024/04/17 18:58:23 by smarsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include "libft/libft.h"
# include <mlx.h>

typedef struct s_img
{
	void	*img;
	int		pos_x;
	int		pos_y;
	int		right;
	int		left;
	int		up;
	int		down;
	int		img_indx;
}	t_img;
typedef struct s_data
{
	char	**map_str;
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	t_img	img;
	t_img	player;
	t_img	enemy;
	t_img	item;
	t_img	wall;
}	t_data;
char	*get_next_line(int fd);
char	*ft_strjoin_next(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*read_all(int fd, char *last);
void	ft_free(char **s);
int		ft_collectible_animation(t_data *ptr);
void	ft_free(char **s);
void	ft_destroy_all(t_data *ptr, int flag);
void	ft_init(t_data *ptr);
int		press_key(int keycode, t_data *ptr);
int		ft_collectible_animation(t_data *ptr);
int	ft_enemy_animation(t_data *ptr, int i, int j);

#endif
