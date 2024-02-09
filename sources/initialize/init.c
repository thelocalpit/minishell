/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:16:57 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/09 07:17:37 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione serve per creare una matrice custom con tutte le variabili di 
	ambiente. */
// void start_env(char **envp, t_attr *att)
// {
// 	att->y_mx_envp = 0;
// 	while (envp[att->y_mx_envp])
// 		att->y_mx_envp++;
// 	att->mx_envp = malloc(sizeof(char *) * (att->y_mx_envp + 1));
// 	if (!att->mx_envp)
// 		return;
// 	while (att->x_mx_envp < att->y_mx_envp)
// 	{
// 		att->mx_envp[att->x_mx_envp] = ft_strdup(envp[att->x_mx_envp]);
// 		att->x_mx_envp++;
// 	}
// 	att->mx_envp[att->x_mx_envp] = 0;
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

	att->nb_tokens = 0;
	att->pipe_index = 0;
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
	att->check_exp = NULL;
	att->y_mx_envp = 0;
	att->x_mx_envp = 0;
	att->pipe_index = 0;
	att->i_readfile = 0;
	att->i_redir = 0;
	att->frirst_redir = 0;
}

