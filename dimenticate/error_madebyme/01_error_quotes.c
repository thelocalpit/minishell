/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_error_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:01:14 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/16 16:01:58 by pfalasch         ###   ########.fr       */
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