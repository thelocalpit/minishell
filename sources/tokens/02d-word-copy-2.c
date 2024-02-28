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

int ft_strlen_name_var(char *c, int *j, int name_var_len)
{
	name_var_len = (*j);
	while (c[*j] != '"' && c[*j] != ' ' && c[*j] != '$' && c[*j])
		(*j)++;
	name_var_len = (*j) - name_var_len;
	return (name_var_len);
}

int copy_g_value(t_attr *strct, int j)
{
	ft_itoa_custom(strct->value, strct);
	j += 2;
	return (j);
}

int copy_double_dollar(int j, t_attr *strct)
{
	j += 2;
	strct->i_flag_dol += 2;
	strct->array2[strct->y2][strct->x2++] = '$';
	strct->array2[strct->y2][strct->x2++] = '$';
	return (j);
}
