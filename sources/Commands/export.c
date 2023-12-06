/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:37 by mcoppola          #+#    #+#             */
/*   Updated: 2023/12/05 16:32:10 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

int basic_export(char **env)
{
    while (*env)
    {
        printf("declare -x %s\n", *env);
        env++;
    }
    return (0);
}

int add_on_env(char *arg, char **env)
{
    // appena hai la lista di env, devi cercare se la variabile esiste già o meno (con ft_strncmp)
    // e se esiste devi aggiornarla (con ft_strjoin)
    // e poi devi aggiornare la lista di env (con ft_lstadd_back)
    (void)arg;
    (void)env;
    return (0);
}
int ft_export(char **args, char **env)
{
    int i;

    i = 0;
    (void)env;
    while (args[i])
    {
        printf("Args: %s\n", args[i]);
        i++;
    }
    if (i == 1)
        return (basic_export(env));
    else
    {
        args++;
        while (*args)
        {
            if(!add_on_env(*args, env))
                args++;
            else
                return (1);
        }
    }
    return (0);
}
