# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 18:09:28 by pfalasch          #+#    #+#              #
#    Updated: 2023/11/08 15:47:20 by pfalasch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASIC
CC = cc -g
CSANI = cc -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
RLFLAG = -lreadline
RM = rm -rf

# LIBFT
LIBFT = ./libft/libft.a

# COLORS
RESET			:= \033[0m
GREEN			=	\e[32m
CYAN			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m
RED				:= \033[1;31m
BOLD			:= \033[1;1m


#MINISHELL
NAME = minishell
SRC =	sources/minishell.c \
		sources/utilities/signals.c \
		sources/utilities/prompt.c \
		sources/utilities/debugg.c \
		sources/tokens/00_token_init_count.c \
		sources/tokens/01_token_in_array.c \
		sources/tokens/02_single_token_matrix.c \
		sources/tokens/02_a_count_words.c \
		sources/initialize/init.c \
		sources/error/error_01.c \
		sources/free/00_free.c \
		sources/Commands/builtin.c \
		

OBJSDIR = objects
OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))

# MAKE RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)
	echo "Everything Done!"
 
sani: re $(OBJ)
	$(MAKE) -C ./libft
	$(CSANI) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)
	echo "Compiled with fsanitizer"

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE)	clean -C ./libft

fclean: clean
	$(RM) $(NAME) $(SANI) $(OBJSDIR)
	$(MAKE) fclean -C ./libft
	echo "Everything Deleted..."

re: fclean all

.PHONY: all clean fclean re