/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_error_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:02:33 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/18 23:04:26 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* qunado si ha una pipe da ultimo */
int error_last_pipe(t_attr *att)
{
	int i;

	i = 0;
	while (att->split_arr[i])
		i++;
	i--;
	if (att->split_arr[i][0] == '|' && att->split_arr[i][1] == '\0')
	{
		printf("parse error near `|'");
		return (1);
	}
	return (0);
}

/* quando si ha una pipe all'inizio della linea */

int error_pipe_first(t_attr *att)
{
	if (att->split_arr[0][0] == '|' && att->split_arr[0][1] == '\0')
	{
		printf("parse error near `|'");
		return (1);
	}
	return (0);
}

/* funzione di gestione degli errori con le pipe. */

int error_pipe(t_attr *att)
{
	if (error_last_pipe(att) != 0)
		return (1);
	if (error_pipe_first(att) != 0)
		return (1);
	return (0);
}
