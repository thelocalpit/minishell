/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_words_counter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:09:43 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 11:52:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_single_quotes(char *s, int len, int i, t_attr *att)
{
	att->words_counter++;
	i++;
	if (s[i] == '\'' && (s[i + 1] == ' ' || !s[i + 1]))
		return (i + 1);
	while (i <= len && s[i] != '\'')
		i++;
	return (++i);
}

int	check_double_quotes(char *s, int len, int i, t_attr *att)
{
	att->words_counter++;
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
int	check_special(int i, t_attr *att)
{
	att->words_counter++;
	i += 2;
	return (i);
}

int	check_no_space(char *s, int len, int i, t_attr *att)
{
	att->words_counter++;
	while (i <= len && s[i] != ' ')
		i++;
	return (++i);
}

/* questa ft serve per il conto di elementi. necessaria per allocare
	la giusta quantità di memoria */
void	ft_words_counter(char *s, t_attr *att)
{
	int	len;
	int	i;

	i = 0;
	att->words_counter = 0;
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
