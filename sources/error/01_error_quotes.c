/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_error_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:01:14 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 12:10:37 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	counter_single_quotes(char *s)
{
	int	i;
	int	counter_quotes;

	counter_quotes = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"' && counter_quotes % 2 == 0)
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
		}
		if (s[i] == '\\' && s[i + 1] == '\'')
			i += 2;
		if (s[i] == '\'')
			counter_quotes++;
		i++;
	}
	if (counter_quotes % 2 != 0)
	{
		printf("error unclosed quotes\n");
		return (1);
	}
	return (0);
}

/* se le quotes sono dispari */
int	counter_double_quotes(char *s)
{
	int	i;
	int	counter_quotes;

	i = 0;
	counter_quotes = 0;
	while (s[i])
	{
		if (s[i] == '\'' && (counter_quotes % 2 == 0))
		{
			i++;
			while (s[i] != '\'' && s[i])
				i++;
		}
		else if (s[i] == '\\' && s[i + 1] == '"')
			i += 2;
		if (s[i] == '"')
			counter_quotes++;
		i++;
	}
	if (counter_quotes % 2 != 0)
	{
		printf("error unclosed quotes\n");
		return (1);
	}
	return (0);
}

/* controllo delle quotes */
int	counter_quotes(char *s)
{
	if (counter_single_quotes(s))
		return (-1);
	if (counter_double_quotes(s))
		return (-1);
	return (0);
}
