/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:49:02 by pfalasch          #+#    #+#             */
/*   Updated: 2023/12/19 23:22:23 by pfalasch         ###   ########.fr       */
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
	printf("questa è la lista:\n");
	// Attraversa la lista e stampa i dati dei nodi
	while (att->env_list != NULL)
	{
		printf("content: %s\n", att->env_list->content);
		printf("number: %d\n\n", att->env_list->$flag);
		att->env_list = att->env_list->next;
	}
}