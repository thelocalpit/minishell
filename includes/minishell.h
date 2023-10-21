/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:16:54 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/19 19:01:48 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

// libs

# include "../libft/libft.h"
# include <dirent.h>
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

//global variable

extern int	g_value;




// colors

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define YELLOW "\033[0;33m"
# define CYAN "\033[0;36m"
# define GREEN_BOLD "\033[1;32m"
# define RED_BOLD "\033[1;31m"
# define YELLOW_BOLD "\033[1;33m"
# define CYAN_BOLD "\033[1;36m"
# define RESET "\033[0m"
# define BLUE_BOLD "\033[1;34m"

// variables

# define PATH_MAX 1024


/* ------------------------  ERRORS   ---------------------------------- */

# define ERROR_UNCLOSED "minishell : syntax error unclosed quotes\n"

/* ------------------------  STRUCTS  ---------------------------------- */

/* ------------------------  STRUCTS  ---------------------------------- */

typedef struct s_attr
{
	int	i;
	//------- n di token -------------------
	int	nb_tokens;
	char **split_arr;
	char **cmd_arr;
	//------ n elements of cmds -------------
	char **matrix_single_cmd;
	int i_matrix_token;
} t_attr;

typedef struct s_token
{
	char *token;
	int nb_elements_toki;
} t_token;

	/* ------------------------  FUNCTIONS ---------------------------------- */

	// init_folder

	void
	init_parameters(t_attr *att, char **envp);
void	init_attributes(t_attr *att);
void	reinit_parameters(t_attr *att, char **envp);

// signals_folder

void handle_interrupt(int sig);
void	set_signals(void);

//tokens_folder

	// 00_token_init_count.c

char 	**split_init(char *s, t_attr *att);
int count_tokens(char *s, t_attr *att);
int process_special_token(t_attr *att, char *s, int i);

	// 01_token_in_array.c

void create_array(char *s, t_attr *att);
char *get_token(char *s);
void check_next_special_token(char *s, int i, char **token);

// utilities_folder

// prompt.c
char *prompt(void);

// signals.c
void	set_signals(void);
void	handle_interrupt(int sig);

//error
	
	//error_01.c
int		verify_readline(char *s);
int		error_single_quote(char *s);
int		error_double_quote(char *s);

// debugg.c

void	ft_print_array(char **array);

#endif
