/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_wrong_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:52 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 11:52:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int error_dollar_01(char *s, t_attr *att)
{
	int i;

	i = 0;
	if (count_dollar_sign(s, att) != 0)
	{
		att->save_y_mx_envp = malloc(sizeof(int) * att->nb_$);
		att->flag$ = malloc(sizeof(int) * att->nb_$);
		while(i < att->nb_$)
			att->flag$[i++] = 0;
		if (!att->flag$ && !att->save_y_mx_envp)
			return (1);
		att->i_flag$ = 0;
	}
	return (0);
}

int error_dollar_00(char *s, int i, t_attr *att)
{
	if (s[i + 1] == '$') // controllo $$
	{
		att->flag$[att->i_flag$++] = -1;
		att->flag$[att->i_flag$] = -1;
		i += 2;
	}
	else if (error_dollar_02(s, i, att) == -1)
		att->flag$[att->i_flag$] = -1;
	else
	{
		i += error_dollar_02(s, i, att);
	}
	att->i_flag$++;
	return (i);
}

int error_dollar(char *s, t_attr *att)
{
	int i;

	if (error_dollar_01(s, att))
		return (1);
	i = 0;
	while (s[i] && att->i_flag$ < att->nb_$)
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
				i++;
		}
		else if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1] && s[i +1] != '"')
			i += error_dollar_00(s, i, att);
		i++;
	}
	return (0);
}
