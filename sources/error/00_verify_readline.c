/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_verify_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:00:05 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/17 17:08:50 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* controlla la linea di comando inserita con tutte le varie casistiche */
int return_negative(void)
{
	g_value = 2;
	return (-1);
}
/* questa funzione serve per valutare la validità della linea di comando.
	viene controllato subito se c'è errori nelle redir (finisce o inizia con
	una redir?), controlla che le quotes siano chiuse, controlla che le
	chiamate con il dollaro siano valide SU TUTTA LA LINEA DI COMANDO
	(POTREBBE ESSERE UN PROBLEMA? nel caso spostare la chiamata al controllo
	su ciascuna parte di arr2) */
int verify_readline(char *s, t_attr *att)
{
	if (error_end(s, '>') || error_end(s, '<') || error_end(s, '|'))
		return (return_negative());
	else if (error_begin(s))
		return (return_negative());
	else if (error_mixed_start(s))
		return (return_negative());
	else if (count_quotes(s))
		return (return_negative());
	else if (error_dollar(s, att))
		return (return_negative());
	return (0);
}
