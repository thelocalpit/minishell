/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_error_start_last.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:03 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 11:52:52 by mcoppola         ###   ########.fr       */
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
			return (return_nl_error(strct));
		else
			return (return_not_required(strct));
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
		return (return_pipe_error(strct));
	else if (c[j] == '>' && c[j + 1] == '>' && c[j + 2] == '|')
		return (return_pipe_error(strct));
	else if (c[j] == '<' && c[j + 1] == '<' && c[j + 2] == '|')
		return (return_pipe_error(strct));
	else if (c[j] == '<' && c[j + 1] == '>' && c[j + 2] == '|')
		return (return_pipe_error(strct));
	else if (c[j] == '>' && c[j + 1] == '|')
		return (return_not_required(strct));
	else if (c[j] == '<' && c[j + 1] == '<' && c[j + 2] == '<')
		return (return_not_required(strct));
	else if (c[j] == '>' && c[j + 1] == '<' && c[j + 2] == '|')
		return (return_lt_error(strct));
	else if (c[j] == '>' && c[j + 1] == '>' && c[j + 2] == '>')
		return (return_gt_error(strct));
	return (0);
}
