/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:37:23 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/21 10:57:42 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione serve a liberare l'array2 */

void	free_array2(char **tokens, t_attr *att)
{
	int i;

	i = 0;
	while (i < att->words_counter)
		free(tokens[i++]);
	free(tokens);
}

/* questo è per liberare una matrix generica */

void	free_array(char **arr)
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

void	free_local_list(t_attr *att)
{
	while (att->local_list)
	{
		free(att->local_list->content);
		att->local_list = att->local_list->next;
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
