/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02c-word-copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:16:38 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:52:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int copy_no_quotes(char *c, int j, t_attr *strct, int name_var_len)
{
	while (c[j] != ' ' && c[j])
	{
		if (c[j] == '$' && c[j + 1] == '$')
			j += copy_double_dollar(j, strct);
		else if (c[j] == '$' && c[j + 1] == '?')
			j = copy_g_value(strct, j);
		else if (c[j] == '$' && c[j + 1] != ' ' && c[j + 1])
		{
			j++;
			if (strct->flag_dol[strct->i_flag_dol] == 0)
			{
				name_var_len = ft_strname_var_len(s, &j, name_var_len);
				copy_expanded_str(strct, name_var_len);
			}
			else
			{
				while (c[j] != '"' && c[j] != ' ' && c[j] != '$' && c[j])
					j++;
			}
			strct->i_flag_dol++;
		}
		else
			strct->array2[strct->y2][strct->x2++] = c[j++];
	}
	return (j);
}

/* questa funzione si occupa delle "".
	copy_g_value copia l'errore del global value.
	se c'è da espandere, facciamo riferimento alla flag_dol che ci dice
	se è un elemento corretto da espandere o se deve ritornare il vuoto
	nel caso lo sia, calcoliamo la lunghezza del nome della variabile
	e ritorniamo il suo valore con copy_expanded_str.
	Se non è da espandere facciamo un normale copia. */
int copy_double_quotes(char *c, int j, t_attr *strct, int name_var_len)
{
	while (c[j] != '"')
	{
		if (c[j] == '$' && c[j + 1] == '$')
			j += copy_double_dollar(j, strct);
		else if (c[j] == '$' && c[j + 1] == '?')
			j = copy_g_value(strct, j);
		else if (c[j] == '$' && c[j + 1] != ' ' && c[j + 1] && c[j + 1] != '"')
		{
			j++;
			if (strct->flag_dol[strct->i_flag_dol] == 0)
			{
				name_var_len = ft_strlen_name_var(s, &j, name_var_len);
				copy_expanded_str(strct, name_var_len);
			}
			else
			{
				while (c[j] != '"' && c[j] != ' ' && c[j] != '$' && c[j])
					j++;
			}
			strct->i_flag_dol++;
		}
		else if (c[j] == '\\' && c[j + 1] == '"')
		{
			strct->array2[strct->y2][strct->x2++] = '"';
			j += 2;
		}
		else
			strct->array2[strct->y2][strct->x2++] = c[j++];
	}
	return (j);
}

/* questa funzione calcola lo spazio di ciascuna str della matrice array2
	con ft_strlen_custom -> alloca la memoria -> a seconda della flag
	chiamiamo la funzione di copy. */
char *ft_write_word(char *c, t_attr *strct, int num, int i)
{
	int n;
	int name_var_len;

	name_var_len = 0;
	n = ft_strlen_custom(c, num, strct);
	strct->array2[strct->y2] = malloc(n + 1);
	if (!strct->array2[strct->y2])
		return (NULL);
	if (num == 2)
		i = copy_double_quotes(c, i, strct, name_var_len);
	else if (num == 1)
	{
		while (c[i] != '\'')
			strct->array2[strct->y2][strct->x2++] = c[i++];
	}
	else
	{
		i = copy_no_quotes(c, i, strct, name_var_len);
	}
	strct->array2[strct->y2][strct->x2] = '\0';
	return (&c[++i]);
}
