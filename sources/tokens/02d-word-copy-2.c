/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02d-word-copy-2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:41:38 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:51:36 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	var_name_strlen(char *c, int *j, int name_var_len)
{
	name_var_len = (*j);
	while (c[*j] != '"' && c[*j] != ' ' && c[*j] != '$' && c[*j])
		(*j)++;
	name_var_len = (*j) - name_var_len;
	return (name_var_len);
}

int	g_value_copy(t_attr *strct, int j)
{
	custom_itoa(strct->value, strct);
	j += 2;
	return (j);
}

int	double_dollar_copy(int j, t_attr *strct)
{
	j += 2;
	strct->i_flag_dol += 2;
	strct->array2[strct->y2][strct->x2++] = '$';
	strct->array2[strct->y2][strct->x2++] = '$';
	return (j);
}
