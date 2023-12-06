# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 18:09:28 by pfalasch          #+#    #+#              #
#    Updated: 2023/12/05 16:22:28 by mcoppola         ###   ########.fr        #
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
		sources/utilities/00_utils.c \
		sources/tokens/00_token_init_count.c \
		sources/tokens/01_token_in_array.c \
		sources/tokens/02_single_token_matrix.c \
		sources/tokens/03_count_words.c \
		sources/tokens/04_expander.c \
		sources/initialize/init.c \
		sources/error/00_verify_readline.c \
		sources/error/01_error_quotes.c \
		sources/error/02_error_start_last.c \
		sources/error/03_error_mixed.c \
		sources/error/04_error_messages.c \
		sources/error/05_wrong_dollar.c \
		sources/free/00_free.c \
		sources/Commands/builtin.c \
		sources/Commands/export.c \
		sources/executer/pipe.c \
		sources/parser/parser.c \
		#sources/parser/lexer.c \
		#sources/expander/00_expander.c \



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
