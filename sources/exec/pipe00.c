/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:36:31 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 13:36:32 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Writes the output of the current command to the next command in the
 *  pipeline.
 *
 * This function is responsible for redirecting the standard output of the
 * current command to the input of the next command in the pipeline. It uses
 *  the pipe file descriptors stored in the `att` structure to establish the
 * connection between the commands.
 *
 * @param att The attribute structure containing information about the
 * pipeline.
 */
void	write_pipe(t_attr *att)
{
	if (att->pipe_index_num >= att->pipes_num)
		return ;
	close(att->pipes_fd[att->pipe_index_num][0]);
	dup2(att->pipes_fd[att->pipe_index_num][WRITE_END], STDOUT_FILENO);
	if (att->pipes_fd[att->pipe_index_num] == NULL)
	{
		close(att->pipes_fd[att->pipe_index_num][1]);
	}
}

/**
 * @brief Reads from the pipe and redirects the input to the standard input
 * file descriptor.
 *
 * @param att The attribute structure containing pipe file descriptors and
 * index.
 */
void	read_pipe(t_attr *att)
{
	close(att->pipes_fd[att->pipe_index_num][1]);
	dup2(att->pipes_fd[att->pipe_index_num][READ_END], STDIN_FILENO);
	if (att->pipes_fd[att->pipe_index_num] == NULL)
	{
		close(att->pipes_fd[att->pipe_index_num][0]);
	}
}

/**
 * @brief Closes the file descriptors of the pipeline.
 *
 * This function is responsible for closing the file descriptors of the
 * pipeline. It closes the read end of the previous pipe if the current
 * pipe index is greater than 0, and it closes the write end of the current
 * pipe if the current pipe index is less than the total number of pipes.
 *
 * @param att The attribute structure containing information about the
 * pipeline.
 */
void	close_pipeline(t_attr *att)
{
	if (att->pipe_index_num > 0)
	{
		close(att->pipes_fd[att->pipe_index_num - 1][READ_END]);
	}
	if (att->pipes_num > att->pipe_index_num)
	{
		close(att->pipes_fd[att->pipe_index_num][WRITE_END]);
	}
}

/**
 * @brief Counts the number of pipes in the given command.
 *
 * @param att The attribute structure containing the command to be executed.
 * @return 1 if the command contains pipes, 0 otherwise.
*/
int	counter_pipes(t_attr *att)
{
	int	c;

	att->pipes_num = 0;
	c = 0;
	while (att->split_array[c])
	{
		if (!ft_strcmp(att->split_array[c], "|"))
		{
			att->pipes_num++;
		}
		c++;
	}
	if (att->pipes_num == 0)
	{
		return (0);
	}
	return (1);
}

/**
 * @brief Initializes the pipes for inter-process communication.
 *
 * @param att The attribute structure containing pipe information.
 */
void	init_pipes(t_attr *att)
{
	int	c;

	att->pipes_fd = ft_calloc(att->pipes_num + 1, sizeof(int *));
	if (!att->pipes_fd)
		return ;
	c = -1;
	while (++c < att->pipes_num)
	{
		att->pipes_fd[c] = malloc(sizeof(int) * 2);
		pipe(att->pipes_fd[c]);
	}
}
