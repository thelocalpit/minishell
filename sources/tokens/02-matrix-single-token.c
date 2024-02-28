/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02-matrix-single-token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:26 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:52:17 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *get_cmd_token(char *c, t_attr *strct)
{
	int j;
	int n;

	j = 0;
	if (c[j] == '"')
	{
		j++;
		if (c[j] == '"')
			return (NULL);
		n = 2;
		return (ft_write_word(c, strct, n, j));
	}
	else if (c[j] == '\'')
	{
		j++;
		if (c[j] == '\'')
			return (NULL);
		n = 1;
		return (ft_write_word(c, strct, n, j));
	}
	else
	{
		n = 0;
		return (ft_write_word(c, strct, n, j));
	}
}

void create_matrix_cmd(char *c, t_attr *strct)
{
	strct->i_flag_dol = 0;
	strct->x2 = 0;
	strct->y2 = 0;
	strct->array2 = malloc((strct->words_counter + 1) * sizeof(char *));
	strct->array2[strct->words_counter] = NULL;
	if (!strct->array2)
		return;
	while (strct->y2 < strct->words_counter)
	{
		strct->x2 = 0;
		while (*c == ' ')
			c++;
		c = get_cmd_token(c, strct);
		if (strct->array2[strct->y2] == 0 && strct->y2 < strct->words_counter)
		{
			c = NULL;
			return ;
		}
		strct->y2++;
	}
	if (strct->i_flag_dol > 0)
	{
		free(strct->flag_dol);
		free(strct->save_y_mtx_envp); // DA RISOLVERE
	}
}

void get_cmd_matrix(char *c, t_attr *strct)
{
	if (!c)
		return ;
	ft_words_counter(c, strct);
	create_matrix_cmd(c, strct);
}

