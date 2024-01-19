/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:16:57 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/19 18:51:55 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* qui inizializziamo  tutti i valori di att. */

void	init_parameters(t_attr *att)
{
	init_attributes(att);
}

void	init_attributes(t_attr *att)
{
	att->y = 0;
	att->x = 0;
	att->y2 = 0;
	att->x2 = 0;

	att->nb_tokens = 0;
}

void	reinit_parameters(t_attr *att, char **envp)
{
	(void)envp;
	att->nb_tokens = 0;
	att->split_arr = NULL;
	att->arr2 = NULL;
	att->y = 0;
	att->x = 0;
	att->y2 = 0;
	att->x2 = 0;
	att->str = NULL;
	att->i_env = 0;
	att->j_env = 0;
	
}
