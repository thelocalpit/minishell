# BASIC
CC = cc -g
CSANI = cc -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
RLFLAG = -lreadline
RM = rm -rf

# COLORS
RESET			:= \033[0m
GREEN			=	\e[32m
CYAN			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m
RED				:= \033[1;31m
BOLD			:= \033[1;1m

#MINIHELL
NAME = minishell
SRC =	sources/minishell.c \
		sources/utils/signals00.c \
		sources/utils/signals01.c \
		sources/utils/prompt00.c \
		sources/utils/utils00.c \
		sources/utils/utils01.c \
		sources/utils/utils02.c \
		sources/utils/utils03.c \
		sources/tokens/00-init-token-count.c \
		sources/tokens/01-token-array.c \
		sources/tokens/02-matrix-single-token.c \
		sources/tokens/02a-custom-itoa.c \
		sources/tokens/02b-custom-strlen.c \
		sources/tokens/02c-word-copy.c \
		sources/tokens/02d-word-copy-2.c \
		sources/tokens/03-words-count.c \
		sources/tokens/04-expander.c \
		sources/initialize/init.c \
		sources/error/00-check-readline.c \
		sources/error/01-quotes-error.c \
		sources/error/begin-error-2.c \
		sources/error/02-last-start-error.c \
		sources/error/03-mixed-error.c \
		sources/error/03b-mixed-error.c \
		sources/error/04-messages-error.c \
		sources/error/04b-messages-error.c \
		sources/error/05-wrong-dollar-error.c \
		sources/error/05b-wrong-dollar-error.c \
		sources/error/06-wrong-dollar-2.c \
		sources/free/free00.c \
		sources/builtin/env-echo-pwd-cd.c \
		sources/builtin/builtin_exec.c \
		sources/builtin/export.c \
		sources/builtin/var.c \
		sources/builtin/unsetexit.c \
		sources/exec/ecxeve00.c \
		sources/exec/exec00.c \
		sources/exec/pipe00.c \
		sources/exec/read_file00.c \
		sources/exec/redir00.c \
		sources/exec/redirections00.c \
		sources/parser/parser00.c \
		sources/libft/ft_atoi.c \
		sources/libft/ft_calloc.c \
		sources/libft/ft_isascii.c \
		sources/libft/ft_isdigit.c \
		sources/libft/ft_lstadd_back.c \
		sources/libft/ft_lstlast.c \
		sources/libft/ft_lstnew.c \
		sources/libft/ft_lstsize.c \
		sources/libft/ft_putstr_fd.c \
		sources/libft/ft_split.c \
		sources/libft/ft_strchr.c \
		sources/libft/ft_strdup.c \
		sources/libft/ft_strjoin.c \
		sources/libft/ft_strlen.c \
		sources/libft/ft_strncmp.c \
		sources/libft/ft_strtrim.c \
		sources/libft/ft_substr.c



OBJSDIR = objects
OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))

# MAKE RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(RLFLAG) -o $(NAME)
	@echo "Everything Done!"

sani: re $(OBJ)
	$(CSANI) $(CFLAGS) $(OBJ) $(RLFLAG) -o $(NAME)
	echo "Compiled with fsanitizer"

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(SANI) $(OBJSDIR)
	echo "Everything Deleted..."

re: fclean all

.PHONY: all clean fclean re
