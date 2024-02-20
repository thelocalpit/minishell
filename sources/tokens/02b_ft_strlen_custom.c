/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02b_ft_strlen_custom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:37:05 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:52:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_counter_exp_print_error(t_attr *att)
{
	att->mem_space = ft_intsize(att->value);
	att->i += 2;
	att->i_flag_dol++;
}

void double_dollar(t_attr *att)
{
	att->mem_space += 2;
	att->i += 2;
	att->save_y_mtx_envp[att->i_flag_dol++] = -1;
	att->save_y_mtx_envp[att->i_flag_dol++] = -1;
}
void ft_strlen_double_quotes_02(char *s, t_attr *att)
{
	att->i++;
	if (att->flag_dol[att->i_flag_dol] == 0)
		counter_expanded_token(att, s);
	else
	{
		while (s[att->i] != '"' && s[att->i] != ' ' && s[att->i] != '$' && s[att->i])
			att->i++;
		att->save_y_mtx_envp[att->i_flag_dol] = -1;
	}
	att->i_flag_dol++;
}
void ft_strlen_double_quotes(char *s, t_attr *att)
{
	att->i++;
	while (s[att->i] != '"')
	{
		if (s[att->i] == '$' && s[att->i + 1] == '$')
			double_dollar(att);
		else if (s[att->i] == '$' && s[att->i + 1] == '?')
			ft_counter_exp_print_error(att);
		else if (s[att->i] == '$' && s[att->i + 1] != ' ' && s[att->i + 1] && s[att->i + 1] != '"')
			ft_strlen_double_quotes_02(s, att);
		else
		{
			att->mem_space++;
			att->i++;
		}
	}
}



void ft_strlen_no_quotes(char *s, t_attr *att)
{
	while (s[att->i] && s[att->i] != ' ')
	{
		if (s[att->i] == '$' && s[att->i + 1] == '$')
			double_dollar(att);
		else if (s[att->i] == '$' && s[att->i + 1] == '?')
			ft_counter_exp_print_error(att);
		else if (s[att->i] == '$' && s[att->i + 1] != ' ' && s[att->i + 1])
		{
			att->i++;
			if (att->flag_dol[att->i_flag_dol] == 0)
				counter_expanded_token(att, s);
			else
			{
				while (s[att->i] != '"' && s[att->i] != ' ' && s[att->i] != '$' && s[att->i])
					att->i++;
			}
			att->i_flag_dol++;
		}
		else
		{
			att->mem_space++;
			att->i++;
		}
	}
}

int ft_strlen_custom(char *s, int flag, t_attr *att)
{
	int save_$;

	save_$ = 0;
	att->mem_space = 0;
	att->i = 0;
	if (!s)
		return (0);
	save_$ = att->i_flag_dol;
	if (flag == 0)
		ft_strlen_no_quotes(s, att);
	if (flag == 1)
	{
		att->i++;
		while (s[att->i] != '\'')
		{
			att->mem_space++;
			att->i++;
		}
	}
	if (flag == 2)
		ft_strlen_double_quotes(s, att);
	att->i_flag_dol = save_$;
	return (att->mem_space);
}



