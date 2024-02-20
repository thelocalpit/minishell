/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:45:28 by asacchin          #+#    #+#             */
/*   Updated: 2024/01/29 15:34:30 by mcoppola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


/* questa funzione serve per scrivere dalla pipe. prima di tutto chiudiamo
	la parte della pipe che non ci serve che in questo caso è la lettura.
	poi utilizziamo la dup2 per reindirizzare il fd su stdout (==1). */
void write_to_pipe(t_attr *att)
{
	if (att->pipe_index >= att->nb_pipes)
		return;
	close(att->pipesfd[att->pipe_index][0]);
	dup2(att->pipesfd[att->pipe_index][WRITE_END], STDOUT_FILENO);
	if (att->pipesfd[att->pipe_index] == NULL)
		close(att->pipesfd[att->pipe_index][1]);
}

/* questo serve per leggere dalla pipe. prima di tutto chiudiamo
	la parte del write_end (che non serve).
	poi utilizziamo la funzione dup2 che ci consente di
	reinderizzare l'uscita di read con lo stdin (== 0).
	*/

void read_from_pipe(t_attr *att)
{
	close(att->pipesfd[att->pipe_index][1]);
	dup2(att->pipesfd[att->pipe_index][READ_END], STDIN_FILENO);
	if (att->pipesfd[att->pipe_index] == NULL)
		close(att->pipesfd[att->pipe_index][0]);
}

/* questa funzione è necessaria per chiudere i lati del read_end
	e del write_end della pipe in questione.  */

void close_pipeline(t_attr *att)
{
	if (att->pipe_index > 0)
		close(att->pipesfd[att->pipe_index - 1][READ_END]);
	if (att->pipe_index < att->nb_pipes)
		close(att->pipesfd[att->pipe_index][WRITE_END]);
}

/* questa funzione serve per contare il numero di pipe nella readline */

int	count_pipes(t_attr *att)
{
	int	i;

	att->nb_pipes = 0;
	i = 0;
	while (att->split_arr[i])
	{
		if (!ft_strcmp(att->split_arr[i], "|"))
			att->nb_pipes++;
		i++;
	}
	if (att->nb_pipes == 0)
		return (0);
	return (1);
}

void  init_pipes(t_attr *att)
{
	int i;

	att->pipesfd = ft_calloc(att->nb_pipes + 1, sizeof(int *));
	if (!att->pipesfd)
		return;
	i = -1;
	while (++i < att->nb_pipes)
	{
		att->pipesfd[i] = malloc(2 * sizeof(int));
		pipe(att->pipesfd[i]);
	}
}
