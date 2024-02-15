/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_begin_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:12:15 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/15 16:16:31 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int check_next_chars(char *s)
{
	if (ft_isspace(s) == 0)
		return (return_nl_error());
	else
		return (0);
}
/* questo serve per controllare che non ci sia solo '>' '<' senza argomenti e altro.
	andava in segfault */
int error_begin_02(char *s)
{
	int i;

	i = 0;
	while (!(*s > 32 && *s < 127))
		s++;
	if (s[i] == '>' || s[i] == '<')
	{
		if ((s[i] == '>' && s[i + 1] == '>') || (s[i] == '<' && s[i + 1] == '<'))
		{
			s += 2;
			if (check_next_chars(s))
				return (1);
		}
		else
		{
			s++;
			if (check_next_chars(s))
				return (1);
		}
	}
	return (0);
}