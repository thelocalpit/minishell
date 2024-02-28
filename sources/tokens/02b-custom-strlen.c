/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02b-custom-ft-strlen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:37:05 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:52:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_counter_exp_print_error(t_attr *strct)
{
	strct->mem_space = ft_intsize(strct->value);
	strct->i += 2;
	strct->i_flag_dol++;
}

void double_dollar(t_attr *strct)
{
	strct->mem_space += 2;
	strct->i += 2;
	strct->save_y_mtx_envp[strct->i_flag_dol++] = -1;
	strct->save_y_mtx_envp[strct->i_flag_dol++] = -1;
}

void ft_strlen_double_quotes_02(char *c, t_attr *strct)
{
	strct->i++;
	if (strct->flag_dol[strct->i_flag_dol] == 0)
		counter_expanded_token(strct, c);
	else
	{
		while (c[strct->i] != '"' && c[strct->i] != ' ' && c[strct->i] != '$' && c[strct->i])
			strct->i++;
		strct->save_y_mtx_envp[strct->i_flag_dol] = -1;
	}
	strct->i_flag_dol++;
}

void ft_strlen_double_quotes(char *c, t_attr *strct)
{
	strct->i++;
	while (c[strct->i] != '"')
	{
		if (c[strct->i] == '$' && c[strct->i + 1] == '$')
			double_dollar(strct);
		else if (c[strct->i] == '$' && c[strct->i + 1] == '?')
			ft_counter_exp_print_error(strct);
		else if (c[strct->i] == '$' && c[strct->i + 1] != ' ' && c[strct->i + 1] && c[strct->i + 1] != '"')
			ft_strlen_double_quotes_02(c, strct);
		else
		{
			strct->mem_space++;
			strct->i++;
		}
	}
}

void ft_strlen_no_quotes(char *c, t_attr *strct)
{
	while (c[strct->i] && c[strct->i] != ' ')
	{
		if (c[strct->i] == '$' && c[strct->i + 1] == '$')
			double_dollar(strct);
		else if (c[strct->i] == '$' && c[strct->i + 1] == '?')
			ft_counter_exp_print_error(strct);
		else if (c[strct->i] == '$' && c[strct->i + 1] != ' ' && c[strct->i + 1])
		{
			strct->i++;
			if (strct->flag_dol[strct->i_flag_dol] == 0)
				counter_expanded_token(strct, c);
			else
			{
				while (c[strct->i] != '"' && c[strct->i] != ' ' && c[strct->i] != '$' && c[strct->i])
					strct->i++;
			}
			strct->i_flag_dol++;
		}
		else
		{
			strct->mem_space++;
			strct->i++;
		}
	}
}

int ft_strlen_custom(char *c, int num, t_attr *strct)
{
	int save_$;

	save_$ = 0;
	strct->mem_space = 0;
	strct->i = 0;
	if (!c)
		return (0);
	save_$ = strct->i_flag_dol;
	if (num == 0)
		ft_strlen_no_quotes(c, strct);
	if (num == 1)
	{
		strct->i++;
		while (c[strct->i] != '\'')
		{
			strct->mem_space++;
			strct->i++;
		}
	}
	if (num == 2)
		ft_strlen_double_quotes(c, strct);
	strct->i_flag_dol = save_$;
	return (strct->mem_space);
}