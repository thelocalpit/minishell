/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03-words-count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:09:43 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 11:52:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_special(int j, t_attr *strct)
{
	strct->words_counter++;
	j += 2;
	return (j);
}

int	double_quotes_check(char *c, int n, int j, t_attr *strct)
{
	strct->words_counter++;
	j++;
	if (c[j] == '"' && (c[j + 1] == ' ' || !c[j + 1]))
		return (j + 1);
	while (j <= n && c[j] != '"')
	{
		if (c[j] == '\\' && c[j + 1] == '"')
			j += 2;
		else
			j++;
	}
	return (++j);
}

int	single_quotes_check(char *c, int n, int j, t_attr *strct)
{
	strct->words_counter++;
	j++;
	if (c[j] == '\'' && (c[j + 1] == ' ' || !c[j + 1]))
		return (j + 1);
	while (j <= n && c[j] != '\'')
		j++;
	return (++j);
}

int	no_space(char *c, int num, int j, t_attr *strct)
{
	strct->words_counter++;
	while (j <= num && c[j] != ' ')
		j++;
	return (++j);
}

/* questa ft serve per il conto di elementi. necessaria per allocare
	la giusta quantità di memoria */
void	counter_words(char *c, t_attr *strct)
{
	int	num;
	int	j;

	j = 0;
	strct->words_counter = 0;
	num = ft_strlen(c) - 1;
	while (j <= num)
	{
		if (c[j] == '\'')
			j = single_quotes_check(c, num, j, strct);
		else if (c[j] == '"')
			j = double_quotes_check(c, num, j, strct);
		else if (c[j] != ' ')
			j = no_space(c, num, j, strct);
		else
			j++;
	}
}
