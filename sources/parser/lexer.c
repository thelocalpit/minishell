/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:59:59 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/23 15:30:37 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questo è il file di lancio del lexer */

void command(t_attr *att)
{
	if (att->flag$[att->y2] == 1)
	{
		printf("sono qui\n");
		expand_tokens(att->arr2, att);
	}
	if (!att->arr2)
		return;
}