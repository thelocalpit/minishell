/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_verify_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:00:05 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/29 11:29:12 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* controlla la linea di comando inserita con tutte le varie casistiche */

int verify_readline(char *s, t_attr *att)
{
	att->heredoc = 0; //questo serve solo per zittire att
	// printf("sono qui\n");
	if (error_end(s, '>') || error_end(s, '<') || error_end(s, '|'))
	{
		// printf("sono qui2\n");
		return (1);
	}
	else if (error_begin(s))
	{
		// printf("sono qui4\n");
		return (1);
	}
	else if (error_mixed_start(s))
	{
		// printf("sono qui7\n");
		return (1);
	}
	else if (count_quotes(s))
	{
		return (1);
	}
	// else if (error_dollar(s, att))
	// {
	// 	return (1);
	// }
	return (0);
}
