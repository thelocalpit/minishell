/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_error_mixed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:02:39 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/07 18:01:34 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_2nd_char_03(char *s, int i, char d)
{
	if (d == '>')
		return (return_not_required());
	else if (d == '|')
		return (return_pipe_error());
	else if (d == '<' && s[i + 1] == '<')
		return (return_not_required());
	else if (d == '<' && s[i + 1] == '>')
		return (return_not_required());
	return (0);
}

int	check_2nd_char_02(char *s, int i, char d)
{
	if (d == '<')
		return (return_lt_error());
	else if (d == '|')
		return (return_not_required());
	else if (d == '>' && s[i + 1] == '>')
		return (return_not_required());
	else if (d == '>' && s[i + 1] == '<')
		return (return_not_required());
	return (0);
}

int	check_2nd_char(char *s, int i)
{
	char	c;
	char	d;

	i++;
	c = s[i - 1];
	d = s[i];
	if (c == '>' && check_2nd_char_02(s, i, d) == 1)
		return (1);
	else if (c == '<' && check_2nd_char_03(s, i, d) == 1)
		return (1);
	else if (c == '|' && (d == '>' || d == '<' || d == '|'))
		return (return_not_required());
	return (0);
}

int	check_spaces(char *s, int *i)
{
	while (s[*i] == ' ' || s[*i] == '\0')
	{
		if (s[*i] == '\0')
			return (1);
		(*i)++;
	}
	return (0);
}

int	error_mixed_start(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i = ft_scorri(s, i);
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
		{
			if (check_2nd_char(s, i))
				return (1);
			else if (check_extra_char(s, i))
				return (1);
			else if (check_next_arg(s, i))
				return (1);
			if (s[i + 1] == '>' || s[i + 1] == '<')
				i += 2;
			else
				i++;
			if (check_spaces(s, &i) != 0)
				return_nl_error();
		}
	}
	return (0);
}
