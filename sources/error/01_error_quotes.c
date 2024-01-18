/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_error_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:01:14 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/17 20:22:09 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int count_single_quotes(char *s)
{
	int i;
	int count_quotes;
	
	count_quotes = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
			if (s[i])
				return (1);
		}
		if (s[i] == '\\' && s[i + 1] == '\'')
			i += 2;
		if (s[i] == '\'')
			count_quotes++;
		i++;
	}
	if (count_quotes % 2 != 0)
		return (1);
	return (0);
}

/* se le quotes sono dispari */
int count_double_quotes(char *s)
{
	int i;
	int count_quotes;
	int flag;

	flag = 0;
	i = 0;
	count_quotes = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			flag = 1;
		if (flag == 1 && s[i] == '\'')
		if (s[i] == '\\' && s[i + 1] == '"')
			i += 2;
		// if (s[i] == '\'')
		// {
		// 	i++;
		// 	while (s[i] != '\'' && s[i])
		// 		i++;
		// 	if (s[i])
		// 		return (1);
		// }
		if (s[i] == '"')
			count_quotes++;
		i++;
	}
	if (count_quotes % 2 != 0)
		return (1);
	return (0);
}

/* controllo delle quotes */
int count_quotes(char *s)
{
	if (count_single_quotes(s))
		return (-1);
	if (count_double_quotes(s))
		return (-1);
	return (0);
}
