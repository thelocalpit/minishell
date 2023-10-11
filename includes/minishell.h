/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:16:54 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/11 16:59:37 by pfalasch         ###   ########.fr       */
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
	// ------ var per quotes ---------------
	int	n_dquotes;
	int	n_squotes;
	int	inside_single_quotes;
} 		t_attr;

/* ------------------------  FUNCTIONS ---------------------------------- */


//init_folder

void	init_parameters(t_attr *att, char **envp);
void	init_attributes(t_attr *att);
void	reinit_parameters(t_attr *att, char **envp);

// signals_folder

void handle_interrupt(int sig);
void	set_signals(void);

//tokens_folder

	// token_init.c

int		check_normal_char(char *s, int len, int i, t_attr *att);
int		check_double_quotes(char *s, int len, int i, t_attr *att);
int		check_single_quotes(char *s, int len, int i, t_attr *att);
void	count_quotes(char *s, t_attr *att);
int		count_tokens(char *s, t_attr *att);

//utilities_folder

	//prompt.c 
char	*prompt(void);

	//signals.c
void	set_signals(void);
void	handle_interrupt(int sig);

//error
	
	//error_01.c
int		verify_readline(char *s);
int		error_single_quote(char *s);
int		error_double_quote(char *s);

#endif
