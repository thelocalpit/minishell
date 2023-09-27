/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:30:09 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/27 16:07:27 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione dovrá contare gli elementi all-interno della linea di 
	comando */

/* é neccessario fin da subito individuare quando ci sono le quotes.
	questo ci permette di evitare problemi in fase di conteggio degli
	elementi. */
	
int	count_tokens(char *s, t_attr *att)
{
	int len;
	int i;

	
}