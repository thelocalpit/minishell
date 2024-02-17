/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_error_start_last.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:03 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/17 07:29:56 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* controlla il primo elemento se è sbagliato */
int	error_begin(char *s, t_attr *att)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' && s[i])
		i++;
	if (s[i] == '|' || (s[i] == '<' && s[i + 1] == '|'))
		return (return_pipe_error(att));
	else if (s[i] == '>' && s[i + 1] == '>' && s[i + 2] == '|')
		return (return_pipe_error(att));
	else if (s[i] == '<' && s[i + 1] == '<' && s[i + 2] == '|')
		return (return_pipe_error(att));
	else if (s[i] == '<' && s[i + 1] == '>' && s[i + 2] == '|')
		return (return_pipe_error(att));
	else if (s[i] == '>' && s[i + 1] == '|')
		return (return_not_required(att));
	else if (s[i] == '<' && s[i + 1] == '<' && s[i + 2] == '<')
		return (return_not_required(att));
	else if (s[i] == '>' && s[i + 1] == '<' && s[i + 2] == '|')
		return (return_lt_error(att));
	else if (s[i] == '>' && s[i + 1] == '>' && s[i + 2] == '>')
		return (return_gt_error(att));
	return (0);
}

/* controlla ultimo elemento se è sbagliato */

int	error_end(char *s, char c, t_attr *att)
{
	int	len;

	len = ft_strlen(s);
	if (len == 0)
		return (0);
	while (s[len] == ' ' || s[len] == '\0')
		len--;
	if (s[len] == c)
	{
		if (c != '|')
			return (return_nl_error(att));
		else
			return (return_not_required(att));
	}
	return (0);
}
