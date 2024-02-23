/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-quotes-error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:36:28 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 11:36:30 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	double_quotes_counter(char *c)
{
	int	j;
	int	quotes_counter;

	j = 0;
	quotes_counter = 0;
	while (c[j])
	{
		if (c[j] == '\'' && (quotes_counter % 2 == 0))
		{
			j++;
			while (c[j] != '\'' && c[j])
				j++;
		}
		else if (c[j] == '\\' && c[j + 1] == '"')
			j += 2;
		if (c[j] == '"')
			quotes_counter++;
		j++;
	}
	if (quotes_counter % 2 != 0)
	{
		printf("error unclosed quotes\n");
		return (1);
	}
	return (0);
}

int	single_quotes_counter(char *src)
{
	int	j;
	int	quotes_counter;

	quotes_counter = 0;
	j = 0;
	while (src[j])
	{
		if (src[j] == '"' && quotes_counter % 2 == 0)
		{
			j++;
			while (src[j] != '"' && src[j])
				j++;
		}
		if (src[j] == '\\' && src[j + 1] == '\'')
			j += 2;
		if (src[j] == '\'')
			quotes_counter++;
		j++;
	}
	if (quotes_counter % 2 != 0)
	{
		printf("error unclosed quotes\n");
		return (1);
	}
	return (0);
}

int	quotes_counter(char *c)
{
	if (single_quotes_counter(c))
		return (-1);
	if (double_quotes_counter(c))
		return (-1);
	return (0);
}
