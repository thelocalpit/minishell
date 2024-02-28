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

void	ft_double_dollar(t_attr *strct)
{
	strct->mem_space += 2;
	strct->i += 2;
	strct->save_y_mtx_envp[strct->i_flag_dol++] = -1;
	strct->save_y_mtx_envp[strct->i_flag_dol++] = -1;
}

void	double_quotes_strlen2(char *c, t_attr *strct)
{
	strct->i++;
	if (strct->flag_dol[strct->i_flag_dol] == 0)
		expanded_token_counter(strct, c);
	else
	{
		while (c[strct->i] != '"' && c[strct->i] != ' '
			&& c[strct->i] != '$' && c[strct->i])
			strct->i++;
		strct->save_y_mtx_envp[strct->i_flag_dol] = -1;
	}
	strct->i_flag_dol++;
}

void	no_quotes_strlen(char *c, t_attr *strct)
{
	while (c[strct->i] && c[strct->i] != ' ')
	{
		if (c[strct->i] == '$' && c[strct->i + 1] == '$')
			ft_double_dollar(strct);
		else if (c[strct->i] == '$' && c[strct->i + 1] == '?')
			exp_print_counter_error(strct);
		else if (c[strct->i] == '$' && c[strct->i + 1] != ' '
			&& c[strct->i + 1])
		{
			strct->i++;
			if (strct->flag_dol[strct->i_flag_dol] == 0)
				expanded_token_counter(strct, c);
			else
				while (c[strct->i] != '"' && c[strct->i] != ' '
					&& c[strct->i] != '$' && c[strct->i])
					strct->i++;
			strct->i_flag_dol++;
		}
		else
		{
			strct->mem_space++;
			strct->i++;
		}
	}
}

void	double_quotes_strlen(char *c, t_attr *strct)
{
	strct->i++;
	while (c[strct->i] != '"')
	{
		if (c[strct->i] == '$' && c[strct->i + 1] == '$')
			ft_double_dollar(strct);
		else if (c[strct->i] == '$' && c[strct->i + 1] == '?')
			exp_print_counter_error(strct);
		else if (c[strct->i] == '$' && c[strct->i + 1] != ' '
			&& c[strct->i + 1] && c[strct->i + 1] != '"')
			double_quotes_strlen2(c, strct);
		else
		{
			strct->mem_space++;
			strct->i++;
		}
	}
}

int	custom_strlen(char *c, int num, t_attr *strct)
{
	int	save_dol;

	save_dol = 0;
	strct->mem_space = 0;
	strct->i = 0;
	if (!c)
		return (0);
	save_dol = strct->i_flag_dol;
	if (num == 0)
		no_quotes_strlen(c, strct);
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
		double_quotes_strlen(c, strct);
	strct->i_flag_dol = save_dol;
	return (strct->mem_space);
}
