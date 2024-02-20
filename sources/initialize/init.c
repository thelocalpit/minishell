/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:16:57 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/09 07:17:37 by mcoppola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione serve per creare una matrice custom con tutte le variabili di
	ambiente. */
// void start_env(char **envp, t_attr *att)
// {
// 	att->y_mtx_envp = 0;
// 	while (envp[att->y_mtx_envp])
// 		att->y_mtx_envp++;
// 	att->mx_envp = malloc(sizeof(char *) * (att->y_mtx_envp + 1));
// 	if (!att->mx_envp)
// 		return;
// 	while (att->x_mtx_envp < att->y_mtx_envp)
// 	{
// 		att->mx_envp[att->x_mtx_envp] = ft_strdup(envp[att->x_mtx_envp]);
// 		att->x_mtx_envp++;
// 	}
// 	att->mx_envp[att->x_mtx_envp] = 0;
// }

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

	att->num_tokens = 0;
	att->pipe_index_num = 0;
}

void	reinit_parameters(t_attr *att, char **envp)
{
	(void)envp;
	att->num_tokens = 0;
	att->split_array = NULL;
	att->array2 = NULL;
	att->y = 0;
	att->x = 0;
	att->y2 = 0;
	att->x2 = 0;
	att->check_exp = NULL;
	att->y_mtx_envp = 0;
	att->x_mtx_envp = 0;
	att->pipe_index_num = 0;
	att->i_readfile = 0;
	att->i_redir = 0;
	att->first_redir = 0;
}

