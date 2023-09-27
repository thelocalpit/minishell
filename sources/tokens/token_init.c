/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:51:52 by asacchin          #+#    #+#             */
/*   Updated: 2023/09/27 19:51:54 by asacchin         ###   ########.fr       */
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