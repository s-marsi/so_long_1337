CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

LIBFT = libft/

LIBFT_NAME = libft/libft.a

FILES = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c main.c collectible.c

FILES_O = $(FILES:.c=.o)

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit


$(NAME): $(FILES)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $? $(LIBFT_NAME) -o $(NAME) $(MLX_FLAGS)

clean : 
	make clean -C $(LIBFT)
	rm -f $(FILES_O)

fclean : clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY : clean fclean
