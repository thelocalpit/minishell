/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/02/15 11:44:01 by pfalasch         ###   ########.fr       */
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

extern int  g_value;

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

#ifdef __linux__
#define PATH_MAX 4096
#elif __MACH__
#define PATH_MAX 1024
#else
#warning "Unknown or unsupported operating system. Assuming PATH_MAX is 4096."
#define PATH_MAX 4096
#endif
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
	int     nb_tokens;
	char    **split_arr;
	int     y;
	int     x;
	char    **arr2;
	int     y2;
	int     x2;
	// int *flag$;
	//------ cmds -------------
	int     count;
	//----- token variables ---------
	int     count_words;
	int     flag_cmd_valid;
	int     flag_quote;
	//------ errors -------------------
	int     flag_err_quote;
	int     flag_err_type;
	int     flag_to_do;
	//-----pipe----------
	int     nb_pipes;
	int     **pipesfd;
	int     pipe_index;
	//----- exec ---------
	int     red_fd;
	pid_t   pid;
	char	**paths;
	char	**env;
	//----- flag ----------
	int     write_to_pipe;
	int     read_from_pipe;
	int     read_from_file;
	int     redir;
	int     heredoc;
	int     skip;
	int     i_redir;
	int     i_readfile;
	int		frirst_redir;
	//---- envp custom matrix ---
	// char    **mx_envp;
	int     y_mx_envp;
	int     x_mx_envp;

	//---- expander --------
	int i;
	int mem_space;
	char *check_exp;
	int len_call_exp;
	int nb_$;
	int *flag$;
	int i_flag$;
	int *save_y_mx_envp;
    int flag_list;

    //--- lista ----

	t_list *env_list;
	int index_list;
	t_list *local_var;

} t_attr;


/* ------------------------------ NODE -------------------------------------- */



	/* ------------------------  FUNCTIONS ---------------------------------- */

	// init_folder

void    init_parameters(t_attr *att);
void    init_attributes(t_attr *att);
void    reinit_parameters(t_attr *att, char **envp);
void    start_env(char **envp, t_attr *att);

// tokens_folder

// 00_token_init_count.c

void    split_init(char *s, t_attr *att);
int     count_tokens(char *s, t_attr *att);
int     process_special_token(t_attr *att, char *s, int i);
int check_s_d_quotes(char *s, int i);

// 01_token_in_array.c

void create_array(char *s, t_attr *att);
char    *get_token(char *s);
void    check_next_special_token(char *s, int i, char **token);

	//02_single_token_matrix.c
void    get_cmd_matrix(char *s, t_attr *att);
void    create_matrix_cmd(char *s, t_attr *att);
char    *get_cmd_token(char *s, t_attr *att);
void    check_cmd_tokens(char *s, t_attr *att);
int     ft_strlen_custom(char *s, int flag, t_attr *att);
char    *ft_write_word(char *s, t_attr *att, int flag, int i);

// 02b_ft_strlen_custom.c

void ft_count_exp_print_error(t_attr *att);
void ft_strlen_double_quotes(char *s, t_attr *att);
void ft_strlen_no_quotes(char *s, t_attr *att);
int ft_strlen_custom(char *s, int flag, t_attr *att);

// 02c_copy_word.c

int copy_g_value(t_attr *att, int i);
int copy_no_quotes(char *s, int i, t_attr *att, int len_name_var);
int copy_double_quotes(char *s, int i, t_attr *att, int len_name_var);
char *ft_write_word(char *s, t_attr *att, int flag, int i);

// 02d_copy_word_02.c

int ft_strlen_name_var(char *s, int *i, int len_name_var);
int copy_g_value(t_attr *att, int i);
int copy_double_dollar(int i, t_attr *att);

// 03_count_words.c
int check_single_quotes(char *s, int len, int i, t_attr *att);
int     check_double_quotes(char *s, int len, int i, t_attr *att);
int     check_no_space(char *s, int len, int i, t_attr *att);
void    ft_count_words(char *s, t_attr *att);

// 04_expander.c

void copy_expanded_str(t_attr *att, int start);
void count_expanded_token(t_attr *att, char *s);
void count_expanded_token_local_var(t_attr *att);

// utilities_folder

// prompt.c
char *prompt(void);

// signals.c
void set_signals3(void);
void set_signals2(void);
void    set_signals(void);
void    handle_interrupt(int sig);
void    heredoc_handler(int sig);

// debugg.c

void	ft_print_array(char **array);
void printlist(t_attr *att);
void printvar(t_list *var);

// 00_utils.c

int     ft_strcmp(const char *str1, const char *str2);
char    *ft_strcpy(char *destination, const char *source);
char    *ft_strcat(char *dest, const char *src);
char    *ft_strncpy(char *dest, const char *src, size_t n);

// 01_utils.c

t_list  *copy_env_in_list(char **env);
t_list  *sort_list(t_list *list);
void    insert_between_node(t_list *prev, char *content);
char    *get_var_name(char *full_var);
void add_index_to_env_list(t_attr *att);
void add_index_to_custom_env(t_attr *att);

// 03_utils.c

void envp_to_matrix(t_attr *att);
int	matrix_len(char **matrix);
void add_index_to_local_var(t_attr *att);
int ft_isspace(char *s);

// 02_utils.c

int ft_intsize(int n);
int ft_ispositive(int n);
void ft_itoa_custom(int n, t_attr *att);
char    *get_var_content(char *full_var);
char    *removePlus(char *full_var);
int		var_name_length(char *full_var);

//	error_folder

// 00_verify_readline.c

int     verify_readline(char *s, t_attr *att);
int error_begin_02(char *s);
int check_next_chars(char *s);
int return_negative(void);

// 01_error_quotes.c

int count_quotes(char *s);

// 02_error_error_start_last.c

int     error_begin(char *s);
int     error_end(char *s, char c);

// 03_error_mixed.c

int check_2nd_char_02(char *s, int i, char d);
int check_2nd_char_03(char *s, int i, char d);
int check_spaces(char *s, int *i);
int check_2nd_char(char *s, int i);
int	error_mixed_start(char *s);

//03a_error_mixed.c

int ft_scorri(char *s, int i);
int check_extra_char(char *s, int i);
int check_next_arg(char *s, int i);

// 04_error_messages.c

int     return_not_required(void);
int     return_pipe_error(void);
int     return_gt_error(void);
int     return_lt_error(void);
int     return_nl_error(void);


// 04a_error_messages.c

int exit__err(char *str);
void	read_file_error(t_attr *att, char *file);
void	command_not_found(char *str);

// 05_error_dollar.c

int error_dollar(char *s, t_attr *att);
int     error_dollar_02(char *s, int i, t_attr *att);
int     error_dollar_03(char *check_envp, t_attr *att, int len);
int count_dollar_sign(char *s, t_attr *att);

//	free_folder

// 00_free.c

void free_arr2(char **tokens, t_attr *att);
void    free_arr(char **arr);
void    ft_delete_matrix(void *matrix);
void    free_mx_envp(t_attr *att);
void	free_local_var(t_attr *att);
void	free_env_list(t_attr *att);

// Commands folder

// Commands

int do_builtin(t_attr *att);
int do_child_cmd(t_attr *att);
int	built_in_check(t_attr *att);
void	ft_exit(void);

// builtin.c

int		echo(char **args);
int		pwd(t_attr *att);
int		envi(t_attr *att);
//int		ls_l(char **env, int j);
int		ft_cd(char **args);

//local_var.c

int		add_var(char *str, t_attr *att);
int		new_var(char *str, t_attr *att, int add, int empty);
int		update_var(char *str, t_list *list, int add);

// 01_export

int     ft_export(char **args, t_attr *att);

// 01_unset

int     ft_unset(char **args, t_attr *att);
void    ft_remove_node(t_list **env_list, char *arg);

// exit.c

void ft_exit_custom(t_attr *att);
int ft_exit_02(t_attr *att);

// parser folder

// parser.c

void reset_flags(t_attr *att);
void    next_step_sub2(t_attr *att);
void    next_step_sub(t_attr *att);
int     check_next_step(t_attr *att);
void    red_index(t_attr *att);

// lexer.c

void    command(t_attr *att);

// Executer folder

// ecxeve.c

int	ft_ecxev(char *path, char **arg, char **env);
int	absolute_exec(t_attr *att);
int	bin_exec(t_attr *att);

// exec.c

int		find_paths(t_attr *att);
int		do_execve(t_attr *att);
int		exec(t_attr *att);

//	pipe.c

int     count_pipes(t_attr *att);
void    init_pipes(t_attr *att);
void    write_to_pipe(t_attr *att);
void    read_from_pipe(t_attr *att);
void    close_pipeline(t_attr *att);

// read_file.c
int    check_read_file(t_attr *att);
int    red_input(t_attr *att, char *path);
int    heredoc(t_attr *att);
int    heredoc_read(t_attr *att, char *eof);
int    read_from_file(t_attr *att);

// redir.c
int    check_redir(t_attr *att);
int    redir(t_attr *att);
int		create_file(t_attr *att, char *str, int redir);

// redirections.c
int		do_red(t_attr *att);
void	reset_flags2(t_attr *att);
int		frist_redir(t_attr *att);

// expander

// 00_expander.c

#endif
