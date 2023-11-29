/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:09:43 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/29 19:41:48 by pfalasch         ###   ########.fr       */
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


void ft_count_words(char *s, t_attr *att)
{
	int len;
	int i;

	i = 0;
	att->count_words = 0;
	len = ft_strlen(s) - 1;
	while (i <= len)
	{
		if (s[i] == '\'')
			i = check_single_quotes(s, len, i, att);
		else if (s[i] == '"')
			i = check_double_quotes(s, len, i, att);
		else if (s[i] != ' ')
			i = check_no_space(s, len, i, att);
		else
			i++;
	}
}