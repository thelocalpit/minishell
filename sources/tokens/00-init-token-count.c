/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-init-token-count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:12:26 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/28 09:35:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	s_d_quotes(char *c, int j)
{
	if (c[j] == '\'')
	{
		j++;
		while (c[j] != '\'' && c[j])
			j++;
	}
	else if (c[j] == '"')
	{
		j++;
		while (c[j] != '"' && c[j])
			j++;
	}
	return (j);
}

int	special_token_process(t_attr *strc, char *c, int j)
{
	if (c[j] == '|' || c[j] == '>' || c[j] == '<')
	{
		strc->num_tokens++;
		if (c[j] == '|')
			return (++j);
		else if (c[j] == '>' && c[j + 1] == '>')
			return (j + 2);
		else if (c[j] == '>' && c[j + 1] != '>')
			return (++j);
		else if (c[j] == '<' && c[j + 1] == '<')
			return (j + 2);
		else
			return (++j);
	}
	else
		return (++j);
}

int	tokens_counter(char *c, t_attr *strc)
{
	int	j;
	int	n;

	if (!c)
		return (0);
	j = 0;
	n = ft_strlen(c) - 1;
	while (j <= n)
	{
		if (c[j] != ' ' && c[j] != '|' && c[j] != '<' && c[j] != '>')
		{
			strc->num_tokens++;
			while (j <= n && (c[j] != '|' && c[j] != '<' && c[j] != '>'))
			{
				if (c[j] == '\'' || c[j] == '"')
					j = s_d_quotes(c, j);
				j++;
			}
		}
		if (c[j] == ' ')
			j++;
		else
			j = special_token_process(strc, c, j);
	}
	return (strc->num_tokens);
}

void	init_split(char *c, t_attr *strc)
{
	if (!c)
		return ;
	strc->num_tokens = 0;
	strc->split_array = NULL;
	tokens_counter(c, strc);
	build_array(c, strc);
}
