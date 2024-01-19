/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:49:02 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/19 17:17:52 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_print_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%d - %s\n", i, array[i]);
		i++;
	}
	printf("end of array\n\n");
}

void printlist(t_attr *att)
{
	t_list *head;

	head = att->env_list;
	// printf("questa è la lista:\n");
	// Attraversa la lista e stampa i dati dei nodi
	while (att->env_list != NULL)
	{
		// printf("content: %s\n", att->env_list->content);
		// printf("number: %d\n\n", att->env_list->id);
		att->env_list = att->env_list->next;
	}
	att->env_list = head;
}


void printvar(t_list *local_var)
{
	t_list *head;

	head = local_var;
	printf("questa è la lista:\n");
	// Attraversa la lista e stampa i dati dei nodi
	while (local_var != NULL)
	{
		printf("content: %s\n", local_var->content);
		printf("number: %d\n\n", local_var->id);
		local_var = local_var->next;
	}
	local_var = head;
}