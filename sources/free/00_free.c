/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:37:23 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/22 19:45:28 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void free_tokens(char **tokens, t_attr *att)
{
	int i;

	i = 0;
	while (i < att->nb_tokens)
		free(tokens[i++]);
	free(tokens);
}