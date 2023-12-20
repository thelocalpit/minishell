/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:48 by pfalasch          #+#    #+#             */
/*   Updated: 2023/12/20 18:28:48 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione copia dalla lista delle variabili d'abiente nella
	nostra matrice arr2. 
	potevo scriverla meglio? SI.
	Funziona? SI.
	la riscriverò? COL CAZZO IMPANATO CON LE PATATE. */

void copy_expanded_str(t_attr *att, int len_name_var)
{
	t_list *current;

	current = att->env_list;
	while (att->env_list->$flag != att->save_y_mx_envp[att->i_flag$])
		att->env_list = att->env_list->next;
	att->x_mx_envp = len_name_var + 1;
	while (att->env_list->content[att->x_mx_envp])
		att->arr2[att->y2][att->x2++] = att->env_list->content[att->x_mx_envp++];
	att->env_list = current;
	return;
}


void count_expanded_token_02(t_attr *att)
{
	t_list *current;
	
	current = att->env_list;
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

/* questa funzione conta quanta memoria devo allocare per l'exp.
	mi devo calcolare la lunghezza del nome ed escluderla (check_exp)
	poi in ft:strncmp faccio un strncmp e trovo la variabile 
	d'ambiente giusta per calcolo quanto necessario per allocare la
	memoria. */
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
	return ;
}
