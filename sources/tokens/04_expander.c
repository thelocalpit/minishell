/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:48 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/19 18:51:55 by pfalasch         ###   ########.fr       */
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

	if (att->flag_list == 0)
	{
		current = att->env_list;
		while (att->env_list->id != att->save_id_node[att->i_flag$])
			att->env_list = att->env_list->next;
		att->j_env = len_name_var + 1;
		while (att->env_list->content[att->j_env])
			att->arr2[att->y2][att->x2++] = att->env_list->content[att->j_env++];
		att->env_list = current;
		return;
	}
	else
	{
		current = att->local_var;
		while (att->local_var->id != att->save_id_node[att->i_flag$])
			att->local_var = att->local_var->next;
		att->j_env = len_name_var + 1;
		while (att->local_var->content[att->j_env])
			att->arr2[att->y2][att->x2++] = att->local_var->content[att->j_env++];
		att->local_var = current;
		att->flag_list = 0;
		return;
	}
}

void count_expanded_token_local_var(t_attr *att)
{
	t_list *current;

	current = att->local_var;
	while (att->local_var != NULL)
	{
		if (!ft_strncmp(att->str, att->local_var->content, att->len))
		{
			while (att->local_var->content[att->j_env])
			{
				att->mem_space++;
				att->j_env++;
			}
			free(att->str);
			att->save_id_node[att->i_flag$] = att->local_var->id;
			att->local_var = current;
			return;
		}
		att->local_var = att->local_var->next;
		att->i_env++;
	}
}

int count_expanded_token_02(t_attr *att)
{
	t_list *current;
	
	current = att->env_list;
	while (att->env_list != NULL)
	{
		if (!ft_strncmp(att->str, att->env_list->content, att->len))
		{
			while (att->env_list->content[att->j_env])
			{
				att->mem_space++;
				att->j_env++;
			}
			free(att->str);
			att->save_id_node[att->i_flag$] = att->env_list->id;
			att->env_list = current;
			return (0);
		}
		att->env_list = att->env_list->next;
		att->i_env++;
	}
	att->i_env = 0;
	att->env_list = current;
	return (-1);
}

/* questa funzione conta quanta memoria devo allocare per l'exp.
	mi devo calcolare la lunghezza del nome ed escluderla (str)
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
	att->len = att->i - start + 1; // +1 perchè c'è anche l'uguale
	att->str = malloc(sizeof(char) * att->len + 1);
	att->i = start;
	while (j < att->len && s[att->i] != '"' && s[att->i] != ' ' && s[att->i] != '$' && s[att->i])
		att->str[j++] = s[att->i++];
	att->str[j] = '=';
	att->str[j + 1] = '\0';
	att->i_env = 0;
	att->j_env = att->len;
	if (count_expanded_token_02(att) == -1)
	{
		att->flag_list = 1;
		count_expanded_token_local_var(att);
	}
	att->mem_space++;
	return ;
}
