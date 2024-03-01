/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02c.word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:16:38 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:52:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	double_quotes_utils2(int j, t_attr *strct)
{
	strct->array2[strct->y2][strct->x2++] = '"';
	j += 2;
}

void	double_quotes_utils(char *c, int j)
{
	while (c[j] != '"' && c[j] != ' ' && c[j] != '$' && c[j])
		j++;
}

/* questa funzione si occupa delle "".
	copy_g_value copia l'errore del global value.
	se c'è da espandere, facciamo riferimento alla flag_dol che ci dice
	se è un elemento corretto da espandere o se deve ritornare il vuoto
	nel caso lo sia, calcoliamo la lunghezza del nome della variabile
	e ritorniamo il suo valore con copy_expanded_str.
	Se non è da espandere facciamo un normale copia. */
int	double_quotes_copy(char *c, int j, t_attr *strct, int name_var_len)
{
	while (c[j] != '"')
	{
		if (c[j] == '$' && c[j + 1] == '$')
			j += double_dollar_copy(j, strct);
		else if (c[j] == '$' && c[j + 1] == '?')
			j = g_value_copy(strct, j);
		else if (c[j] == '$' && c[j + 1] != ' ' && c[j + 1] && c[j + 1] != '"')
		{
			j++;
			if (strct->flag_dol[strct->i_flag_dol] == 0)
			{
				name_var_len = var_name_strlen(c, &j, name_var_len);
				expanded_str_clone(strct, name_var_len);
			}
			else
				double_quotes_utils(c, j);
			strct->i_flag_dol++;
		}
		else if (c[j] == '\\' && c[j + 1] == '"')
			double_quotes_utils2(j, strct);
		else
			strct->array2[strct->y2][strct->x2++] = c[j++];
	}
	return (j);
}

int	no_quotes_copy(char *c, int j, t_attr *strct, int name_var_len)
{
	while (c[j] != ' ' && c[j])
	{
		if (c[j] == '$' && c[j + 1] == '$')
			j += double_dollar_copy(j, strct);
		else if (c[j] == '$' && c[j + 1] == '?')
			j = g_value_copy(strct, j);
		else if (c[j] == '$' && c[j + 1] != ' ' && c[j + 1])
		{
			j++;
			if (strct->flag_dol[strct->i_flag_dol] == 0)
			{
				name_var_len = var_name_strlen(c, &j, name_var_len);
				expanded_str_clone(strct, name_var_len);
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

/* questa funzione calcola lo spazio di ciascuna str della matrice array2
	con ft_strlen_custom -> alloca la memoria -> a seconda della flag
	chiamiamo la funzione di copy. */
char	*write_word(char *c, t_attr *strct, int num, int i)
{
	int	n;
	int	name_var_len;

	name_var_len = 0;
	n = custom_strlen(c, num, strct);
	strct->array2[strct->y2] = malloc(n + 1);
	if (!strct->array2[strct->y2])
		return (NULL);
	if (num == 2)
		i = double_quotes_copy(c, i, strct, name_var_len);
	else if (num == 1)
	{
		while (c[i] != '\'')
			strct->array2[strct->y2][strct->x2++] = c[i++];
	}
	else
	{
		i = no_quotes_copy(c, i, strct, name_var_len);
	}
	strct->array2[strct->y2][strct->x2] = '\0';
	return (&c[++i]);
}
