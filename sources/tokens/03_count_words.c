/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:09:43 by pfalasch          #+#    #+#             */
/*   Updated: 2023/12/05 14:47:48 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int check_single_quotes(char *s, int len, int i, t_attr *att)
{
	att->count_words++;
	i++;
	if (s[i] == '\'' && (s[i + 1] == ' ' || !s[i + 1]))
		return (i + 1);
	while (i <= len && s[i] != '\'')
		i++;
	return (++i);
}

int check_double_quotes(char *s, int len, int i, t_attr *att)
{
	att->count_words++;
	i++;
	if (s[i] == '"' && (s[i + 1] == ' ' || !s[i + 1]))
		return (i + 1);
	while (i <= len && s[i] != '"')
	{
		if (s[i] == '\\' && s[i + 1] == '"')
			i += 2;
		else
			i++;
	}
	return (++i);
}

int check_no_space(char *s, int len, int i, t_attr *att)
{
	att->count_words++;
	while (i <= len && s[i] != ' ')
		i++;
	return (++i);
}

int check_dollar(char *s, int len, int i, t_attr *att)
{
	att->count_words++;
	i++;
	while (i <= len && s[i] != '$' && s[i] !=  ' ' && s[i] != '\'' && s[i] != '"')
		i++;
	return (++i);
}


void ft_count_words(char *s, t_attr *att)
{
	int len;
	int i;

	i = 0;
	att->count_words = 0;
	len = ft_strlen(s) - 1;
	att->j_flag$ = att->i_flag$;
	while (i <= len)
	{
		if (s[i] == '\'')
			i = check_single_quotes(s, len, i, att);
		else if (s[i] == '"')
			i = check_double_quotes(s, len, i, att);
		else if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1])
			i = check_dollar(s, len, i, att);
		else if (s[i] != ' ')
			i = check_no_space(s, len, i, att);
		else
			i++;
	}
	att->i_flag$ = att->j_flag$;
}
