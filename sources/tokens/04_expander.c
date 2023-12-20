/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:48 by pfalasch          #+#    #+#             */
/*   Updated: 2023/12/20 15:34:23 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questo è da aggiornare con la lista */

void copy_expanded_str(t_attr *att, int len_name_var, int flag)
{
	t_list *current = att->env_list;
	printf("questa è il content della prima exp: %s\n", att->env_list->content);
	printf("numero del nodo: %d\n", att->env_list->$flag);
	if (flag == 2)
	{
		while (att->env_list->$flag != att->save_y_mx_envp[att->i_flag$])
			att->env_list = att->env_list->next;
	}
	att->y_mx_envp = att->save_y_mx_envp[att->i_flag$];
	att->x_mx_envp = len_name_var + 1;
	while (att->env_list->content[att->x_mx_envp])
	{
		att->arr2[att->y2][att->x2++] = att->env_list->content[att->x_mx_envp++];
	}
	att->env_list = current;
	return;
}

/* questa è da aggiornare con la lista */

void count_expanded_token_02(t_attr *att)
{
	t_list *current = att->env_list;
	while (att->env_list != NULL)
	{
		if (!ft_strncmp(att->check_exp, att->env_list->content, att->len_call_exp))
		{
			while (att->env_list->content[att->x_mx_envp])
			{
				att->mem_space++;
				att->x_mx_envp++;
			}
			free(att->check_exp);
			att->save_y_mx_envp[att->i_flag$] = att->env_list->$flag;
			att->env_list = current;
			return;
		}
		att->env_list = att->env_list->next;
		att->y_mx_envp++;
	}
}

void count_expanded_token(t_attr *att, char *s)
{
	int start;
	int j;

	j = 0;
	start = att->i; // mi salvo il valore iniziale.
	while (s[att->i] != '"' && s[att->i] != ' '
			&& s[att->i] != '$' && s[att->i])
		att->i++;
	att->len_call_exp = att->i - start + 1; // +1 perchè c'è anche l'uguale
	att->check_exp = malloc(sizeof(char) * att->len_call_exp + 1);
	att->i = start;
	while (j < att->len_call_exp && s[att->i] != '"' && s[att->i] != ' ' && s[att->i] != '$' && s[att->i])
		att->check_exp[j++] = s[att->i++];
	att->check_exp[j] = '=';
	att->check_exp[j + 1] = '\0';
	att->y_mx_envp = 0;
	att->x_mx_envp = att->len_call_exp;
	count_expanded_token_02(att);
	att->mem_space++;
	// printf("ERRORE CONTROLLA COUNT_EXPANDED_TOKEN\n");
	return ;
}
