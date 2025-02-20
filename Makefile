NAME =		cub3d

CC = 		cc
CFLAGS = 	-Wall -Wextra -Werror #-g3 -fsanitize=address

SRC = 		cub3d.c ft_putstr_fd.c get_next_line.c get_next_line_utils.c ft_memset.c ft_strcmp.c ft_split.c \
 			ft_strncmp.c ft_strrchr.c ft_atoi.c 


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY :