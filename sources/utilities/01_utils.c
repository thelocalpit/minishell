/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:16:08 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/16 18:16:10 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void add_index_to_custom_env(t_attr *att)
{
	int i;

	t_list *tmp_list = att->env_list;
	i = 0;
	while (att->env_list != NULL)
	{
		att->env_list->$flag = i;
		i++;
		att->env_list = att->env_list->next;
	}
	att->env_list = tmp_list;
}

void add_index_to_local_var(t_attr *att)
{
	int i;

	t_list *tmp_list = att->local_var;
	i = 0;
	while (att->local_var != NULL)
	{
		att->local_var->$flag = i;
		i++;
		att->local_var = att->local_var->next;
	}
	att->local_var = tmp_list;
}

/* questa funzione aggiunge un id ad ogni nodo. necessaria quando lavoriamo
	con l'expander. */
void add_index_to_env_list(t_attr *att)
{
	int i;

	t_list *tmp_list = att->env_list;
	i = 0;
	while (tmp_list != NULL)
	{
		tmp_list->$flag = i;
		i++;
		tmp_list = tmp_list->next;
	}
}

void insert_between_node(t_list *prev, char *content)
{
	t_list *new_node = (t_list *)malloc(sizeof(t_list));
	new_node->content = content;
	new_node->next = prev->next;
	prev->next = new_node;
}

t_list  *copy_env_in_list(char **env)
{
	t_list *head;

	head = ft_lstnew((void *)ft_strdup(*env));
	// head = ft_lstnew((void *)*env);
	env++;
	while (*env)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(*env)));
		// ft_lstadd_back(&head, ft_lstnew(*env));
		env++;
	}
	return (head);
}

char    *get_var_name(char *full_var)
{
	char    *name;
	char    *p;
	int     var_name_length;

	p = ft_strchr(full_var, '=');
	if (!p)
		return (full_var);
	var_name_length = ft_strlen(full_var) - ft_strlen(p);
	if (full_var[var_name_length - 1] == '+')
	{
		var_name_length--;
		p--;
	}
	name = malloc(sizeof(char) * var_name_length + 1);
	name[var_name_length] = '\0';
	ft_strncpy(name, full_var, p - full_var);
	return (name);
}

t_list *sort_list(t_list *list)
{
	t_list *sorted_list;
	t_list **sorted_list_temp;
	t_list *prev;
	t_list *new_node;
	t_list *tmp_list = list;

	sorted_list = NULL;
	while (tmp_list)
	{
		sorted_list_temp = &sorted_list;
		prev = NULL;
		while (*sorted_list_temp &&
			ft_strncmp(tmp_list->content, (*sorted_list_temp)->content, var_name_length(tmp_list->content)) > 0)
		{
			prev = *sorted_list_temp;
			sorted_list_temp = &(*sorted_list_temp)->next;
		}
		new_node = ft_lstnew(tmp_list->content);
		if (prev == NULL) {
			new_node->next = sorted_list;
			sorted_list = new_node;
		} else {
			new_node->next = prev->next;
			prev->next = new_node;
		}
		tmp_list = tmp_list->next;
	}
	return sorted_list;
}
