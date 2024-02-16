/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_verify_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:00:05 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/16 01:37:54 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* controlla la linea di comando inserita con tutte le varie casistiche */
int	return_negative(t_attr *att)
{
	att->g_value = 2;
	return (1); //HO MERGIATO PRIMA IL RETURNN ERA da g_struct_var branch -1 DA VERIFICARE CON PIETRO PORCO DIO
}

/* questa funzione serve per valutare la validità della linea di comando.
	viene controllato subito se c'è errori nelle redir (finisce o inizia con
	una redir?), controlla che le quotes siano chiuse, controlla che le
	chiamate con il dollaro siano valide SU TUTTA LA LINEA DI COMANDO
	(POTREBBE ESSERE UN PROBLEMA? nel caso spostare la chiamata al controllo
	su ciascuna parte di arr2) */
int	verify_readline(char *s, t_attr *att)
{
	if (error_begin_02(s, att))
		return (return_negative(att));
	else if (count_quotes(s))
		return (return_negative(att));
	else if (error_end(s, '>', att) || error_end(s, '<', att) || error_end(s, '|', att))
		return (return_negative(att));
	else if (error_begin(s, att))
		return (return_negative(att));
	else if (error_mixed_start(s, att))
		return (return_negative(att));
	else if (error_dollar(s, att))
		return (return_negative(att));
	return (0);
}
