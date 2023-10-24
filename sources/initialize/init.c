/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:16:57 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/24 17:37:22 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_parameters(t_attr *att, char **envp)
{
	(void)envp;
	init_attributes(att);
}

void	init_attributes(t_attr *att)
{
	att->y = 0;
	att->nb_tokens = 0;
}

void	reinit_parameters(t_attr *att, char **envp)
{
	(void)envp;
	att->nb_tokens = 0;
}
