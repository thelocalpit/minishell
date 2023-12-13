/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:23:47 by mcoppola          #+#    #+#             */
/*   Updated: 2023/12/13 14:40:53 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


// t_list  *insert_between_node(t_list list, char *content)
// {
//     t_list  *list_;
//     t_list  *temp_next;
//     t_list  *new_node;

//     list_ = &list;
//     temp_next = list_->next;
//     new_node = ft_lstnew(content);
//     new_node->next = temp_next;
//     return (list_);
// }

// t_list  *sort_list(t_list list)
// {
//     t_list  *sorted_list;
//     t_list  **sorted_list_temp;
//     t_list  *list_;
//     char    *tempA;
//     char    *tempB;
//     t_list  *prev;

//     list_ = &list;
//     sorted_list = ft_lstnew(list_->content);
//     list_ = list_->next;
//     while (list_)
//     {
//         tempA = get_var_name(list_->content);
//         *sorted_list_temp = &sorted_list;
//         prev = *sorted_list_temp;
//         while (*sorted_list_temp)
//         {
//             tempB = get_var_name(*sorted_list_temp->content);
//             if (ft_strcmp(tempA, tempB) < 0)
//                 insert_between_node(*prev, list_->content);
//             else if (ft_strcmp(tempA, tempB) == 0)
//                 printf("--%s---%s---0\n", tempA, tempB);
//             prev = *sorted_list_temp;
//             *sorted_list_temp = *sorted_list_temp->next;
//         }
//         ft_lstadd_back(&sorted_list, ft_lstnew((char *)list_->content));

//         prev = list_;
//         list_ = list_->next;
//     }
//     return (sorted_list);
// }

void insert_between_node(t_list *prev, char *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->content = content;
    new_node->next = prev->next;
    prev->next = new_node;
}

t_list *ft_lstnew2(char *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}
t_list  *copy_env_in_list(char **env)
{
    t_list *head;

    head = ft_lstnew2((void *)*env++);
    while (*env)
    {
        ft_lstadd_back(&head, ft_lstnew2(*env));
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
    var_name_length = ft_strlen(full_var) - ft_strlen(p);
    name = malloc(sizeof(char) * var_name_length + 1);
    ft_strncpy(name, full_var, p - full_var);
    return (name);
}

t_list *sort_list(t_list *list) {
    t_list *sorted_list;
    t_list **sorted_list_temp;
    t_list *prev;
    t_list *new_node;
    char *tempA;

    sorted_list = NULL;
    while (list) {
        tempA = get_var_name(list->content);
        sorted_list_temp = &sorted_list;
        prev = NULL;

        // Find the correct position to insert the current element in the sorted list
        while (*sorted_list_temp && ft_strcmp(tempA, get_var_name((*sorted_list_temp)->content)) > 0) {
            prev = *sorted_list_temp;
            sorted_list_temp = &(*sorted_list_temp)->next;
        }

        // Insert the current element into the sorted list
        new_node = ft_lstnew2(list->content);
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
