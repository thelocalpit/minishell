/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:30:06 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/13 16:45:05 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	handle_interrupt is a signal handler for Ctrl+C
	(SIGINT) that clears the current input line and
	starts a new line with a new prompt.
	SIGINT - CTRL C
	SIGQUIT - CTRL BACKSLSH
	SIGTSTP - CTRL Z
*/


/* la seguente funzione è necessaria per gestire il segnale CTRL+C
	se il sig passato in funzione è SIGINT, allora andiamo a capo, sostituiamo 
	la riga con una vuota.
	muovo il cursore su una nuova linea.
	faccio un redisplay del prompt
	
	 */
void	handle_interrupt(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	//att.g_value = 130;
}
void handle_interrupt3(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	//att.g_value = 130;
}
void set_signals3(void)
{
	// printf("sono dentro 3\n")
	signal(SIGINT, handle_interrupt3);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signals(void)
{
	signal(SIGINT, handle_interrupt);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signals2(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	heredoc_handler(int sig)
{
	if (sig == SIGINT)
	{
		unlink(".heredoc");
		exit(130);
	}
	else if (sig == SIGQUIT)
	{
		unlink(".heredoc");
		exit(131);
	}
}
