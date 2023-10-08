/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:30:09 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/08 19:24:03 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_double_quotes(char *s, int len, int i, t_attr * att)
{
	int quotes;

	quotes = 0;
	att->nb_tokens
}
/* questa funzione va a controllare le single quotes.
	prima di tutto facciamo alcuni controlli:
	1. controlliamo che il carattere successivo non sia uno \0 ed è una '
		e allo stesso tempo anche due caratteri successivi non sia uno \0 e
		allo stesso tempo sia uno spazio 
	2.	altra condizione è che lo s[i + 2] è un \0 
			allora ritorniamo i + 2
	
	in questo caso non controlliamo che sia un token valido ma lo faremo
	più avanti 
	
	poi entriamo nel loop che semplicemente proseguirà fintanto che i non è
	uguale a len o che il numero di s_quotes che andremo a contare non è
	uguale a quello totale di single quote. questo ci dice che abbiamo 
	analizzato tutti quanti i casi di virgolette. 
	attiveremo un controllo all'interno del loop che ci dirà che quando il 
	conteggio del single quote è uguale a 0 quindi pari e s[i + 1]
	è uguale a spazio, ovvero che contenuto all'intenro delle virgolette
	è concluso. ritorniamo quindi i dopo aver aggiunto un carattere e aver
	mosso il contatore allo spazio.   */
	
int	check_single_quotes(char *s, int len, int i, t_attr * att)
{
	int	s_quotes;

	s_quotes = 0;
	att->nb_tokens++;
	if (s[i + 1] && s[i + 1] == '\''
		&& (s[i + 2] && s[i + 2] == ' ') || !s[i + 2])
		return (i + 2);
	while (i <= len && s_quotes <= att->n_squotes)
	{
		if (s[i] == '\'')
			s_quotes++;
		if (s_quotes % 2 == 0 && s[i + 1] && s[i + 1] == ' ')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}
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
				type = 1;
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

	count_quotes(s, att);
	len = ft_strlen(s) - 1;
	i = 0;
	while (i <= len)
	{
		//single quote
		if (s[i] == '\'')
			i = check_single_quotes(s, len, i, att);
	
		// double quote
		else if (s[i] == '"')
			i = check_double_quotes(s, len, i, att);
	}
}

