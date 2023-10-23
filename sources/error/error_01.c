/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:43:57 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/22 13:49:58 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_error_quotes(t_attr *att)
{
	att->flag_err_quote = 1;
	printf(ERROR_UNCLOSED);
}

int	error_double_quote( char *s)
{
	int 	i;
	int 	flag;
	char 	c;

	flag = 0;
	i = 0;
	c = '"';
	while (s[i])
	{
		if (s[i] == '\\' && s[i + 1] == '"')
			i += 2;
		if (s[i] == c && flag == 0)
			flag = 1;
		else if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	if (flag == 1)
	{
		return (1);
		printf(ERROR_UNCLOSED);
	}
	return (0);
}

int	error_single_quote(char *s)
{
	int		i;
	int		flag;
	char	c;

	flag = 0;
	i = 0;
	c = '\'';
	while (s[i])
	{
		if (s[i] == c && flag == 0)
			flag = 1;
		else if (s[i] == c && flag == 1)
			flag = 0;
		i++;
	}
	if (flag == 1)
	{
		return (1);
		printf(ERROR_UNCLOSED);
	}
	return (0);
}

int	verify_readline(char *s)
{
	if (error_single_quote(s) || error_double_quote(s))
	{
		// g_value = 2;
		return (1);
	}
	return (0);
}