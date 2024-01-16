/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_verify_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:00:05 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/10 18:06:01 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* controlla la linea di comando inserita con tutte le varie casistiche */
int return_negative(void)
{
	g_value = 2;
	return (-1);
}

int verify_readline(char *s, t_attr *att)
{
	if (error_end(s, '>') || error_end(s, '<') || error_end(s, '|'))
		return (return_negative());
	else if (error_begin(s))
		return (return_negative());
	else if (error_mixed_start(s))
		return (return_negative());
	else if (count_quotes(s))
		return (return_negative());
	else if (error_dollar(s, att))
		return (return_negative());
	return (0);
}
