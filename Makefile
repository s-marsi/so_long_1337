CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

LIBFT = libft/

LIBFT_NAME = libft/libft.a

FILES = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c parcing/check_images.c collectible.c \
		ft_draw.c enemy/enemy.c enemy/enemy_explosion.c enemy/enemy_animation.c helpers.c key_manager.c \
		moves/left_right_moves.c moves/up_down_moves.c moves/moves_helpers.c exit.c enemy/enemy2.c  moves/attack_moves.c\
		player/player.c parcing/map_handling.c parcing/check_double.c parcing/floodfill.c helpers2.c win.c\
		hook.c main.c

FILES_O = $(FILES:.c=.o)

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

$(NAME): $(FILES_O)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(FILES_O) $(LIBFT_NAME) -o $(NAME) $(MLX_FLAGS)

clean : 
	make clean -C $(LIBFT)
	rm -f $(FILES_O)

fclean : clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean
