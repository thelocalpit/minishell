/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:48 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/30 18:28:58 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void copy_expanded_str(t_attr *att, int len_name_var)
{
	att->x_mx_envp = len_name_var + 1;
	while (att->mx_envp[att->y_mx_envp][att->x_mx_envp])
		att->arr2[att->y2][att->x2++] = att->mx_envp[att->y_mx_envp][att->x_mx_envp++];
	return ;
}

void count_expanded_token(t_attr *att, char *s)
{
	int start;
	int j;

	j = 0;
	start = att->index; // mi salvo il valore iniziale.
	while (s[att->index] != '"' && s[att->index] != ' ' && s[att->index] != '$' && s[att->index])
	{
		att->index++;
	}
	att->len_call_exp = att->index - start + 1; // +1 perchè c'è anche l'uguale
	att->check_exp = malloc(sizeof(char) * att->len_call_exp + 1);
	att->index = start;
	while (j < att->len_call_exp && s[att->index] != '"' && s[att->index] != ' ' && s[att->index] != '$' && s[att->index])
	{
		att->check_exp[j++] = s[att->index++];
	}
	att->check_exp[j] = '=';
	att->check_exp[j + 1] = '\0';
	// printf("questo è check_exp: %s\n", att->check_exp);
	att->y_mx_envp = 0;
	att->x_mx_envp = att->len_call_exp;
	// printf("index: %d\n", att->index);
	while (att->mx_envp[att->y_mx_envp])
	{
		if (!ft_strncmp(att->check_exp, att->mx_envp[att->y_mx_envp], att->len_call_exp))
		{
			// printf("questa è la stringa che viene passata: %c\n", att->mx_envp[att->y_mx_envp][att->x_mx_envp]);
			while (att->mx_envp[att->y_mx_envp][att->x_mx_envp])
			{
				att->mem_space++;
				att->x_mx_envp++;
			}
			free(att->check_exp);
			// printf("dentro exp. questo è il numero di celle di memoria alloc: %zu\n", att->mem_space);
			return ;
		}
		att->y_mx_envp++;
	}
	att->mem_space++;
	printf("ERRORE CONTROLLA COUNT_EXPANDED_TOKEN\n");
	return ;
}
