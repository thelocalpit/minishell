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
void write_pipe(t_attr *att)
{
	if (att->pipe_index_num >= att->pipes_num)
		return;
	close(att->pipes_fd[att->pipe_index_num][0]);
	dup2(att->pipes_fd[att->pipe_index_num][WRITE_END], STDOUT_FILENO);
	if (att->pipes_fd[att->pipe_index_num] == NULL)
		close(att->pipes_fd[att->pipe_index_num][1]);
}

/* questo serve per leggere dalla pipe. prima di tutto chiudiamo
	la parte del write_end (che non serve).
	poi utilizziamo la funzione dup2 che ci consente di
	reinderizzare l'uscita di read con lo stdin (== 0).
	*/

void read_pipe(t_attr *att)
{
	close(att->pipes_fd[att->pipe_index_num][1]);
	dup2(att->pipes_fd[att->pipe_index_num][READ_END], STDIN_FILENO);
	if (att->pipes_fd[att->pipe_index_num] == NULL)
		close(att->pipes_fd[att->pipe_index_num][0]);
}

/* questa funzione è necessaria per chiudere i lati del read_end
	e del write_end della pipe in questione.  */

void close_pipeline(t_attr *att)
{
	if (att->pipe_index_num > 0)
		close(att->pipes_fd[att->pipe_index_num - 1][READ_END]);
	if (att->pipe_index_num < att->pipes_num)
		close(att->pipes_fd[att->pipe_index_num][WRITE_END]);
}

/* questa funzione serve per contare il numero di pipe nella readline */

int	counter_pipes(t_attr *att)
{
	int	i;

	att->pipes_num = 0;
	i = 0;
	while (att->split_array[i])
	{
		if (!ft_strcmp(att->split_array[i], "|"))
			att->pipes_num++;
		i++;
	}
	if (att->pipes_num == 0)
		return (0);
	return (1);
}

void  init_pipes(t_attr *att)
{
	int i;

	att->pipes_fd = ft_calloc(att->pipes_num + 1, sizeof(int *));
	if (!att->pipes_fd)
		return;
	i = -1;
	while (++i < att->pipes_num)
	{
		att->pipes_fd[i] = malloc(2 * sizeof(int));
		pipe(att->pipes_fd[i]);
	}
}
