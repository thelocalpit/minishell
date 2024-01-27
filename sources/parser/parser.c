/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:40:12 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/27 17:00:28 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// qui è dove settiamo le giuste flag per andare a dire al prossimo cmd
// dove dovrà andare a leggere (se non  è il primo) e dove dovrà scrivere 
// se c'è una successiva PIPE

/* in questa funzione andiamo a resettare le flags che servono per
	reindirizzare gli output e prendere gli input in caso di arrivo da pipe */

void	reset_flags(t_attr *att)
{
	att->write_to_pipe = 0;
	att->redir = 0;
	att->read_from_pipe = 0;
	att->read_from_file = 0;
	att->heredoc = 0;
	att->skip = 0;
	att->create_file = 0;
	att->only_create = 0;
}

void	next_step_sub2(t_attr *att)
{
	if (!ft_strcmp(att->split_arr[att->y - 1], "|"))
		att->read_from_pipe = 1;
	if (!ft_strcmp(att->split_arr[att->y - 1], ">>")
		|| !ft_strcmp(att->split_arr[att->y - 1], ">"))
	{
		att->redir = 0;
		att->skip = 1;
	}
	if (!ft_strcmp(att->split_arr[att->y - 1], "<"))
		att->skip = 1;
	if (!ft_strcmp(att->split_arr[att->y - 1], "<<"))
		att->skip = 1;
}

void	next_step_sub(t_attr *att)
{
	if (!ft_strcmp(att->split_arr[att->y + 1], "|"))
		att->write_to_pipe = 1;
	else if (!ft_strcmp(att->split_arr[att->y + 1], ">")
		|| !ft_strcmp(att->split_arr[att->y + 1], ">>"))
		att->redir = 1;
	else if (!ft_strcmp(att->split_arr[att->y + 1], "<"))
	{
		att->read_from_file = 1;
		if (att->split_arr[att->y + 3]
			&& !ft_strcmp(att->split_arr[att->y + 3], "|"))
			att->write_to_pipe = 1;
	}
	else if (!ft_strcmp(att->split_arr[att->y + 1], "<<"))
		att->heredoc = 1;
}
	/* in questa funzione procediamo nel seguente modo:
		1. si resettano le flag.
		2. si controlla se non è un comando singolo per creare un file
		3. se esiste e non è l'ultimo argomento allora si vanno ad attivare le flag
		4. ulteriore controllo se non è il cmd[0] allora andiamo a indagare se
			dobbiamo prendere qualcosa dalla pipe prima e nel caso settiamo 
			la flag   */

int	check_next_step(t_attr *att)
{
	reset_flags(att);
	if (!ft_strcmp(att->split_arr[0], ">")
		|| !ft_strcmp(att->split_arr[0], ">>"))
	{
		att->skip = 1;
		if (!ft_strcmp(att->split_arr[0], ">"))
			att->only_create = 1;
		else
			att->only_create = 2;
	}
	if (att->split_arr[att->y] && att->split_arr[att->y + 1])
		next_step_sub(att);
	if (att->y > 1)
		next_step_sub2(att);
	red_index(att);
	return (0);
}

void	red_index(t_attr *att)
{
	int	y;

	y = att->y + 1;
	while (att->split_arr[y])
	{
		if (!ft_strcmp(att->split_arr[y], ">")
			|| !ft_strcmp(att->split_arr[y], ">>"))
			att->i_redir = y;
		else if (!ft_strcmp(att->split_arr[y], "<")
			|| !ft_strcmp(att->split_arr[y], "<<"))
			att->i_readfile = y;
		if (!ft_strcmp(att->split_arr[y], "|"))
			break ;
		y += 2;
	}
}
