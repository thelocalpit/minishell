/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesac <alesac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:16:54 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/08 16:35:55 by alesac           ###   ########.fr       */
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

# define PATH_MAX 4096


/* ------------------------  ERRORS   ---------------------------------- */

# define ERROR_UNCLOSED "minishell : syntax error unclosed quotes\n"

/* ------------------------  STRUCTS  ---------------------------------- */

/* ------------------------  STRUCTS  ---------------------------------- */

typedef struct s_attr
{
	//------- n di token -------------------
	int	nb_tokens;
	char **split_arr;
	int y;
	int x;
	char **arr2;
	int y2;
	int x2;
	//------ cmds -------------
	int count;
	//----- token variables ---------
	int count_words;
	int flag_cmd_valid;
	int flag_quote;
	//------ errors -------------------
	int flag_err_quote;
} t_attr;


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

void split_init(char *s, t_attr *att);
int count_tokens(char *s, t_attr *att);
int process_special_token(t_attr *att, char *s, int i);

	// 01_token_in_array.c

void create_array(char *s, t_attr *att);
char *get_token(char *s);
void check_next_special_token(char *s, int i, char **token);

	//02_single_token_matrix.c
void get_cmd_matrix(char *s, t_attr *att);
void create_matrix_cmd(char *s, t_attr *att);
char *get_cmd_token(char *s, t_attr *att);
void check_cmd_tokens(char *s, t_attr *att);
int ft_strlen_custom(char *s, int flag);
char *ft_write_word(char *s, t_attr *att, int flag, int i);

// 02_a_count_words.c
int check_single_quotes(char *s, int len, int i, t_attr *att);
int check_double_quotes(char *s, int len, int i, t_attr *att);
int check_no_space(char *s, int len, int i, t_attr *att);
void ft_count_words(char *s, t_attr *att);

// utilities_folder

// prompt.c
char *prompt(void);

// signals.c
void	set_signals(void);
void	handle_interrupt(int sig);

// debugg.c

void	ft_print_array(char **array);

//	error_folder

// 00_verify_readline.c
int verify_readline(char *s);
int count_quotes(char *s);

//	free_folder

// 00_free.c

void free_arr2(char **tokens, t_attr *att);
void free_arr(char **arr);

// Commands

int		pwd(char **env);
int		envi(char **env);
int		ls_l(char **env, int j);
int		echo(char **args);
void	ft_exit();


#endif
