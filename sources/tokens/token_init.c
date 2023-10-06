/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:30:09 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/06 12:29:09 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* in qeusta funzione andiamo a contarci il numero totali di "" e di '\'' 
	inoltre controlliamo se la prima virgoletta ad apparire è una singola. 
	i servirà in seguito come signal booleano */

int	count_quotes(char *s, t_attr *att)
{
	int	i;
	int	type;

	i = 0;
	type = 0;
	while (s[i])
	{
		if (s[i] == '"')
		{
			if (type == 0)
				type = 2;
			att->n_dquotes++;
		}
		else if (s[i] == '\'')
		{
			if (type == 0)
			{
				type = 1;
			}
			att->n_squotes++;
		}
		i++;
	}
	if (type == 1)
		att->inside_single_quotes = 1;
	else
		att->inside_single_quotes = 0;
}

/* questa funzione dovrá contare gli elementi all-interno della linea di 
	comando */

/* é neccessario fin da subito individuare quando e quante quotes ci sono.
	questo ci permette di evitare problemi in fase di conteggio degli
	elementi. */

int	count_tokens(char *s, t_attr *att)
{
	int	len;
	int	i;
	int s_quotes;

	count_quotes(s, att);
	len = ft_strlen(s) - 1;
	i = 0;
	while (i <= len)
	{
		//single quote
		if (s[i] == '\'')
		{
			s_quotes = 0;
			att->nb_tokens++;
			//if (s[i + 1] && s[i + 1] == '\'')
			while (i <= len && s_quotes <= att->n_squotes)
			{
				if (s[i] == '\'')
					s_quotes++;
				if (s_quotes % 2 == 0 && s[i +1] && s[i + 1] == ' ')
				{
					i++;
					break ;
				}
				i++;
			}
		}
		// double quote
		else if (s[i] == '"')
		{
			
		}
	}
}