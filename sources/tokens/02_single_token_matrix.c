/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_single_token_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:26 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:52:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* chiamiamo la funzione ft_write_word a seconda di che elemento abbiamo
	davanti. può essere "" '' o niente. */
char *get_cmd_token(char *s, t_attr *att)
{
	int i;
	int flag;

	i = 0;
	if (s[i] == '"')
	{
		i++;
		if (s[i] == '"')
			return (NULL);
		flag = 2;
		return (ft_write_word(s, att, flag, i));
	}
	else if (s[i] == '\'')
	{
		i++;
		if (s[i] == '\'')
			return (NULL);
		flag = 1;
		return (ft_write_word(s, att, flag, i));
	}
	else
	{
		flag = 0;
		return (ft_write_word(s, att, flag, i));
	}
}

/* creiamo una nuova matrice ("array2"). allochiamo la memoria e andiamo a
	copiare ogni elemento all'interno della matrice.
	NB: con elemento intendiamo solo separati da spazi
		(quindi una doppia "" sarà 1 solo argomento anche se all'interno
			contiene degli spazi) */
void create_matrix_cmd(char *s, t_attr *att)
{
	att->i_flag_dol = 0;
	att->x2 = 0;
	att->y2 = 0;
	att->array2 = malloc((att->words_counter + 1) * sizeof(char *));
	att->array2[att->words_counter] = NULL;
	if (!att->array2)
		return;
	while (att->y2 < att->words_counter)
	{
		att->x2 = 0;
		while (*s == ' ')
			s++;
		s = get_cmd_token(s, att);
		if (att->array2[att->y2] == 0 && att->y2 < att->words_counter)
		{
			s = NULL;
			return ;
		}
		att->y2++;
	}
	if (att->i_flag_dol > 0)
	{
		free(att->flag_dol);
		free(att->save_y_mtx_envp); // DA RISOLVERE
	}
}
/* questa funzione si occupa di spezzare ciascun str della split_array
	in comandi e args. */
void get_cmd_matrix(char *s, t_attr *att)
{
	if (!s)
		return ;
	ft_words_counter(s, att);
	create_matrix_cmd(s, att);
}

