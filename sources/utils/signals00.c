/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals00.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:31:56 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 13:31:57 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_sig_val;

/**
 * @brief Function to handle child process signals.
 *
 * This function is called when a signal is received by the child process.
 * It updates the global variable g_sig_val with the received signal number.
 *
 * @param signum The signal number received by the child process.
 */
void	check_child(int signum)
{
	g_sig_val = signum;
}

/**
 * @brief Handles the interrupt signal.
 *
 * This function is called when an interrupt signal (SIGINT) is received.
 * It updates the global variable g_sig_val with the received signal number,
 * prints a newline character, resets the readline library, clears the current
 * input line, and redisplays the prompt.
 *
 * @param signumber The signal number.
 */
void	interrupt_handler(int signumber)
{
	g_sig_val = signumber;
	printf("\n");
	rl_on_new_line();
	rl_replace_line ("", 0);
	rl_redisplay();
}

/**
 * @brief Signal handler for heredoc.
 *
 * This function is called when a signal is received while processing heredoc.
 * It handles SIGINT and SIGQUIT signals by unlinking the ".heredoc" file and
 * exiting the program.
 *
 * @param signumber The signal number.
 */
void	handler_heredoc(int signumber)
{
	if (signumber == SIGINT)
	{
		unlink(".heredoc");
		exit(130);
	}
	else if (signumber == SIGQUIT)
	{
		unlink(".heredoc");
		exit(0);
	}
}

/**
 * @brief Sets up signal handlers for heredoc processing.
 *  The SIGINT and SIGQUIT signals will be handled by the handler_heredoc
 *  function.
 */
void	handler_signal_heredoc(void)
{
	struct sigaction	action;

	action.sa_handler = handler_heredoc;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL);
	action.sa_handler = handler_heredoc;
	sigemptyset(&action.sa_mask);
	sigaction(SIGQUIT, &action, NULL);
}

/**
 * @brief Sets up the signal handler to avoid interruption by SIGINT.
 * The signal handler is set to call the function check_child.
 */
void	set_signal_avoid(void)
{
	struct sigaction	action;

	action.sa_handler = check_child;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;
	sigaction(SIGINT, &action, NULL);
}
