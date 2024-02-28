/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:32:17 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 13:32:18 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Updates the 'dol_flag' field of each node in the environment list.
 * The 'dol_flag' field represents the index of the node in the list.
 *
 * @param att The attribute structure containing the environment list.
 */
void	add_index_env_list(t_attr *att)
{
	t_list	*temp_list;
	int		c;

	c = 0;
	temp_list = att->env_list;
	while (temp_list != NULL)
	{
		temp_list->dol_flag = c;
		temp_list = temp_list->next;
		c++;
	}
}

/**
 * @brief Copies the environment variables into a linked list.
 *
 * @param env The array of environment variables.
 * @return A pointer to the head of the linked list.
 */
t_list	*copy_env_in_list(char **env)
{
	t_list	*node;

	node = ft_lstnew((void *)ft_strdup(*env));
	env++;
	while (*env)
	{
		ft_lstadd_back(&node, ft_lstnew(ft_strdup(*env)));
		env++;
	}
	return (node);
}

/**
 * @brief Retrieves the variable name from a given string containing a variable
 *  assignment. If the string does not contain an equal sign ('='), it is
 * assumed to be the variable name itself. If the variable name ends with a
 * plus sign ('+'), the plus sign is excluded from the name.
 *
 * @param full_var The string containing the variable assignment.
 * @return The variable name extracted from the given string.
 */
char	*get_variable_name(char *full_var)
{
	int		var_name_len;
	char	*p;
	char	*name;

	p = ft_strchr(full_var, '=');
	if (!p)
	{
		return (full_var);
	}
	var_name_len = ft_strlen(full_var) - ft_strlen(p);
	if (full_var[var_name_len - 1] == '+')
	{
		p--;
		var_name_len--;
	}
	name = malloc(sizeof(char) * var_name_len + 1);
	name[var_name_len] = '\0';
	ft_strncpy(name, full_var, (p - full_var));
	return (name);
}

t_list	*create_new_node(t_list *temp_list, t_list **list_sorted, t_list *prev)
{
	t_list	*new_nd;

	new_nd = ft_lstnew(temp_list->content);
	if (prev == NULL)
	{
		new_nd->next = *list_sorted;
		*list_sorted = new_nd;
	}
	else
	{
		new_nd->next = prev->next;
		prev->next = new_nd;
	}
	return (new_nd);
}

/**
 * @brief Sorts a linked list in ascending order based on the content of each
 * node.
 *
 * @param list The linked list to be sorted.
 * @return The sorted linked list.
 */
t_list	*sort_list(t_list *list)
{
	t_list	**sorted_list_tmp;
	t_list	*list_sorted;
	t_list	*temp_list;
	t_list	*prev;

	list_sorted = NULL;
	temp_list = list;
	while (temp_list)
	{
		sorted_list_tmp = &list_sorted;
		prev = NULL;
		while (*sorted_list_tmp
			&& ft_strncmp(temp_list->content, (*sorted_list_tmp)->content,
				var_name_length(temp_list->content)) > 0)
		{
			prev = *sorted_list_tmp;
			sorted_list_tmp = &(*sorted_list_tmp)->next;
		}
		create_new_node(temp_list, &list_sorted, prev);
		temp_list = temp_list->next;
	}
	return (list_sorted);
}
