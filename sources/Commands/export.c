/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:37 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/17 22:25:12 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

/**
 * basic_export - print all the env variables in the format "declare -x VAR"
 * sorted
 *
 * @param t_attr* att: the struct of attributes
 * @return 0 if success
*/
int	basic_export(t_attr *att)
{
	t_list	*export;

	export = sort_list(att->env_list);
	while (export)
	{
		if (get_var_content((char *)export->content)[0] == '"')
			printf("declare -x %s\n", export->content);
		else
			printf("declare -x %s=\"%s\"\n",
				get_var_name((char *)export->content),
				get_var_content((char *)export->content));
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
 * @param char* arg: the argument to add
 * @param t_attr* att: the struct of attributes
 * @return 0 if success
*/
int	add_on_env(char *arg, t_attr *att)
{
	t_list	*env_list;
	t_list	*local_list;
	char	*content;

	env_list = att->env_list;
	local_list = att->local_var;
	content = arg;
	if (ft_strchr(arg, '=') == NULL)
		while (local_list)
		{
			if (ft_strcmp(get_var_name(arg), get_var_name((char *)local_list->content)) == 0)
			{
				content = local_list->content;
				break ;
			}
			local_list = local_list->next;
		}
	while (env_list)
	{
		if (ft_strcmp(get_var_name(content), get_var_name((char *)env_list->content)) == 0)
			return (env_list->content = ft_strdup(content), 0);
		env_list = env_list->next;
	}
	ft_lstadd_back(&(att->env_list), ft_lstnew(ft_strdup(content)));
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
