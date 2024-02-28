/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:32:02 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 13:32:04 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Sets up signal handlers for SIGINT and SIGQUIT.
 * SIGINT is handled by the function interrupt_handler.
 * SIGQUIT is ignored.
 */
void	set_signal(void)
{
	struct sigaction	action;

	action.sa_handler = interrupt_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL);
	action.sa_handler = SIG_IGN;
	sigemptyset(&action.sa_mask);
	sigaction(SIGQUIT, &action, NULL);
}

/**
 * @brief Sets the signal handlers for child processes.
 * The SIGINT and SIGQUIT signals are set to their default handlers.
 */
void	set_child_signal(void)
{
	struct sigaction	action;

	action.sa_handler = SIG_DFL;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	sigaction(SIGINT, &action, NULL);
	action.sa_handler = SIG_DFL;
	sigemptyset(&action.sa_mask);
	sigaction(SIGQUIT, &action, NULL);
}
