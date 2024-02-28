/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_error_mixed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:02:39 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:04:50 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	char_2nd_check_02(char *c, int j, char b, t_attr *strct)
{
	if (b == '<')
		return (lt_error(strct));
	else if (b == '|')
		return (not_required(strct));
	else if (b == '>' && c[j + 1] == '>')
		return (not_required(strct));
	else if (b == '>' && c[j + 1] == '<')
		return (not_required(strct));
	return (0);
}

int	char_2nd_check_03(char *c, int j, char b, t_attr *strct)
{
	if (b == '>')
		return (not_required(strct));
	else if (b == '|')
		return (pipe_error(strct));
	else if (b == '<' && c[j + 1] == '<')
		return (not_required(strct));
	else if (b == '<' && c[j + 1] == '>')
		return (not_required(strct));
	return (0);
}

int	spaces_check(char *src, int *j, t_attr *strct)
{
	while (src[*j] == ' ' && src[*j] != '\0')
	{
		if (src[*j] == '\0')
			return (nl_error(strct));
		(*j)++;
	}
	return (0);
}

int	check_2nd_char(char *src, int j, t_attr *strct)
{
	char	c;
	char	d;

	if (src[j + 1])
		j++;
	else
		return (nl_error(strct));
	c = src[j - 1];
	d = src[j];
	if (c == '>' && char_2nd_check_02(src, j, d, strct) == 1)
		return (1);
	else if (c == '<' && char_2nd_check_03(src, j, d, strct) == 1)
		return (1);
	else if (c == '|' && (d == '>' || d == '<' || d == '|'))
		return (not_required(strct));
	return (0);
}

int	mixed_error_start(char *c, t_attr *strct)
{
	int	j;

	j = 0;
	while (c[j])
	{
		j = scroll(c, j);
		if (c[j] == '>' || c[j] == '<' || c[j] == '|')
		{
			if (check_2nd_char(c, j, strct))
				return (1);
			else if (extra_char_check(c, j, strct))
				return (1);
			else if (next_arg_check(c, j, strct))
				return (1);
			if (c[j + 1] == '>' || c[j + 1] == '<')
				j += 2;
			else
				j++;
			if (spaces_check(c, &j, strct) != 0)
				return (1);
		}
	}
	return (0);
}
