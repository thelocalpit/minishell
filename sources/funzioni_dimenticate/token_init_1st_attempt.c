/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:30:09 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/12 09:27:32 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_normal_char(char *s, int len, int i, t_attr *att)
{
	att->nb_tokens++;
	while (i <= len && s[i] != ' ')
		i++;
	return (++i);
}

int	check_double_quotes(char *s, int len, int i, t_attr *att)
{
	int	d_quotes;

	d_quotes = 0;
	att->nb_tokens++;
	if (s[i + 1] && s[i + 1] == '"'
		&& ((s[i +2] && s[i + 2] == ' ') || !s[i + 2]))
		return (i + 2);
	while (i <= len)
	{
		if (s[i] == '\\' && s[i + 1] == '"')
			i += 2;
		if (s[i] == '"')
			d_quotes++;
		if (d_quotes % 2 == 0 && s[i + 1] && s[i + 1] == ' ')
			return (++i);
		i++;
	}
	return (i);
}


int	check_single_quotes(char *s, int len, int i, t_attr *att)
{
	int	s_quotes;

	s_quotes = 0;
	att->nb_tokens++;
	if (s[i + 1] && s[i + 1] == '\''
		&& ((s[i + 2] && s[i + 2] == ' ') || !s[i + 2]))
		return (i + 2);
	while (i <= len)
	{
		if (s[i] == '\'')
			s_quotes++;
		if (s_quotes % 2 == 0 && s[i + 1] && s[i + 1] == ' ')
			return (++i);
		i++;
	}
	return (i);
}

int	count_tokens(char *s, t_attr *att)
{
	int	len;
	int	i;

	// count_quotes(s, att);
	len = ft_strlen(s) - 1;
	i = 0;
	while (i <= len)
	{
		//single quote
		if (s[i] == '\'')
			i = check_single_quotes(s, len, i, att);
	
		// double quote
		else if (s[i] == '"')
			i = check_double_quotes(s, len, i, att);
		//common token, solo caratteri senza tanti frenzoli
		else if (s[i] != ' ')
		{
			i = check_normal_char(s, len, i, att);
			// printf("sono dentro normal");
		}
		else
			i++;
	}
	return (att->nb_tokens);
}

