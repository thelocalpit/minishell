/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02c_copy_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:16:38 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:52:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


/* vedi funzione sotto ma senza "" */
int copy_no_quotes(char *s, int i, t_attr *att, int len_name_var)
{
	while (s[i] != ' ' && s[i])
	{
		if (s[i] == '$' && s[i + 1] == '$')
			i += copy_double_dollar(i, att);
		else if (s[i] == '$' && s[i + 1] == '?')
			i = copy_g_value(att, i);
		else if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1])
		{
			i++;
			if (att->flag_dol[att->i_flag_dol] == 0)
			{
				len_name_var = ft_strlen_name_var(s, &i, len_name_var);
				copy_expanded_str(att, len_name_var);
			}
			else
			{
				while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
					i++;
			}
			att->i_flag_dol++;
		}
		else
			att->array2[att->y2][att->x2++] = s[i++];
	}
	return (i);
}

/* questa funzione si occupa delle "".
	copy_g_value copia l'errore del global value.
	se c'è da espandere, facciamo riferimento alla flag_dol che ci dice
	se è un elemento corretto da espandere o se deve ritornare il vuoto
	nel caso lo sia, calcoliamo la lunghezza del nome della variabile
	e ritorniamo il suo valore con copy_expanded_str.
	Se non è da espandere facciamo un normale copia. */
int copy_double_quotes(char *s, int i, t_attr *att, int len_name_var)
{
	while (s[i] != '"')
	{
		if (s[i] == '$' && s[i + 1] == '$')
			i += copy_double_dollar(i, att);
		else if (s[i] == '$' && s[i + 1] == '?')
			i = copy_g_value(att, i);
		else if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1] && s[i + 1] != '"')
		{
			i++;
			if (att->flag_dol[att->i_flag_dol] == 0)
			{
				len_name_var = ft_strlen_name_var(s, &i, len_name_var);
				copy_expanded_str(att, len_name_var);
			}
			else
			{
				while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
					i++;
			}
			att->i_flag_dol++;
		}
		else if (s[i] == '\\' && s[i + 1] == '"')
		{
			att->array2[att->y2][att->x2++] = '"';
			i += 2;
		}
		else
			att->array2[att->y2][att->x2++] = s[i++];
	}
	return (i);
}

/* questa funzione calcola lo spazio di ciascuna str della matrice array2
	con ft_strlen_custom -> alloca la memoria -> a seconda della flag
	chiamiamo la funzione di copy. */
char *ft_write_word(char *s, t_attr *att, int flag, int i)
{
	int len;
	int len_name_var;

	len_name_var = 0;
	len = ft_strlen_custom(s, flag, att);
	att->array2[att->y2] = malloc(len + 1);
	if (!att->array2[att->y2])
		return (NULL);
	if (flag == 2)
		i = copy_double_quotes(s, i, att, len_name_var);
	else if (flag == 1)
	{
		while (s[i] != '\'')
			att->array2[att->y2][att->x2++] = s[i++];
	}
	else
	{
		i = copy_no_quotes(s, i, att, len_name_var);
	}
	att->array2[att->y2][att->x2] = '\0';
	return (&s[++i]);
}
