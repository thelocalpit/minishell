/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_verify_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:43:57 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/18 19:48:52 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* funzione di partenza degli errori. */


int	verify_readline(t_attr *att)
{
	if (error_pipe(att) != 0)
		return (1);
	if (error_last_redir(att) != 0)
		return (1);
	if (mixed_error(att) != 0)
		return (1);
	if (count_quotes(att->split_arr[att->y]) != 0)
	{
		printf(ERROR_UNCLOSED);
		return (1);
	}
	return (0);
}

