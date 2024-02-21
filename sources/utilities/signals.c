/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:30:06 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/21 11:08:52 by mcoppola         ###   ########.fr       */
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

extern int	g_sig_val;

void	handle_interrupt(int signum)
{
	g_sig_val = signum;
	printf("\n");
	rl_on_new_line();
	rl_replace_line ("", 0);
	rl_redisplay();
}

void	check_child(int signum)
{
	g_sig_val = signum;
}
void	signal_set(void)
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

void	signal_set_avoid(void)
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

