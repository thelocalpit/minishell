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

void	expanded_token_counter_list(t_attr *strct)
{
	t_list	*tmp;

	tmp = strct->local_list;
	while (strct->local_list != NULL)
	{
		if (!ft_strncmp(strct->check_exp,
				strct->local_list->content, strct->len_call_exp))
		{
			while (strct->local_list->content[strct->xmnvp])
			{
				strct->mem_space++;
				strct->xmnvp++;
			}
			free(strct->check_exp);
			strct->save_y_mtx_envp[strct->i_flag_dol]
				= strct->local_list->dol_flag;
			strct->local_list = tmp;
			return ;
		}
		strct->local_list = strct->local_list->next;
		strct->y_mtx_envp++;
	}
}

/* questa funzione copia dalla lista delle variabili d'abiente nella
	nostra matrice array2.
	potevo scriverla meglio? SI.
	Funziona? SI.
	la riscriverò? COL CAZZO IMPANATO CON LE PATATE. */
void	expanded_str_clone(t_attr *st, int name_var_len)
{
	t_list	*tmp;

	if (st->list_flag == 0)
	{
		tmp = st->env_list;
		while (tmp && tmp->dol_flag
			!= st->save_y_mtx_envp[st->i_flag_dol])
			tmp = tmp->next;
		st->xmnvp = name_var_len + 1;
		while (tmp && tmp->content[st->xmnvp])
			st->array2[st->y2][st->x2++]
				= tmp->content[st->xmnvp++];
		return ;
	}
	else
	{
		tmp = st->local_list;
		while (tmp && tmp->dol_flag != st->save_y_mtx_envp[st->i_flag_dol])
			tmp = tmp->next;
		st->xmnvp = name_var_len + 1;
		while (tmp && tmp->content[st->xmnvp])
			st->array2[st->y2][st->x2++] = tmp->content[st->xmnvp++];
		st->list_flag = 0;
		return ;
	}
}

int	expanded_token_counter2(t_attr *strct)
{
	t_list	*tmp;

	tmp = strct->env_list;
	while (tmp != NULL)
	{
		if (!ft_strncmp(strct->check_exp, tmp->content, strct->len_call_exp))
		{
			while (tmp->content[strct->xmnvp])
			{
				strct->mem_space++;
				strct->xmnvp++;
			}
			free(strct->check_exp);
			strct->save_y_mtx_envp[strct->i_flag_dol] = tmp->dol_flag;
			return (0);
		}
		tmp = tmp->next;
		strct->y_mtx_envp++;
	}
	strct->y_mtx_envp = 0;
	return (-1);
}

/* questa funzione conta quanta memoria devo allocare per l'exp.
	mi devo calcolare la lunghezza del nome ed escluderla (check_exp)
	poi in ft:strncmp faccio un strncmp e trovo la variabile
	d'ambiente giusta per calcolo quanto necessario per allocare la
	memoria. */
void	expanded_token_counter(t_attr *strct, char *c)
{
	int	inizio;
	int	i;

	i = 0;
	inizio = strct->i;
	while (c[strct->i] != '"' && c[strct->i] != ' '
		&& c[strct->i] != '$' && c[strct->i])
		strct->i++;
	strct->len_call_exp = strct->i - inizio + 1;
	strct->check_exp = malloc(sizeof(char) * strct->len_call_exp + 1);
	strct->i = inizio;
	while (i < strct->len_call_exp && c[strct->i] != '"'
		&& c[strct->i] != ' ' && c[strct->i] != '$' && c[strct->i])
		strct->check_exp[i++] = c[strct->i++];
	strct->check_exp[i] = '=';
	strct->check_exp[i + 1] = '\0';
	strct->y_mtx_envp = 0;
	strct->xmnvp = strct->len_call_exp;
	if (expanded_token_counter2(strct) == -1)
	{
		strct->list_flag = 1;
		expanded_token_counter_list(strct);
	}
	strct->mem_space++;
	return ;
}
