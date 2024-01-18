/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_error_mixed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:02:39 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/18 17:43:38 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione si assicura che non ci siano extra char
	oltre i possibili 2 consentiti e stampa i relativi errori */
int check_extra_char(char *s, int i)
{
	char c;
	char d;
	char e;

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

int check_next_arg(char *s, int i)
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

int check_2nd_char(char *s, int i)
{
	char c;
	char d;

	i++;
	c = s[i - 1];
	d = s[i];
	if (c == '>')
	{
		if (d == '<')
			return (return_lt_error());
		else if (d == '|')
			return (return_not_required());
	}
	else if (c == '<')
	{
		if (d == '>')
			return (return_not_required());
		else if (d == '|')
			return (return_pipe_error());
	}
	else if (c == '|' && (d == '>' || d == '<' || d == '|'))
		return (return_not_required());
	return (0);
}

int ft_scorri(char *s, int i)
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

int error_mixed_start(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		i = ft_scorri(s, i);
		// printf("sono qui8\n");
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
		{
			if (check_2nd_char(s, i))
			{
				// printf("sono qui1\n");
				return (1);
			}
			else if (check_extra_char(s, i))
				return (1);
			else if (check_next_arg(s, i))
				return (1);
			if (s[i + 1] == '>' || s[i + 1] == '<')
				i += 2;
			else
				i++;
		}
	}
	return (0);
}
