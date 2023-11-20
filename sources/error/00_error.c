/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:00:05 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/20 17:04:15 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int verify_readline(char *s)
{
	if (!error_last(s, '>') || !error_last(s, '<') || !error_last(s, '|'))
		return (1);
	else if (!error_begin(s))
		return (1);
	else if (!error_mixed_start(s))
		return (1);
	else if (count_quotes(s))
	{
		return (1);
	}
	return (0);
}
