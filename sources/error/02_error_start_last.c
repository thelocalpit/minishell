/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_error_start_last.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:03 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/20 17:05:57 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* controlla il primo elemento */
int error_begin(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != ' ')
		i++;
	if (s[i] == '|')
		return (return_pipe_error);
	else if (s[i] == '<' && s[i + 1] == '|')
		return (return_pipe_error);
	else if (s[i] == '>' && s[i + 1] == '>' && s[i + 2] == '|')
		return (return_pipe_error);
	else if (s[i] == '<' && s[i + 1] == '<' && s[i + 2] == '|')
		return (return_pipe_error);
	else if (s[i] == '<' && s[i + 1] == '>' && s[i + 2] == '|')
		return (return_pipe_error);
	else if (s[i] == '>' && s[i + 1] == '<' && s[i + 2] == '|')
		return (return_lt_error);
	return (0);
}

/* controlla ultimo elemento */

int error_last(char *s, char c)
{
	int len;

	len = ft_strlen(s);
	if (len == 0)
		return (0);
	if (s[len - 1] == c)
	{
		if (c != '|')
			return (return_pipe_error());
		else
			return (return_nl_error());
	}
	return (0);
}
