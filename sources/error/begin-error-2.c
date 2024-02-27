/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin-error-2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:12:15 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:02:18 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int next_chars_check(char *c, t_attr *strc)
{
	if (ft_is_space(s) == 0)
		return (nl_error(strc));
	else
		return (0);
}

int begin_error_2(char *c, t_attr *strc)
{
	int j;
	j = 0;
	while (!(*c > 32 && *c < 127))
		c++;
	if (c[j] == '>' || c[j] == '<')
	{
		if ((c[j] == '>' && c[j + 1] == '>') || (c[j] == '<' && c[j + 1] == '<'))
		{
			c += 2;
			if (next_chars_check(c, strc))
			{
				// printf("sono qui1\n");
				return (1);
			}
		}
		else
		{
			c++;
			if (next_chars_check(c, strc))
				return (1);
		}
	}
	return (0);
}
