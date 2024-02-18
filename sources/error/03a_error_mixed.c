/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03a_error_mixed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:58:24 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/16 23:18:46 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_scorri(char *s, int i)
{
	while (s[i] != '|' && s[i] != '>' && s[i] != '<' && s[i])
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
		}
		else if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'' && s[i])
				i++;
		}
		i++;
	}
	return (i);
}

/* questa funzione si assicura che non ci siano extra char
	oltre i possibili 2 consentiti e stampa i relativi errori */
int	check_extra_char(char *s, int i, t_attr *att)
{
	char	c;
	char	d;
	char	e;

	if (s[i + 1] == '>' || s[i + 1] == '<')
	{
		if (s[i + 2])
			i += 2;
		else
		{
			return (return_nl_error(att));
		}
		c = s[i - 2];
		d = s[i - 1];
		e = s[i];
		if (c == '<' && d == '<' && e == '<')
			return (return_not_required(att));
		else if ((c == '>' && d == '>') || (c == '<' && d == '<'))
		{
			if (e == '>')
				return (return_gt_error(att));
			else if (e == '<')
				return (return_lt_error(att));
			else if (e == '|')
				return (return_pipe_error(att));
		}
	}
	return (0);
}

/* questa funzione si assicura che non ci siano due redir
	di fila a quell'altra e stampa i relativi errori in caso ci siano  */
int	check_next_arg(char *s, int i, t_attr *att)
{
	i++;
	if (s[i] == '>' || s[i] == '<')
		i++;
	while (s[i] == ' ' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (return_not_required(att));
	if (s[i] != '>' && s[i] != '<' && s[i] != '|')
		return (0);
	else
	{
		if (s[i] == '>')
			return (return_gt_error(att));
		else if (s[i] == '<')
			return (return_lt_error(att));
		else
			return (return_pipe_error(att));
	}
}
