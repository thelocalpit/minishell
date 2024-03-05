/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:37 by mcoppola          #+#    #+#             */
/*   Updated: 2024/03/05 12:39:29 by mcoppola         ###   ########.fr       */
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
	t_list	*temp;
	char	*var_name;

	export = sort_list(att->env_list);
	while (export)
	{
		if (get_variable_content((char *)export->content)[0] == '"')
			printf("declare -x %s\n", export->content);
		else
		{
			var_name = get_variable_name(export->content);
			printf("declare -x %s=\"%s\"\n",
				var_name,
				get_variable_content(export->content));
			free(var_name);
		}
		temp = export;
		export = export->next;
		free(temp);
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
		if (!ft_strncmp(content,
				(char *)list->content, var_name_length(content)))
		{
			list->content = var_no_quote_on_content(content);
			return ;
		}
		list = list->next;
	}
	ft_lstadd_back(&(att->env_list),
		ft_lstnew(var_no_quote_on_content(content)));
}

/**
 * Adds a variable to the environment list with the given content.
 * If the variable already exists, it updates the content based on the append
 * flag.
 *
 * @param content The variable to add/update in the format "name=value".
 * @param att The attribute structure containing the environment list.
 * @param env_list The current environment list.
 * @param append Flag indicating whether to append the content or replace it.
 * @return 0 on success, -1 on failure.
 */
int	add_on_env_2(char *content, t_attr *att, t_list *env_list, int append)
{
	if (ft_strchr(content, '+') && ft_strchr(content, '+')[1] == '=')
		append = 1;
	while (env_list)
	{
		if (ft_strncmp(content, (char *)env_list->content,
				var_name_length(content)) == 0)
		{
			if (append)
				return (env_list->content = ft_strjoin(env_list->content,
						get_variable_content(content)), 0);
			return (env_list->content = var_no_quote_on_content(content), 0);
		}
		env_list = env_list->next;
	}
	if (append)
		ft_lstadd_back(&(att->env_list),
			ft_lstnew(var_no_quote_on_content(content)));
	else
		ft_lstadd_back(&(att->env_list),
			ft_lstnew(var_no_quote_on_content(content)));
	return (0);
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
	int		append;

	append = 0;
	env_list = att->env_list;
	local_list = att->local_list;
	content = arg;
	if (ft_strchr(arg, '=') == NULL)
	{
		while (local_list)
		{
			if (ft_strncmp(arg, (char *)local_list->content,
					var_name_length(arg)) == 0)
			{
				content = local_list->content;
				break ;
			}
			local_list = local_list->next;
		}
		if (!local_list)
			return (1);
	}
	return (add_on_env_2(content, att, env_list, append));
}

/**
 * export -p -> print all the env variables in the format "declare -x VAR"
 * sorted export VAR -> add the variable VAR to the env variables
 *
 * @param {char **} arguments: the array of arguments
 * @param {t_attr *} att: the struct of attributes
 * @return {int} 0 if success, 1 if error
*/
int	ft_export(char **arguments, t_attr *att)
{
	int	c;

	c = 0;
	while (arguments[c])
	{
		c = c + 1;
	}
	if (c == 1)
		return (basic_export(att));
	else
	{
		arguments = arguments + 1;
		while (*arguments)
		{
			if (add_on_env(*arguments, att) == 0)
			{
				arguments++;
			}
			else
			{
				return (1);
			}
		}
	}
	return (0);
}
