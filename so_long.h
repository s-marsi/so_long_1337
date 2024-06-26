/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarsi <smarsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:38:18 by smarsi            #+#    #+#             */
/*   Updated: 2024/05/07 08:51:49 by smarsi           ###   ########.fr       */
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
	int		img_indx;
	int		animation;
	int		item_eaten;
	int		speed;
}	t_img;
typedef struct s_data
{
	char	**map_str;
	char	**map_check;
	void	*mlx;
	void	*win;
	int		size_x;
	int		size_y;
	int		size_x_map;
	int		size_y_map;
	int		num_item;
	int		finish;
	int		winer;
	int		kill_all;
	int		attack;
	int		bomb;
	int		moves_number;
	t_img	img;
	t_img	player;
	t_img	enemy;
	t_img	enemy2;
	t_img	item;
	t_img	wall;
	t_img	exit;
}	t_data;
char	*get_next_line(int fd);
char	*ft_strjoin_next(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*read_all(int fd, char *last);
void	ft_free(char **s);
char	**get_map(t_data *ptr, char *file_name);
int		ft_collectible_animation(t_data *ptr, int x, int y);
void	ft_free(char **s);
void	ft_init(t_data *ptr);
int		ft_draw(t_data *ptr);
int		press_key(int keycode, t_data *ptr);
void	right_route(t_data *ptr, int *i, int *j);
void	left_route(t_data *ptr, int *i, int *j);
void	move_right(t_data *ptr, int x, int y, int flag);
void	move_left(t_data *ptr, int x, int y, int flag);
void	move_up(t_data *ptr, int x, int y, int flag);
void	move_down(t_data *ptr, int x, int y, int flag);
void	ft_destroy_all(t_data *ptr, int flag, int fd);
int		is_enemy(t_data *ptr, int x, int y);
void	ft_exit(t_data *ptr, int i, int j);
void	ft_exit_animation(t_data *ptr, int x, int y);
void	bombe_animation(t_data *ptr, int i, int j);
void	ft_enemy_bombe(t_data *ptr, int i, int j);
char	*make_path(int nb, char *path);
void	ft_player_animation(t_data *ptr, int i, int j, int flag);
char	*make_path(int nb, char *path);
char	*ft_strjoin2(char *s1, char *s2);
void	ft_collectible_img(t_data *ptr);
int		check_access(char *path);
void	check_images(void);
void	is_valid_map(char *name);
void	flood_fill(t_data *ptr);
void	ft_enemy_animation(t_data *ptr, int i, int j, char c);
void	check_double(t_data *ptr);
void	print_moves(t_data *ptr);
void	attack_right(t_data *ptr, int x, int y);
void	attack_left(t_data *ptr, int x, int y);
void	call_img(t_data *ptr, char *path, int i);
void	ft_win(t_data *ptr);
void	ft_lose(t_data *ptr);
void	game_over(t_data *ptr, int x, int y);
void	game_over_two(t_data *ptr, int x, int y);
int		close_key(int keycode, t_data *ptr);
void	lose_bomb(t_data *ptr, int i, int j);
int		check_finish(t_data *ptr);
void	display_img(t_data *ptr, void *img, int i, int j);
void	count_item(t_data *ptr);
int		enemy_speed(t_data *ptr);
void	enemy_right(t_data *ptr);
void	enemy_left(t_data *ptr);
void	enemy_right2(t_data *ptr);
void	enemy_left2(t_data *ptr);
int		check_no_enemy(t_data *ptr);
void	ft_enemy_bombe2(t_data *ptr, int i, int j);
void	attack_enemy(t_data *ptr, int x, int y);
void	check_img(t_data *ptr, void *img);
void	is_enemy2(t_data *ptr, int x, int y);
void	lose_win(t_data *ptr);
void	player_draw(t_data *ptr, int i, int j);
void	exit_draw(t_data *ptr, int i, int j);
void	enemy_draw(t_data *ptr, int i, int j);
void	collection_draw(t_data *ptr, int i, int j);
int		moves_speed(t_data *ptr);
#endif
