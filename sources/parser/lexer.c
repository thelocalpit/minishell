/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:59:59 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/22 16:03:05 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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