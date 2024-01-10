/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_verify_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:00:05 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/10 17:40:25 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* controlla la linea di comando inserita con tutte le varie casistiche */

int verify_readline(char *s, t_attr *att)
{
	if (error_end(s, '>') || error_end(s, '<') || error_end(s, '|'))
	{
		g_value = 2;
		return (-1);
	}
	else if (error_begin(s))
	{
		g_value = 2;
		return (-1);
	}
	else if (error_mixed_start(s))
	{
		g_value = 2;
		return (-1);
	}
	else if (count_quotes(s))
	{
		g_value = 2;
		return (-1);
	}
	else if (error_dollar(s, att))
	{
		g_value = 2;
		return (-1);
	}
	return (0);
}
