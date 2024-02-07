/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03a_error_mixed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:58:24 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/07 18:08:35 by pfalasch         ###   ########.fr       */
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
int	check_extra_char(char *s, int i)
{
	char	c;
	char	d;
	char	e;

	i++;
	c = s[i - 2];
	d = s[i - 1];
	e = s[i];
	if (c == '<' && d == '<' && e == '<')
		return (return_not_required());
	else if ((c == '>' && d == '>') || (c == '<' && d == '<'))
	{
		if (e == '>')
			return (return_gt_error());
		else if (e == '<')
			return (return_lt_error());
		else if (e == '|')
			return (return_pipe_error());
	}
	return (0);
}

/* questa funzione si assicura che non ci siano due redir
	di fila a quell'altra e stampa i relativi errori in caso ci siano  */
int	check_next_arg(char *s, int i)
{
	i++;
	if (s[i] == '>' || s[i] == '<')
		i++;
	while (s[i] != ' ')
		i++;
	if (s[i] != '>' || s[i] != '<' || s[i] != '|')
		return (0);
	else
	{
		if (s[i] == '>')
			return (return_gt_error());
		else if (s[i] == '<')
			return (return_lt_error());
		else
			return (return_pipe_error());
	}
}
