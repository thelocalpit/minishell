/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:37 by mcoppola          #+#    #+#             */
/*   Updated: 2023/12/12 23:42:55 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

int basic_export(t_list env_list)
{
    t_list *env;

    env = &env_list;
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

    // se il 1 carattere della stringa da aggiungere è > del 1 carattere del nome della carattere d'ambiente confrontata
    // allora vai alla variabile successiva altrimenti controlla tutti gli altri caratteri,
    // se il carattere confrontato è == vai al carattere successivo,
    // altrimenti TI FERMI e metti come "next", del nodo precedente, il puntatore alla stringa da aggiungere
    // e come "next" della stringa da aggiungere il "next" del nodo precedente
    // --Fermarsi quando la lista è finita e aggiungere alla fine
    // SE PERO tutti i caratteri sono uguali allora sostituisci tutto il content con la stringa attuale
    t_list  *env;

    env = &env_list;

    while (env)
    {
        printf("sss %d", ft_strcmp(arg, (char *)env->content));
        env = env->next;
    }
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

