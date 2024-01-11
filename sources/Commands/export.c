/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:37 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/04 18:23:41 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

/**
 * basic_export - print all the env variables in the format "declare -x VAR"
 * sorted
 *
 * @param {t_attr *} att: the struct of attributes
 * @return {int} 0 if success
*/
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

/**
 * check_duplicate - check if the variable VAR is already in the env variables
 * if it is, update the value of the variable
 * if it is not, add the variable to the env variables
 *
 * @param {t_attr *} att: the struct of attributes
 * @param {char *} content: the content of the variable
 * @return {void}
*/
void	check_duplicate(t_attr *att, char *content)
{
	t_list	*list;

	list = att->env_list;
	while (list)
	{
		if (!ft_strcmp(get_var_name(content),
				get_var_name((char *)list->content)))
		{
			list->content = ft_strdup(content);
			return ;
		}
		list = list->next;
	}
	ft_lstadd_back(&(att->env_list), ft_lstnew(ft_strdup(content)));
}

/**
 * add_on_env - add the variable VAR to the env variables
 *
 * @param {char *} arg: the argument to add
 * @param {t_attr *} att: the struct of attributes
 * @return {int} 0 if success
*/
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

/**
 * export -p -> print all the env variables in the format "declare -x VAR" sorted
 * export VAR -> add the variable VAR to the env variables
 *
 * @param {char **} args: the array of arguments
 * @param {t_attr *} att: the struct of attributes
 * @return {int} 0 if success, 1 if error
*/
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
