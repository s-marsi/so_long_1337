CFLAGS = -Wall -Wextra -Werror

AR = ar -r

NAME = libft.a

FILES = ft_isdigit.c  ft_strlen.c ft_strcmp.c ft_strlcpy.c ft_strlcat.c \
		ft_bzero.c ft_calloc.c ft_strdup.c ft_memset.c ft_atoi.c	\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c

BONUS_FILES = ft_lstnew_bonus.c	\
			ft_lstadd_front_bonus.c	\
			ft_lstsize_bonus.c	\
			ft_lstlast_bonus.c	\
			ft_lstadd_back_bonus.c	\
			ft_lstdelone_bonus.c	\
			ft_lstclear_bonus.c	\
			ft_lstiter_bonus.c	\
			ft_lstmap_bonus.c \
			ft_putstr_fd_bonus.c

FILES_O = $(FILES:.c=.o)

BONUS_O = $(BONUS_FILES:.c=.o)

all : $(NAME) bonus

$(NAME) : $(FILES_O)
	$(AR) $(NAME) $(FILES_O)

bonus : $(BONUS_O)

$(BONUS_O): $(BONUS_FILES)
	cc $(CFLAGS) -c $(BONUS_FILES) 
	$(AR) $(NAME) $(BONUS_O)

clean :
	rm -f $(FILES_O) $(BONUS_O)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean