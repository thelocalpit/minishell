/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:16:57 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/24 19:00:00 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione serve per creare una matrice custom con tutte le variabili di 
	ambiente. */

void start_env(char **envp, t_attr *att)
{
	att->y_mx_envp = 0;
	while (envp[att->y_mx_envp])
		att->y_mx_envp++;
	att->mx_envp = malloc(sizeof(char *) * (att->y_mx_envp + 1));
	if (!att->mx_envp)
		return;
	while (att->x_mx_envp < att->y_mx_envp)
	{
		att->mx_envp[att->x_mx_envp] = ft_strdup(envp[att->x_mx_envp]);
		att->x_mx_envp++;
	}
	att->mx_envp[att->x_mx_envp] = 0;
}

/* qui inizializziamo  tutti i valori di att. */

void	init_parameters(t_attr *att, char **envp)
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
}
