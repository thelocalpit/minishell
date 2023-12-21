/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:31:40 by mcoppola          #+#    #+#             */
/*   Updated: 2023/12/21 11:40:22 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libft/libft.h"
#include "../../includes/minishell.h"

int	ft_unset(char **args, t_list *env_list)
{
	int	i;

	i = 1;
	while (args[i])
	{
		ft_remove_node(&env_list, args[i]);
		i++;
	}
	return (0);
}

void	ft_remove_node(t_list **env_list, char *arg)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *env_list;
	prev = NULL;
	while (tmp)
	{
		if (ft_strncmp(arg, get_var_name((char *)tmp->content), ft_strlen(arg)) == 0)
		{
			if (prev == NULL)
				*env_list = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
