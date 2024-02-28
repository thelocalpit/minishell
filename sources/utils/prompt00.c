/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:31:48 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 13:31:49 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Generates a prompt for the minishell program.
 *
 *  This function prompts the user for input by displaying a formatted string.
 *  The prompt includes the name of the program and a decorative symbol.
 *
 * @return A pointer to a dynamically allocated string containing the user's
 * input.
 * ⚠️The caller is responsible for freeing the memory.⚠️
 */
char	*prompt(void)
{
	char	*line;

	line = readline(RESET "◈" RED_BOLD " 👹 Minihell" RED_BOLD " " RESET "");
	return (line);
}
