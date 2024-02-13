/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:37:23 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/13 11:35:25 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione serve a liberare l'arr2 */

void	free_arr2(char **tokens, t_attr *att)
{
	int i;

	i = 0;
	while (i < att->count_words)
		free(tokens[i++]);
	free(tokens);
}

/* questo è per liberare una matrix generica */

void	free_arr(char **arr)
{
	int	i;

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

void	ft_delete_matrix(void *matrix)
{
	int	i;

	i = -1;
	while (((char **)matrix)[++i])
		free(((char **)matrix)[i]);
	free(matrix);
}

void	free_local_var(t_attr *att)
{
	while (att->local_var)
	{
		free(att->local_var->content);
		att->local_var = att->local_var->next;
	}
}

void	free_env_list(t_attr *att)
{
	t_list	*tmp;

	while (att->env_list)
	{
		tmp = att->env_list;
		free(att->env_list->content);
		att->env_list = att->env_list->next;
		free(tmp);
	}
}
