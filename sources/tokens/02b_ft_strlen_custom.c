/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02b_ft_strlen_custom.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:37:05 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/19 11:43:31 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_count_exp_print_error(t_attr *att)
{
	att->mem_space = ft_intsize(g_value);
	att->i += 2;
	att->i_flag$++;
}
void ft_strlen_double_quotes(char *s, t_attr *att)
{
	att->i++;
	att->mem_space++; // questo per aggiungere un char delle quotes
	while (s[att->i] != '"')
	{
		if (s[att->i] == '$' && s[att->i + 1] == '?')
			ft_count_exp_print_error(att);
		if (s[att->i] == '$' && s[att->i + 1] != ' ' && s[att->i + 1] && s[att->i + 1] != '"')
		{
			att->i++;
			if (att->flag$[att->i_flag$] == 0)
				count_expanded_token(att, s);
			else
			{
				while (s[att->i] != '"' && s[att->i] != ' ' && s[att->i] != '$' && s[att->i])
					att->i++;
				att->save_y_mx_envp[att->i_flag$] = -1;
			}
			att->i_flag$++;
		}
		else
		{
			att->mem_space++;
			att->i++;
		}
		att->mem_space++; //questo per aggiungere un char delle quotes
	}
}

void ft_strlen_no_quotes(char *s, t_attr *att)
{
	printf("PORCODIO%s\n", s);
	while (s[att->i] && s[att->i] != ' ')
	{
		if (s[att->i] == '$' && s[att->i + 1] == '?')
			ft_count_exp_print_error(att);
		if (s[att->i] == '$' && s[att->i + 1] != ' ' && s[att->i + 1])
		{
			att->i++;
			printf("----%d---%d\n", att->flag$[att->i_flag$], att->i_flag$);
			if (att->flag$[att->i_flag$] == 0)
				count_expanded_token(att, s);
			else
			{
				while (s[att->i] != '"' && s[att->i] != ' ' && s[att->i] != '$' && s[att->i])
					att->i++;
			}
			att->i_flag$++;
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
	save_$ = att->i_flag$;
	printf("flagfflagffalg----%d\n", att->i_flag$);
	if (flag == 0)
		ft_strlen_no_quotes(s, att);
	if (flag == 1)
	{
		att->i++;
		att->mem_space++;
		while (s[att->i] != '\'')
		{
			att->mem_space++;
			att->i++;
		}
		att->mem_space++;
	}
	if (flag == 2)
		ft_strlen_double_quotes(s, att);
	att->i_flag$ = save_$;
	return (att->mem_space);
}
