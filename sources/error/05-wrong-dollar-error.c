/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05-wrong-dollar-errror.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:52 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:25:04 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	dollar_error_00(char *c, int j, t_attr *strct)
{
	if (c[j + 1] == '$')
	{
		strct->flag_dol[strct->i_flag_dol++] = -1;
		strct->flag_dol[strct->i_flag_dol] = -1;
		j += 2;
	}
	else if (dollar_error_2(c, j, strct) == -1)
		strct->flag_dol[strct->i_flag_dol] = -1;
	else
	{
		j += dollar_error_2(c, j, strct);
	}
	strct->i_flag_dol++;
	return (j);
}

int	dollar_error_01(char *c, t_attr *strct)
{
	int	j;

	j = 0;
	if (dollar_sign_counter(c, strct) != 0)
	{
		strct->save_y_mtx_envp = malloc(sizeof(int) * strct->num_dol);
		strct->flag_dol = malloc(sizeof(int) * strct->num_dol);
		while (j < strct->num_dol)
			strct->flag_dol[j++] = 0;
		if (!strct->flag_dol && !strct->save_y_mtx_envp)
			return (1);
		strct->i_flag_dol = 0;
	}
	return (0);
}

int	dollar_error(char *c, t_attr *strct)
{
	int	j;

	if (dollar_error_01(c, strct))
		return (1);
	j = 0;
	while (c[j] && strct->i_flag_dol < strct->num_dol)
	{
		if (c[j] == '\'')
		{
			j++;
			while (c[j] != '\'')
				j++;
		}
		else if (c[j] == '$' && c[j + 1] != ' ' && c[j + 1] && c[j +1] != '"')
			j += dollar_error_00(c, j, strct);
		j++;
	}
	return (0);
}
