/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:37 by mcoppola          #+#    #+#             */
/*   Updated: 2023/12/12 18:44:08 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

int basic_export(t_list env_list)
{
    t_list *env;

    env = &env_list;
    printf("basic export\n");
    while (env)
    {
        printf("declare -x %s\n", (char *)env->content);
        env=env->next;
    }
    return (0);
}

int add_on_env(char *arg, t_list env_list)
{
    // appena hai la lista di env, devi cercare se la variabile esiste già o meno (con ft_strncmp)
    // e se esiste devi aggiornarla (con ft_strjoin)
    // e poi devi aggiornare la lista di env (con ft_lstadd_back)
    (void)arg;
    (void)env_list;
    return (0);
}

int ft_export(char **args, t_list env_list)
{
    int i;

    i = 0;
    while (args[i])
    {
        printf("Args: %s\n", args[i]);
        i++;
    }
    if (i == 1)
        return (basic_export(env_list));
    else
    {
        args++;
        while (*args)
        {
            if(!add_on_env(*args, env_list))
                args++;
            else
                return (1);
        }
    }

    return (0);
}

