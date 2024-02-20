/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:18:48 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:51:36 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione copia dalla lista delle variabili d'abiente nella
	nostra matrice array2.
	potevo scriverla meglio? SI.
	Funziona? SI.
	la riscriverò? COL CAZZO IMPANATO CON LE PATATE. */
void copy_expanded_str(t_attr *att, int len_name_var)
{
	t_list *tmp_list;

	if (att->list_flag == 0)
	{
		tmp_list = att->env_list;

		while (tmp_list && tmp_list->dol_flag != att->save_y_mtx_envp[att->i_flag_dol])
			tmp_list = tmp_list->next;
		att->x_mtx_envp = len_name_var + 1;
		while (tmp_list && tmp_list->content[att->x_mtx_envp])
			att->array2[att->y2][att->x2++] = tmp_list->content[att->x_mtx_envp++];
		return;
	}
	else
	{
		tmp_list = att->local_list;
		while (tmp_list && tmp_list->dol_flag != att->save_y_mtx_envp[att->i_flag_dol])
			tmp_list = tmp_list->next;
		att->x_mtx_envp = len_name_var + 1;
		while (tmp_list && tmp_list->content[att->x_mtx_envp])
			att->array2[att->y2][att->x2++] = tmp_list->content[att->x_mtx_envp++];
		att->list_flag = 0;
		return;
	}
}

void counter_expanded_token_local_list(t_attr *att)
{
	t_list *tmp_list;

	tmp_list = att->local_list;
	while (att->local_list != NULL)
	{
		if (!ft_strncmp(att->check_exp, att->local_list->content, att->len_call_exp))
		{
			while (att->local_list->content[att->x_mtx_envp])
			{
				att->mem_space++;
				att->x_mtx_envp++;
			}
			free(att->check_exp);
			att->save_y_mtx_envp[att->i_flag_dol] = att->local_list->dol_flag;
			att->local_list = tmp_list;
			return;
		}
		att->local_list = att->local_list->next;
		att->y_mtx_envp++;
	}
}
int counter_expanded_token_02(t_attr *att)
{
	t_list *tmp_list;

	tmp_list = att->env_list;
	while (tmp_list != NULL)
	{
		if (!ft_strncmp(att->check_exp, tmp_list->content, att->len_call_exp))
		{
			while (tmp_list->content[att->x_mtx_envp])
			{
				att->mem_space++;
				att->x_mtx_envp++;
			}
			free(att->check_exp);
			att->save_y_mtx_envp[att->i_flag_dol] = tmp_list->dol_flag;
			return (0);
		}
		tmp_list = tmp_list->next;
		att->y_mtx_envp++;
	}
	att->y_mtx_envp = 0;
	return (-1);
}
/* questa funzione conta quanta memoria devo allocare per l'exp.
	mi devo calcolare la lunghezza del nome ed escluderla (check_exp)
	poi in ft:strncmp faccio un strncmp e trovo la variabile
	d'ambiente giusta per calcolo quanto necessario per allocare la
	memoria. */
void counter_expanded_token(t_attr *att, char *s)
{
	int start;
	int j;
	j = 0;
	start = att->i;
	while (s[att->i] != '"' && s[att->i] != ' '
			&& s[att->i] != '$' && s[att->i])
		att->i++;
	att->len_call_exp = att->i - start + 1;
	att->check_exp = malloc(sizeof(char) * att->len_call_exp + 1);
	att->i = start;
	while (j < att->len_call_exp && s[att->i] != '"' && s[att->i] != ' ' && s[att->i] != '$' && s[att->i])
		att->check_exp[j++] = s[att->i++];
	att->check_exp[j] = '=';
	att->check_exp[j + 1] = '\0';
	att->y_mtx_envp = 0;
	att->x_mtx_envp = att->len_call_exp;
	if (counter_expanded_token_02(att) == -1)
	{
		att->list_flag = 1;
		counter_expanded_token_local_list(att);
	}
	att->mem_space++;
	return ;
}
