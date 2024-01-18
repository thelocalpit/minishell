/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:16:54 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/18 12:44:10 by pfalasch         ###   ########.fr       */
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
    //----- flag ----------
    int     write_to_pipe;
    int     read_from_pipe;
    int     read_from_file;
    int     redir;
    int     create_file;
    int     only_create;
    int     heredoc;
    int     skip;
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

// 03_count_words.c
int     check_single_quotes(char *s, int len, int i, t_attr *att);
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
void    set_signals(void);
void    handle_interrupt(int sig);

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
void add_index_to_local_var(t_attr *att);

// 02_utils.c

int ft_intsize(int n);
int ft_ispositive(int n);
void ft_itoa_custom(int n, t_attr *att);
char    *get_var_content(char *full_var);

//	error_folder

// 00_verify_readline.c
int     verify_readline(char *s, t_attr *att);

// 01_error_quotes.c

int     count_quotes(char *s);

// 02_error_error_start_last.c

int     error_begin(char *s);
int     error_end(char *s, char c);

// 03_error_redir.c

int     check_extra_char(char *s, int i);
int     check_next_arg(char *s, int i);
int     check_2nd_char(char *s, int i);
int     ft_scorri(char *s, int i);
int     error_mixed_start(char *s);

// 04_error_mixed.c

int     return_not_required(void);
int     return_pipe_error(void);
int     return_gt_error(void);
int     return_lt_error(void);
int     return_nl_error(void);

// 05_error_dollar.c

int     error_dollar(char *s, t_attr *att);
int     error_dollar_02(char *s, int i, t_attr *att);
int     error_dollar_03(char *check_envp, t_attr *att, int len);
int count_dollar_sign(char *s, t_attr *att);

//	free_folder

// 00_free.c

void free_arr2(char **tokens, t_attr *att);
void    free_arr(char **arr);
void    ft_delete_matrix(void *matrix);
void    free_mx_envp(t_attr *att);
void    free_env_list(t_attr *att);

// Commands

int do_builtin(char **args, char **env, t_attr *att);
int		pwd(char **env);
int		envi(t_attr *att);
int		ls_l(char **env, int j);
int		echo(char **args);
void	ft_exit(void);
void	ft_cd(char **args);
int		add_var(char *str, t_list **var_list);

// 01_export

int     ft_export(char **args, t_attr *att);

// 01_unset

int     ft_unset(char **args, t_attr *att);
void    ft_remove_node(t_list **env_list, char *arg);

// parser folder

// parser.c

void    reset_flags(t_attr *att);
void    next_step_sub2(t_attr *att);
void    next_step_sub(t_attr *att);
int     check_next_step(t_attr *att);

// lexer.c

void    command(t_attr *att);

// Executer folder

//	pipe.c

int     count_pipes(t_attr *att);
void    init_pipes(t_attr *att);
void    write_to_pipe(t_attr *att);
void    read_from_pipe(t_attr *att);
void    close_pipeline(t_attr *att);

// expander

// 00_expander.c

#endif
