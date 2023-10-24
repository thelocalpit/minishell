/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_verify_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:43:57 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/24 18:28:11 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int count_quotes(char *s)
{
	int i;
	int count_quotes;

	count_quotes = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			count_quotes++;
		i++;
	}
	if (count_quotes % 2 != 0)
		return (1);
	i = 0;
	count_quotes = 0;
	while (s[i])
	{
		if (s[i] == '\\' && s[i + 1] == '"')
			i += 2;
		if (s[i] == '"')
			count_quotes++;
		i++;
	}
	if (count_quotes % 2 != 0)
		return (1);
	return (0);
}

int	verify_readline(char *s)
{
	if (count_quotes(s))
	{
		printf(ERROR_UNCLOSED);
		return (1);
	}
	return (0);
}