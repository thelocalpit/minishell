/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:37 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/03 14:21:44 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

int	basic_export(t_attr *att)
{
	t_list	*export;

	export = sort_list(att->env_list);
	while (export)
	{
		printf("declare -x %s\n", (char *)export->content);
		export = export->next;
	}
	return (0);
}

void	check_duplicate(t_attr *att, char *content)
{
	t_list	*list;

	list = att->env_list;
	while (list)
	{
		if (!ft_strcmp(get_var_name(content), get_var_name((char *)list->content)))
		{
			list->content = ft_strdup(content);
			return ;
		}
		list = list->next;
	}
	ft_lstadd_back(&(att->env_list), ft_lstnew(ft_strdup(content)));
}

int	add_on_env(char *arg, t_attr *att)
{
	t_list	*list;

	list = att->local_var;
	while (list)
	{
		if (ft_strcmp(arg, get_var_name((char *)list->content)) == 0)
			check_duplicate(att, list->content);
		list = list->next;
	}
	return (0);
}

int	ft_export(char **args, t_attr *att)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i == 1)
		return (basic_export(att));
	else
	{
		args++;
		while (*args)
		{
			if (!add_on_env(*args, att))
				args++;
			else
				return (1);
		}
	}
	return (0);
}
