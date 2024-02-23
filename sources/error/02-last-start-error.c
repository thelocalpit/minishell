/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_error_start_last.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:03 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:04:33 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	end_error(char *c, char s, t_attr *strct)
{
	int	len;

	len = ft_strlen(c);
	if (len == 0)
		return (0);
	while (c[len] == ' ' || c[len] == '\0')
		len--;
	if (c[len] == s)
	{
		if (s != '|')
			return (nl_error(strct));
		else
			return (not_required(strct));
	}
	return (0);
}

int	begin_error(char *c, t_attr *strct)
{
	int	j;

	j = 0;
	if (!c)
		return (0);
	while (c[j] == ' ' && c[j])
		j++;
	if (c[j] == '|' || (c[j] == '<' && c[j + 1] == '|'))
		return (pipe_error(strct));
	else if (c[j] == '>' && c[j + 1] == '>' && c[j + 2] == '|')
		return (pipe_error(strct));
	else if (c[j] == '<' && c[j + 1] == '<' && c[j + 2] == '|')
		return (pipe_error(strct));
	else if (c[j] == '<' && c[j + 1] == '>' && c[j + 2] == '|')
		return (pipe_error(strct));
	else if (c[j] == '>' && c[j + 1] == '|')
		return (not_required(strct));
	else if (c[j] == '<' && c[j + 1] == '<' && c[j + 2] == '<')
		return (not_required(strct));
	else if (c[j] == '>' && c[j + 1] == '<' && c[j + 2] == '|')
		return (lt_error(strct));
	else if (c[j] == '>' && c[j + 1] == '>' && c[j + 2] == '>')
		return (gt_error(strct));
	return (0);
}
