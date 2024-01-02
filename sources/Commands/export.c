/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:37 by mcoppola          #+#    #+#             */
/*   Updated: 2023/12/29 14:39:43 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

int	basic_export(t_attr *att)
{
	t_list	*export;

	export = sort_list(att->env_list);
	while (export)
	{
		printf("declare -x %s\n", (char *)export->content);
		export = export->next;
	}
	return (0);
}

void	check_duplicate(t_attr *att, char *content)
{
	t_list	*list;

	list = att->env_list;
	while (list)
	{
		if (!ft_strcmp(get_var_name(content), get_var_name((char *)list->content)))
		{
			list->content = ft_strdup(content);
			return ;
		}
		list = list->next;
	}
	ft_lstadd_back(&(att->env_list), ft_lstnew(ft_strdup(content)));
}

int	add_on_env(char *arg, t_attr *att)
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
	t_list	*list;

	list = att->local_var;
	printf("arg: %s\n", arg);
	while (list)
	{
		if (ft_strcmp(arg, get_var_name((char *)list->content)) == 0)
			check_duplicate(att, list->content);
		list = list->next;
	}
	return (0);
}

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
