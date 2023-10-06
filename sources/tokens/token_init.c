/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:30:09 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/06 10:39:47 by pfalasch         ###   ########.fr       */
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

/* é neccessario fin da subito individuare quando ci sono le quotes.
	questo ci permette di evitare problemi in fase di conteggio degli
	elementi. */
	
int	count_tokens(char *s, t_attr *att)
{
	int	len;
	int	i;

	count_quotes(s, att);
	len = ft_strlen(s) - 1;
	i = 0;
	while (s[i])
	{
		if ()
	}
}