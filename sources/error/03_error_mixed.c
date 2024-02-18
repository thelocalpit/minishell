/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_error_mixed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:02:39 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/16 23:58:21 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_2nd_char_03(char *s, int i, char d, t_attr *att)
{
	if (d == '>')
		return (return_not_required(att));
	else if (d == '|')
		return (return_pipe_error(att));
	else if (d == '<' && s[i + 1] == '<')
		return (return_not_required(att));
	else if (d == '<' && s[i + 1] == '>')
		return (return_not_required(att));
	return (0);
}

int	check_2nd_char_02(char *s, int i, char d, t_attr *att)
{
	if (d == '<')
		return (return_lt_error(att));
	else if (d == '|')
		return (return_not_required(att));
	else if (d == '>' && s[i + 1] == '>')
		return (return_not_required(att));
	else if (d == '>' && s[i + 1] == '<')
		return (return_not_required(att));
	return (0);
}

int	check_2nd_char(char *s, int i, t_attr *att)
{
	char	c;
	char	d;

	if (s[i + 1])
		i++;
	else
		return (return_nl_error(att));
	c = s[i - 1];
	d = s[i];
	if (c == '>' && check_2nd_char_02(s, i, d, att) == 1)
		return (1);
	else if (c == '<' && check_2nd_char_03(s, i, d, att) == 1)
		return (1);
	else if (c == '|' && (d == '>' || d == '<' || d == '|'))
		return (return_not_required(att));
	return (0);
}
int check_spaces(char *s, int *i, t_attr *att)
{
	while (s[*i] == ' ' && s[*i] != '\0')
	{
		if (s[*i] == '\0')
			return (return_nl_error(att));
		(*i)++;
	}
	return (0);
}
// int	check_spaces(char *s, int *i, t_attr *att)
// {
// 	while (s[*i] == ' ')
// 		(*i)++;
// 	if (s[*i] == '\0')
// 		return (return_nl_error(att));
// 	// else if (s[*i] == '>')
// 	// 	return_gt_error();
// 	// else if (s[*i] == '<')
// 	// 	return_lt_error();
// 	// else if (s[*i] == '|')
// 	// 	return_pipe_error();
// 	return (0);
// }

int	error_mixed_start(char *s, t_attr *att)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i = ft_scorri(s, i);
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
		{
			if (check_2nd_char(s, i, att))
				return (1);
			else if (check_extra_char(s, i, att))
				return (1);
			else if (check_next_arg(s, i, att))
				return (1);
			if (s[i + 1] == '>' || s[i + 1] == '<')
				i += 2;
			else
				i++;
			if (check_spaces(s, &i, att) != 0)
				return (1);
		}
	}
	return (0);
}
