/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:48 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/27 17:19:07 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int copy_expanded_str(t_attr *att, char *s, int start)
{
	att->x_mx_envp = start + att->len_call_exp + 1;
	while (att->mx_envp[att->y_mx_envp][att->x_mx_envp])
		att->arr2[att->y2][att->x2++] = att->mx_envp[att->y_mx_envp][att->x_mx_envp++];
	return (att->len_call_exp + 1);
}

int count_expanded_token(t_attr *att, char *s, int i)
{
	att->len_call_exp = i;
	while (s[att->len_call_exp] != '"' || s[att->len_call_exp] != ' ' || s[att->len_call_exp] != '$' || s[att->len_call_exp])
		att->len_call_exp++;
	att->check_exp = malloc(sizeof(char) * att->len_call_exp + 1);
	while (i < att->len_call_exp)
	{
		att->check_exp[i] = s[i];
		i++;
	}
	att->check_exp[i] = '\0';
	att->y_mx_envp = 0;
	att->x_mx_envp = att->len_call_exp + 2;
	while (att->mx_envp[att->y_mx_envp])
	{
		if (ft_strncmp(att->check_exp, att->mx_envp[att->y_mx_envp], att->len_call_exp))
		{
			while (att->mx_envp[att->y_mx_envp][att->x_mx_envp])
			{
				att->memory_space++;
				att->x_mx_envp++;
			}
			return (att->len_call_exp + 1);
		}
		att->y_mx_envp++;
	}
	att->memory_space++;
	return (1);
}