/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:48 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/28 00:46:03 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int copy_expanded_str(t_attr *att, int start)
{
	att->x_mx_envp = start + att->len_call_exp;
	while (att->mx_envp[att->y_mx_envp][att->x_mx_envp])
		att->arr2[att->y2][att->x2++] = att->mx_envp[att->y_mx_envp][att->x_mx_envp++];
	return (att->len_call_exp + 1);
}

int count_expanded_token(t_attr *att, char *s, int i)
{
	i++;
	att->len_call_exp = i;
	// printf("questo è il n di i: %d\n", i);
	while (s[att->len_call_exp] != '"' && s[att->len_call_exp] != ' ' && s[att->len_call_exp] != '$' && s[att->len_call_exp])
	{
		// printf("sono qui\n");
		att->len_call_exp++;
	}
	att->len_call_exp--;
	// printf("questo è il n di len_call_exp: %d\n", att->len_call_exp);
	att->check_exp = malloc(sizeof(char) * att->len_call_exp + 2);
	while (i <= att->len_call_exp)
	{
		// printf("sono qui\n");
		// printf("questo è il n di i: %d\n", i);
		att->check_exp[i -1] = s[i];
		// write(1, &s[i], 1);
		i++;
	}
	att->check_exp[i - 1] = '=';
	att->check_exp[i] = '\0';
	// printf("questo è check_exp: %s\n", att->check_exp);
	att->y_mx_envp = 0;
	att->len_call_exp++;
	att->x_mx_envp = att->len_call_exp;
	while (att->mx_envp[att->y_mx_envp])
	{
		if (!ft_strncmp(att->check_exp, att->mx_envp[att->y_mx_envp], att->len_call_exp))
		{
			// printf("questa è la stringa che viene passata: %c\n", att->mx_envp[att->y_mx_envp][att->x_mx_envp]);
			while (att->mx_envp[att->y_mx_envp][att->x_mx_envp])
			{
				att->memory_space++;
				att->x_mx_envp++;
			}
			free(att->check_exp);
			return (att->len_call_exp + 1);
		}
		att->y_mx_envp++;
	}
	att->memory_space++;
	return (1);
}