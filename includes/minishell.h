/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:12:38 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:22:50 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// libs
# include <dirent.h>
# include <errno.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <fcntl.h>

//global variable

extern int	g_sig_val;

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

# ifdef __linux__
#  define PATH_MAX 4096
# elif __MACH__
#  define PATH_MAX 1024
# else
#  warning "Unknown or unsupported operating system. Assuming PATH_MAX is 4096."
#  define PATH_MAX 4096
# endif
// pipe

# define READ_END 0
# define WRITE_END 1

/* ------------------------  ERRORS   ---------------------------------- */

# define ERROR_UNCLOSED "minishell : syntax error unclosed quotes\n"
# define ERROR_PIPE "minishell : syntax error  near '|'\n"

/* ------------------------  STRUCTS  ---------------------------------- */

typedef struct s_list
{
	char			*content;
	int				dol_flag;
	struct s_list	*next;
}				t_list;

typedef struct s_attr
{
	int		num_tokens;
	int		y;
	int		x;
	int		y2;
	int		x2;
	int		i_readfile;
	int		counter;
	int		words_counter;
	int		red_fd;
	int		pipe_index_num;
	int		pipes_num;
	int		write_pipe;
	int		**pipes_fd;
	int		redir;
	int		i_redir;
	int		first_redir;
	int		read_pipe;
	int		x_mtx_envp;
	int		skip;
	int		y_mtx_envp;
	int		read_files;
	int		mem_space;
	int		len_call_exp;
	int		heredoc;
	int		num_dol;
	int		i_flag_dol;
	int		*flag_dol;
	int		i;
	int		*save_y_mtx_envp;
	int		list_flag;
	int		list_index;
	int		value;
	char	**split_array;
	char	**array2;
	char	**env;
	char	**paths;
	char	*check_exp;
	pid_t	pid;
	t_list	*env_list;
	t_list	*local_list;
}				t_attr;

//---------------------------------------------------------------------

// libft
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isascii(int x);
int		ft_isdigit(int x);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);

//---------------------------------------------------------------------

// init_folder
void	init_parameters(t_attr *att);
void	init_attributes(t_attr *att);
void	reinit_parameters(t_attr *att, char **envp);

//---------------------------------------------------------------------

// tokens_folder
// 00_token_init_counter.c
void	init_split(char *c, t_attr *strc);
int		tokens_counter(char *c, t_attr *strc);
int		special_token_process(t_attr *strc, char *c, int j);
int		s_d_quotes(char *c, int j);

// 01_token_in_array.c
void	create_array(char *s, t_attr *att);
char	*get_token(char *s);
void	check_next_special_token(char *s, int i, char **token);

//02_single_token_matrix.c
void	get_cmd_matrix(char *s, t_attr *att);
void	create_matrix_cmd(char *s, t_attr *att);
char	*get_cmd_token(char *s, t_attr *att);
int		ft_strlen_custom(char *s, int flag, t_attr *att);
char	*ft_write_word(char *s, t_attr *att, int flag, int i);

// 02b_ft_strlen_custom.c
void	ft_counter_exp_print_error(t_attr *att);
void	ft_strlen_double_quotes(char *s, t_attr *att);
void	ft_strlen_no_quotes(char *s, t_attr *att);
int		ft_strlen_custom(char *s, int flag, t_attr *att);

// 02c_copy_word.c
int		copy_g_value(t_attr *att, int i);
int		copy_no_quotes(char *s, int i, t_attr *att, int len_name_var);
int		copy_double_quotes(char *s, int i, t_attr *att, int len_name_var);
char	*ft_write_word(char *s, t_attr *att, int flag, int i);

// 02d_copy_word_02.c
int		ft_strlen_name_var(char *s, int *i, int len_name_var);
int		copy_g_value(t_attr *att, int i);
int		copy_double_dollar(int i, t_attr *att);

// 03_words_counter.c
int		check_single_quotes(char *s, int len, int i, t_attr *att);
int		check_double_quotes(char *s, int len, int i, t_attr *att);
int		check_no_space(char *s, int len, int i, t_attr *att);
void	ft_words_counter(char *s, t_attr *att);

// 04_expander.c
void	copy_expanded_str(t_attr *att, int start);
void	counter_expanded_token(t_attr *att, char *s);
void	counter_expanded_token_local_list(t_attr *att);

int		ft_intsize(int n);
int		ft_ispositive(int n);
void	ft_itoa_custom(int n, t_attr *att);

//---------------------------------------------------------------------

// utilities_folder
// prompt.c
char	*prompt(void);

// signals.c
void	signal_set(void);
void	set_signal_child(void);
void	signal_set_avoid(void);
void	signal_heredoc_handler(void);

// debugg.c
void	ft_print_array(char **array);
void	printlist(t_attr *att);
void	printvar(t_list *var);

// 00_utils.c
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);

// 01_utils.c
t_list	*copy_env_in_list(char **env);
t_list	*sort_list(t_list *list);
char	*get_variable_name(char *full_var);
void	add_index_env_list(t_attr *att);
void	add_index_custom_env(t_attr *att);

// 03_utils.c
void	env_to_matrix(t_attr *att);
int		matrix_len(char **matrix);
void	add_index_local_list(t_attr *att);
int		ft_is_space(char *s);

// 02_utils.c
char	*get_variable_content(char *full_var);
int		var_name_length(char *full_var);
char	*var_no_quote_on_content(char *str);

//---------------------------------------------------------------------

//	error_folder
// 00_verify_readline.c

int		check_readline(char *src, t_attr *strct);
int		begin_error_2(char *s, t_attr *att);
int		next_chars_check(char *c, t_attr *strc);
int		return_negative(t_attr *att);

// 01_error_quotes.c
int		quotes_counter(char *c);

// 02_error_error_start_last.c

int		begin_error(char *c, t_attr *strct);
int		end_error(char *c, char s, t_attr *strct);

// 03_error_mixed.c

int		char_2nd_check_02(char *c, int j, char b, t_attr *strct);
int		char_2nd_check_03(char *c, int j, char b, t_attr *strct);
int		spaces_check(char *src, int *j, t_attr *strct);
int		check_2nd_char(char *s, int i, t_attr *att);
int		mixed_error_start(char *c, t_attr *strct);

//03a_error_mixed.c

int		scroll(char *c, int j);
int		extra_char_check(char *c, int j, t_attr *strct);
int		next_arg_check(char *c, int j, t_attr *strct);

// 04_error_messages.c

int		not_required(t_attr *strct);
int		pipe_error(t_attr *strct);
int		gt_error(t_attr *strct);
int		lt_error(t_attr *strct);
int		nl_error(t_attr *strct);

// 04a_error_messages.c
int		error_exit(char *c, t_attr *strct);
void	reader_file_error(t_attr *strct, char *src);
void	not_found_command(char *src);

// 05_error_dollar.c

int		dollar_error(char *c, t_attr *strct);
int		dollar_error_2(char *c, int a, t_attr *strc);
int		dollar_error_3(char *check_envp, t_attr *att, int len);
int		dollar_sign_counter(char *c, t_attr *strc);

//	free_folder

// 00_free.c

void	free_array2(char **tokens, t_attr *att);
void	free_array(char **arr);
void	ft_delete_matrix(void *matrix);
void	free_mx_envp(t_attr *att);
void	free_local_list(t_attr *att);
void	free_env_list(t_attr *att);

// Commands folder

// Commands

int		builtin_exec(t_attr *strc);
int		child_command(t_attr *strc);
int		check_builtin(t_attr *strc);

// env-echo-pwd-cd.c

int		ft_enviorment(t_attr *strc);
int		ft_echo(char **str);
int		ft_pwd(t_attr *strc);
int		ft_cd(char **args);

// var.c

int		var_update(char *src, t_list *list, int n);
int		add_var(char *str, t_attr *att);
int		var_new(char *src, t_attr *strc, int tot, int clear);

// 01_export

int		ft_export(char **args, t_attr *att);

// 01_unset

int		unset(char **str, t_attr *strc);
void	node_remove(t_list **env_list, char *str);

// exit.c

void	custom_exit(t_attr *strc);
int		ft_exit_02(t_attr *att);

// parser folder

// parser.c

void	reset_flags(t_attr *att);
void	next_step_sub2(t_attr *att);
void	next_step_sub(t_attr *att);
int		check_next_step(t_attr *att);
void	red_index(t_attr *att);

// Executer folder

// ecxeve.c

int		ft_ecxev(char *path, char **arg, char **env);
int		binary_executer(t_attr *att);

// exec.c

int		do_execve(t_attr *att);
int		exec(t_attr *att);

//	pipe.c

int		counter_pipes(t_attr *att);
void	init_pipes(t_attr *att);
void	write_pipe(t_attr *att);
void	read_pipe(t_attr *att);
void	close_pipeline(t_attr *att);

// read_file.c
void	check_read_file(t_attr *att);
int		heredoc(t_attr *att);

// redir.c
void	check_redirections(t_attr *att);
int		create_file(t_attr *att, char *str, int redir);

// redirections.c
void	reset_flag2(t_attr *att);
void	frist_redir(t_attr *att);

#endif
