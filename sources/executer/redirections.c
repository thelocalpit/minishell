/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:41:39 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/21 13:49:07 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Resets the flag values in the given attribute structure.
 *
 * @param att The attribute structure to reset.
 */
void	reset_flag2(t_attr *att)
{
	att->redir = 0;
	att->read_files = 0;
	att->heredoc = 0;
}

/**
 * @brief Performs the first redirection step in the execution process.
 *
 * @param att: A pointer to the t_attr structure containing execution
 * attributes.
 */
void	frist_redir(t_attr *att)
{
	att->y = att->y - 1;
	next_step_sub(att);
	red_index(att);
	att->first_redir = 1;
	att->y = att->y + 1;
}
