/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02b_ft_strlen_custom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:37:05 by pfalasch          #+#    #+#             */
/*   Updated: 2023/12/16 12:48:58 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_count_exp_print_error(t_attr *att)
{
	att->mem_space = ft_intsize(g_value);
	att->index += 2;
	att->i_flag$++;
}
void ft_strlen_double_quotes(char *s, t_attr *att)
{
	att->index++;
	while (s[att->index] != '"')
	{
		if (s[att->index] == '$' && s[att->index + 1] == '?')
			ft_count_exp_print_error(att);
		if (s[att->index] == '$' && s[att->index + 1] != ' ' && s[att->index + 1] && s[att->index + 1] != '"')
		{
			att->index++;
			if (att->flag$[att->i_flag$] == 0)
				count_expanded_token(att, s);
			else
			{
				while (s[att->index] != '"' && s[att->index] != ' ' && s[att->index] != '$' && s[att->index])
					att->index++;
			}
			att->save_y_mx_envp[att->i_flag$] = att->y_mx_envp;
			att->i_flag$++;
		}
		else
		{
			att->mem_space++;
			att->index++;
		}
	}
}

void ft_strlen_no_quotes(char *s, t_attr *att)
{
	while (s[att->index] != ' ' && s[att->index])
	{
		if (s[att->index] == '$' && s[att->index + 1] == '?')
			ft_count_exp_print_error(att);
		if (s[att->index] == '$' && s[att->index + 1] != ' ' && s[att->index + 1])
		{
			att->index++;
			if (att->flag$[att->i_flag$] == 0)
				count_expanded_token(att, s);
			else
			{
				while (s[att->index] != '"' && s[att->index] != ' ' && s[att->index] != '$' && s[att->index])
					att->index++;
			}
			att->i_flag$++;
		}
		else
		{
			att->mem_space++;
			att->index++;
		}
	}
}

int ft_strlen_custom(char *s, int flag, t_attr *att)
{
	int save_$;

	save_$ = 0;
	att->mem_space = 0;
	att->index = 0;
	if (!s)
		return (0);
	save_$ = att->i_flag$;
	if (flag == 0)
		ft_strlen_no_quotes(s, att);
	if (flag == 1)
	{
		att->index++;
		while (s[att->index] != '\'')
		{
			att->mem_space++;
			att->index++;
		}
	}
	if (flag == 2)
		ft_strlen_double_quotes(s, att);
	att->i_flag$ = save_$;
	return (att->mem_space);
}
