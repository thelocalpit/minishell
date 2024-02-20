/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_token_init_counter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:12:26 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 12:07:06 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione serve per contare i token ¨speciali¨. */

int	process_special_token(t_attr *att, char *s, int i)
{
	if (s[i] == '|' || s[i] == '>' || s[i] == '<')
	{
		att->num_tokens++;
		if (s[i] == '|')
			return (++i);
		else if (s[i] == '>' && s[i + 1] == '>')
			return (i + 2);
		else if (s[i] == '>' && s[i + 1] != '>')
			return (++i);
		else if (s[i] == '<' && s[i + 1] == '<')
			return (i + 2);
		else
			return (++i);
	}
	else
		return (++i);
}

int	check_s_d_quotes(char *s, int i)
{
	if (s[i] == '\'')
	{
		i++;
		while (s[i] != '\'' && s[i])
			i++;
	}
	else if (s[i] == '"')
	{
		i++;
		while (s[i] != '"' && s[i])
			i++;
	}
	return (i);
}

/* to counter tokens we get the len of s.
	with those conditions we intend to counter (cmd + args) and (|,>,<)
	 */
int	counter_tokens(char *s, t_attr *att)
{
	int 	i;
	int		len;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s) - 1;
	while (i <= len)
	{
		if (s[i] != ' ' && s[i] != '|' && s[i] != '<' && s[i] != '>')
		{
			att->num_tokens++;
			while (i <= len && (s[i] != '|' && s[i] != '<' && s[i] != '>'))
			{
				if (s[i] == '\'' || s[i] == '"')
					i = check_s_d_quotes(s, i);
				i++;
			}
		}
		if (s[i] == ' ')
			i++;
		else
			i = process_special_token(att, s, i);
	}
	return (att->num_tokens);
}
/* questa funzione si occupa di splittare fra comandi (con argomenti)
	e redirections */

void	split_init(char *s, t_attr *att)
{
	if (!s)
		return ;
	att->num_tokens = 0;
	att->split_array = NULL;
	counter_tokens(s, att);
	create_array(s, att);
}
