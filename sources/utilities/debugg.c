/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:49:02 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:50:45 by mcoppola         ###   ########.fr       */
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
		printf("number: %d\n\n", tmp_list->dol_flag);
		tmp_list = tmp_list->next;
	}
}


void printvar(t_list *local_list)
{
	t_list *head;

	head = local_list;
	printf("questa è la lista:\n");
	while (local_list != NULL)
	{
		printf("content: %s\n", local_list->content);
		printf("number: %d\n\n", local_list->dol_flag);
		local_list = local_list->next;
	}
	local_list = head;
}
