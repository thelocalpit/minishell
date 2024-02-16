/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:30:06 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/16 18:21:20 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* la seguente funzione è necessaria per gestire il segnale CTRL+C
	se il sig passato in funzione è SIGINT, allora andiamo a capo, sostituiamo
	la riga con una vuota.
	muovo il cursore su una nuova linea.
	faccio un redisplay del prompt
*/


#include "../../includes/minishell.h"
#include <signal.h>

extern int	g_signal;

void	handle_interrupt(int signum)
{
	g_signal = signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line ("", 0);
	rl_redisplay();
}

void	handle_quit(int signum)
{
	printf("sono dentro handle_quit\n");
	(void)signum;
	return ;
}

void	check_child(int signum)
{
	g_signal = signum;
}
void	set_signal(void)
{
	struct sigaction	new_action;

	new_action.sa_handler = handle_interrupt;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(SIGINT, &new_action, NULL);
	new_action.sa_handler = SIG_IGN;
	sigemptyset(&new_action.sa_mask);
	sigaction(SIGQUIT, &new_action, NULL);
}

void	set_signal_child(void)
{
	struct sigaction	new_action;

	new_action.sa_handler = SIG_DFL;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(SIGINT, &new_action, NULL);
	new_action.sa_handler = SIG_DFL;
	sigemptyset(&new_action.sa_mask);
	sigaction(SIGQUIT, &new_action, NULL);
}

void	set_signal_avoid(void)
{
	struct sigaction	new_action;

	new_action.sa_handler = check_child;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = SA_RESTART;
	sigaction(SIGINT, &new_action, NULL);
}

void	heredoc_handler(int signum)
{
	if (signum == SIGINT)
	{
		unlink(".heredoc");
		exit(130);
	}
	else if (signum == SIGQUIT)
	{
		unlink(".heredoc");
		exit(0);
	}
}

void	signal_heredoc_handler(void)
{
	struct sigaction new_action;

	new_action.sa_handler = heredoc_handler;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(SIGINT, &new_action, NULL);
	new_action.sa_handler = heredoc_handler;
	sigemptyset(&new_action.sa_mask);
	sigaction(SIGQUIT, &new_action, NULL);

}

