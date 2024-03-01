/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03a_error_mixed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:58:24 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:29:14 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	next_arg_check(char *c, int j, t_attr *strct)
{
	j++;
	if (c[j] == '>' || c[j] == '<')
		j++;
	while (c[j] == ' ' && c[j] != '\0')
		j++;
	if (c[j] == '\0')
		return (not_required(strct));
	if (c[j] != '>' && c[j] != '<' && c[j] != '|')
		return (0);
	else
	{
		if (c[j] == '>')
			return (gt_error(strct));
		else if (c[j] == '<')
			return (lt_error(strct));
		else
			return (pipe_error(strct));
	}
}

int	scroll(char *c, int j)
{
	while (c[j] != '|' && c[j] != '>' && c[j] != '<' && c[j])
	{
		if (c[j] == '"')
		{
			j++;
			while (c[j] != '"' && c[j])
				j++;
		}
		else if (c[j] == '\'')
		{
			j++;
			while (c[j] != '\'' && c[j])
				j++;
		}
		j++;
	}
	return (j);
}

int	handle_double_char(char *src, int j, t_attr *strct)
{
	char	str;
	char	str1;
	char	str2;

	str = src[j - 2];
	str1 = src[j - 1];
	str2 = src[j];
	if (str == '<' && str1 == '<' && str2 == '<')
		return (not_required(strct));
	else if ((str == '>' && str1 == '>') || (str == '<' && str1 == '<'))
	{
		if (str2 == '>')
			return (gt_error(strct));
		else if (str2 == '<')
			return (lt_error(strct));
		else if (str2 == '|')
			return (pipe_error(strct));
	}
	return (0);
}

int	extra_char_check(char *src, int j, t_attr *strct)
{
	if (src[j + 1] == '>' || src[j + 1] == '<')
	{
		if (src[j + 2])
			j += 2;
		else
			return (nl_error(strct));
		return (handle_double_char(src, j, strct));
	}
	return (0);
}

// int	extra_char_check(char *src, int j, t_attr *strct)
// {
// 	char	str;
// 	char	str1;
// 	char	str2;

// 	if (src[j + 1] == '>' || src[j + 1] == '<')
// 	{
// 		if (src[j + 2])
// 			j += 2;
// 		else
// 		{
// 			return (nl_error(strct));
// 		}
// 		str = src[j - 2];
// 		str1 = src[j - 1];
// 		str2 = src[j];
// 		if (str == '<' && str1 == '<' && str2 == '<')
// 			return (not_required(strct));
// 		else if ((str == '>' && str1 == '>') || (str == '<' && str1 == '<'))
// 		{
// 			if (str2 == '>')
// 				return (gt_error(strct));
// 			else if (str2 == '<')
// 				return (lt_error(strct));
// 			else if (str2 == '|')
// 				return (pipe_error(strct));
// 		}
// 	}
// 	return (0);
// }
