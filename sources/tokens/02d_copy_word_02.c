/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02d_copy_word_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:41:38 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 11:52:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_strlen_name_var(char *s, int *i, int len_name_var)
{
	len_name_var = (*i);
	while (s[*i] != '"' && s[*i] != ' ' && s[*i] != '$' && s[*i])
		(*i)++;
	len_name_var = (*i) - len_name_var;
	return (len_name_var);
}

int copy_g_value(t_attr *att, int i)
{
	ft_itoa_custom(att->g_value, att);
	i += 2;
	return (i);
}

int copy_double_dollar(int i, t_attr *att)
{
	i += 2;
	att->i_flag$ += 2;
	att->arr2[att->y2][att->x2++] = '$';
	att->arr2[att->y2][att->x2++] = '$';
	return (i);
}
