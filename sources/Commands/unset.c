/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:31:40 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/29 16:16:04 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libft/libft.h"
#include "../../includes/minishell.h"

int	ft_unset(char **args, t_attr *att)
{
	int	i;

	i = 1;
	while (args[i])
	{
		ft_remove_node(&(att->env_list), args[i]);
		i++;
	}
	i = 1;
	while (args[i])
	{
		ft_remove_node(&(att->local_var), args[i]);
		i++;
	}
	return (0);
}

void	ft_remove_node(t_list **list, char *arg)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *list;
	prev = NULL;
	while (tmp)
	{
		if (ft_strncmp(arg, (char *)tmp->content, ft_strlen(arg)) == 0)
		{
			if (prev == NULL)
				*list = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
