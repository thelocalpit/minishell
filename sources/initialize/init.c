/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:10:56 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 12:18:12 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Initializes the attributes of a t_attr structure.
 *
 * @param att The t_attr structure to be initialized.
 */
void	init_attr(t_attr *att)
{
	att->x2 = 0;
	att->y2 = 0;
	att->pipe_index_num = 0;
	att->num_tokens = 0;
	att->y = 0;
	att->x = 0;
}

/**
 * @brief Reinitializes the parameters of the t_attr structure.
 *
 * This function sets the values of various fields in the t_attr structure to
 * their initial state.
 *
 * @param att The t_attr structure to be reinitialized.
 */
void	reinit_params(t_attr *att)
{
	att->y = 0;
	att->array2 = NULL;
	att->num_tokens = 0;
	att->y_mtx_envp = 0;
	att->split_array = NULL;
	att->y2 = 0;
	att->x2 = 0;
	att->check_exp = NULL;
	att->i_readfile = 0;
	att->xmnvp = 0;
	att->first_redir = 0;
	att->pipe_index_num = 0;
	att->x = 0;
	att->i_redir = 0;
}
