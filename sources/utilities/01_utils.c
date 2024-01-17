/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:23:47 by mcoppola          #+#    #+#             */
/*   Updated: 2024/01/17 15:35:18 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* questa funzione aggiunge un id ad ogni nodo. necessaria quando lavoriamo 
    con l'expander. */

void add_index_to_list(t_attr *att)
{
    int i;

    t_list *current = att->env_list;
    i = 0;
    while (att->env_list != NULL)
    {
        att->env_list->$flag = i;
        i++;
        att->env_list = att->env_list->next;
    }
    att->env_list = current;
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

    head = ft_lstnew((void *)*env++);
    while (*env)
    {
        ft_lstadd_back(&head, ft_lstnew(*env));
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
    name = malloc(sizeof(char) * var_name_length + 1);
    ft_strncpy(name, full_var, p - full_var);
    return (name);
}

t_list *sort_list(t_list *list)
{
    t_list *sorted_list;
    t_list **sorted_list_temp;
    t_list *prev;
    t_list *new_node;
    char *tempA;

    sorted_list = NULL;
    while (list)
    {
        tempA = get_var_name(list->content);
        sorted_list_temp = &sorted_list;
        prev = NULL;
        while (*sorted_list_temp &&
            ft_strcmp(tempA, get_var_name((*sorted_list_temp)->content)) > 0)
        {
            prev = *sorted_list_temp;
            sorted_list_temp = &(*sorted_list_temp)->next;
        }
        new_node = ft_lstnew(list->content);
        if (prev == NULL) {
            new_node->next = sorted_list;
            sorted_list = new_node;
        } else {
            new_node->next = prev->next;
            prev->next = new_node;
        }
        list = list->next;
    }
    return sorted_list;
}
