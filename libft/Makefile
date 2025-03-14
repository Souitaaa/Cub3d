# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhobba <akhobba@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 09:51:36 by akhobba           #+#    #+#              #
#    Updated: 2025/03/10 03:34:20 by akhobba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

############################################
#⠀⠀⠀⠀⠀⠀⠀⢀⡾⣇⠀⠀⠀⠀⠀⠀⢀⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⢸⡇⠻⣦⡀⠀⣀⣤⣀⣾⢯⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠈⣧⠳⣽⣷⡞⢿⠿⠾⠿⢯⣘⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⢈⣷⠟⠉⢷⠀⣿⣦⣄⠀⠈⠳⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⢠⣾⠟⠀⠀⠈⠳⠋⣿⠈⢳⡀⠀⠘⡍⠳⢄⡀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⣠⠴⣻⠏⠀⠀⠀⠀⠀⢀⠸⠇⠀⢻⣸⣷⣽⣀⠀⠙⢦⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠐⠾⣇⣼⡏⠀⠀⠀⠀⣴⣾⣿⣤⣤⠤⠟⢻⣷⡉⠙⠛⢀⡈⢷⡀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⢹⣿⠀⠀⠀⠀⠀⠿⣿⣿⣿⠃⠀⣠⡀⠙⢷⡄⠀⠀⠙⣶⣿⣦⣤⣤⠴	#
#⠀⠀⠀⠀⠀⣼⡟⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⡴⠋⣇⠀⠀⠈⠃⠀⠀⠸⣇⠉⠉⠁	#⠀
#⠀⠀⠀⢀⣾⠟⠀⠀⠀⢀⣤⠴⠛⠁⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⣴⣄⠀⣿⡄⠀⠀	#	⠀
#⠀⠀⣠⣿⠏⠀⣀⣴⠞⠉⠀⠀⠀⠀⠀⠀⠀⠀⢀⡿⠀⠀⠀⢀⣿⣿⢷⣸⡇⠀⠀	#⠀
#⢠⣾⡟⠁⢀⡘⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠃⠀⢰⡆⢸⣿⡿⠀⢿⡇⠀⠀	#⠀
#⣼⣿⣇⢰⡿⠿⡾⡗⠀⠀⠀⠀⣠⣤⣶⣶⡿⠟⠁⠀⠀⣸⠃⣸⣿⡇⠀⢸⡇⠀⠀	#⠀
#⠧⣿⡏⠈⣳⠴⣃⣴⣶⣄⣴⣿⡿⠋⠉⠁⠀⠀⠀⠀⣠⡿⠀⢿⣿⠁⠀⠸⠃⠀⠀	#⠀
#⠀⠻⣧⣠⣼⠞⠉⡽⠛⠉⢰⡿⠁⠀⠀⠀⠀⠀⢀⣴⡿⠁⠀⢸⣿⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠈⠓⠶⠶⠛⠁⠀⠀⣾⣷⡟⠀⠀⠀⠀⣠⣿⠟⠁⠀⢠⠘⣿⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠏⣧⠄⠀⠀⣾⣿⠋⠀⠀⠀⣾⠳⣻⡇⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⠀⣿⠀⠀⢸⣿⡇⣴⣾⡆⢰⣿⠀⠙⢿⡄⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢧⢸⡄⠀⢸⣿⣿⡟⢸⣷⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢷⠀⢸⣿⣿⠁⢸⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⠈⣿⣿⠀⠸⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢧⢻⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
#⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀	#⠀
############################################

NAME		=	libft.a
CC			=	cc
CFLAGS 		=	-Wall -Wextra -Werror
INCLUDES	=	headers
OBJDIR		=	obj
SRCDIR		=	src
AR			=	ar csr
RED			=	\e[1;31m
GREEN		=	\e[1;32m
YELLOW		=	\e[3;33m
CYAN		=	\e[3;96m
END			=	\e[0m
RM			=	rm -rf

SRC	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
			ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c

B_SRC	=	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c \
				ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ			=	$(patsubst %.c, $(OBJDIR)/%.o, $(SRC))
B_OBJ		=	$(patsubst %.c, $(OBJDIR)/%.o, $(B_SRC))

all : $(NAME) bonus

$(NAME):	$(OBJ)
	@echo "\e[K\r$(GREEN)Mandatory part is done!$(END)"

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)/libft.h
	@mkdir -p $(OBJDIR)
	@echo -n "$(CYAN)Compiling $(notdir $<)...$(END)\e[K\r"
	@${CC} ${CFLAGS} -c $< -I$(INCLUDES) -o $@ > /dev/null
	@echo -n "$(YELLOW)Inserting $(notdir $@) to $(NAME)...$(END)\e[K\r"
	@${AR} $(NAME) $@ > /dev/null

bonus : ${B_OBJ}
	@echo "\e[K\r$(GREEN)Bonus part is done!$(END)"


clean :
	@echo "$(RED)Cleaning $(OBJDIR)...$(END)"
	@${RM} $(OBJDIR)

fclean : clean
	@echo "$(RED)Cleaning $(NAME)...$(END)"
	@${RM} $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus