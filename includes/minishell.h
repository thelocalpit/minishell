/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:16:54 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/18 22:59:29 by pfalasch         ###   ########.fr       */
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

// pipe

# define READ_END 0
# define WRITE_END 1


/* ------------------------  ERRORS   ---------------------------------- */

# define ERROR_UNCLOSED "minishell : syntax error unclosed quotes\n"
# define ERROR_PIPE "minishell : syntax error  near '|'\n"

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
	int flag_err_type;
	int flag_to_do;
	//-----pipe----------
	int nb_pipes;
	int **pipesfd;
	int pipe_index;
	//----- flag ----------
	int write_to_pipe;
	int read_from_pipe;
	int read_from_file;
	int redir;
	int create_file;
	int only_create;
	int heredoc;
	int skip;

} t_attr;

	/* ------------------------  FUNCTIONS ---------------------------------- */

	// init_folder

void	init_parameters(t_attr *att);
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

// 00_utils.c

int ft_strcmp(const char *str1, const char *str2);

//	error_folder

// 00_verify_readline.c
int verify_readline(t_attr *att);
int error_redir(t_attr *att);

// 01_error_quotes.c

int count_quotes(char *s);

// 02_error_piepes.c

int error_pipe(t_attr *att);
int error_pipe_first(t_attr *att);
int error_last_pipe(t_attr *att);

// 03_error_redir.c

int error_last_redir(t_attr *att);

// 04_error_mixed.c

void check_to_do(char *s, t_attr *att);
int check_next_str_err(char *s2);
int check_error_cmd(char *s1);
int mixed_error(t_attr *att);

//	free_folder

// 00_free.c

void free_arr2(char **tokens, t_attr *att);
void free_arr(char **arr);

// Commands

int		do_builtin(char **args, char **env);
int		pwd(char **env);
int		envi(char **env);
int		ls_l(char **env, int j);
int		echo(char **args);
void	ft_exit(void);

// parser folder

// parser.c

void reset_flags(t_attr *att);
void next_step_sub2(t_attr *att);
void next_step_sub(t_attr *att);
int check_next_step(t_attr *att);

// Executer folder

//	pipe.c

void count_pipes(t_attr *att);
void init_pipes(t_attr *att);
void write_to_pipe(t_attr *att);
void read_from_pipe(t_attr *att);
void close_pipeline(t_attr *att);

#endif
