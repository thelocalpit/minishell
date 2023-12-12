/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:23:47 by mcoppola          #+#    #+#             */
/*   Updated: 2023/12/12 18:39:39 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list *copy_env_in_list(char **env)
{
    t_list *head;

    head = ft_lstnew((void *)*env++);
    printf("head: %s\n", *env);
    while (*env)
    {
        ft_lstadd_back(&head, ft_lstnew(*env));
        env++;
    }
    return (head);
}
