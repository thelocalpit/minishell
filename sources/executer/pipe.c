/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:45:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/14 14:22:38 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void write_to_pipe(t_attr *att)
{
	if (att->pipe_index >= att->nb_pipes)
		return;
	close(att->pipesfd[att->pipe_index][0]);
	dup2(att->pipesfd[att->pipe_index][WRITE_END], STDOUT_FILENO);
	if (att->pipesfd[att->pipe_index] < 0)
		close(att->pipesfd[att->pipe_index][1]);
}

void read_from_pipe(t_attr *att)
{
	close(att->pipesfd[att->pipe_index][1]);
	dup2(att->pipesfd[att->pipe_index][READ_END], STDIN_FILENO);
	if (att->pipesfd[att->pipe_index] < 0)
		close(att->pipesfd[att->pipe_index][0]);
}

void close_pipeline(t_attr *att)
{
	if (att->pipe_index > 0)
		close(att->pipesfd[att->pipe_index - 1][READ_END]);
	if (att->pipe_index < att->nb_pipes)
		close(att->pipesfd[att->pipe_index][WRITE_END]);
}

void	count_pipes(t_attr *att)
{
	int	i;

	att->nb_pipes = 0;
	i = 0;
	while (att->split_arr[i])
	{
		if (ft_strcmp(att->split_arr[i], "|"))
			att->nb_pipes++;
		i++;
	}
}

void init_pipes(t_attr *att)
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
