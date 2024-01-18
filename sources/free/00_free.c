/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:37:23 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/10 13:40:41 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione serve a liberare l'arr2 */

void free_arr2(char **tokens, t_attr *att)
{
	int i;

	i = 0;
	while (i < att->count_words)
		free(tokens[i++]);
	free(tokens);
}

/* questo è per liberare una matrix generica */

void free_arr(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

/* questa è stata fatta per liberare la matrice degli fd
	delle pipes. per farlo castiamo la matrice a char ** */

void ft_delete_matrix(void *matrix)
{
	int i;

	i = -1;
	while (((char **)matrix)[++i])
		free(((char **)matrix)[i]);
	free(matrix);
}

/* questa f è per liberare la matrice di envp */
void free_mx_envp(t_attr *att)
{
	int i;

	i = 0;
	while (att->mx_envp[i] != NULL)
	{
		free(att->mx_envp[i]);
		i++;
	}
	free(att->mx_envp);
}
