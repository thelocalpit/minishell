/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:49:02 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/16 18:21:04 by pfalasch         ###   ########.fr       */
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
	t_list *tmp_list;

	tmp_list = att->env_list;
	printf("questa è la lista_ENV:\n");
	while (tmp_list != NULL)
	{
		printf("content: %s\n", tmp_list->content);
		printf("number: %d\n\n", tmp_list->$flag);
		tmp_list = tmp_list->next;
	}
}


void printvar(t_list *local_var)
{
	t_list *head;

	head = local_var;
	printf("questa è la lista:\n");
	while (local_var != NULL)
	{
		printf("content: %s\n", local_var->content);
		printf("number: %d\n\n", local_var->$flag);
		local_var = local_var->next;
	}
	local_var = head;
}