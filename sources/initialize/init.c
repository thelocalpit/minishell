/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:16:57 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/09 19:04:34 by pfalasch         ###   ########.fr       */
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
	att->i = 0;
	att->inside_single_quotes = 0;
	att->n_dquotes = 0;
	att->n_squotes = 0;
	att->nb_tokens = 0;
}

void	reinit_parameters(t_attr *att, char **envp)
{
	(void)envp;
	att->nb_tokens = 0;
}
