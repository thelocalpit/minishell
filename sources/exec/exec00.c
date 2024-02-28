/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:36:25 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 15:31:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Executes the command using execve system call.
 *
 * @param att The attribute structure containing command information.
 * @return The exit status of the executed command.
 */
int	do_execve(t_attr *att)
{
	env_to_matrix(att);
	if (ft_strchr(att->array2[0], '.') || ft_strchr(att->array2[0], '/'))
	{
		att->value = ft_ecxev(att->array2[0], att->array2, att->env);
	}
	else
		att->value = binary_executer(att);
	return (free_matrix(att->env), att->value);
}

/**
 * @brief Searches for the "PATH" environment variable in the given attribute
 * structure. If found, splits the value by ':' delimiter and stores the paths
 * in the attribute structure. If not found, allocates memory for an empty paths
 * array.
 *
 * @param att: The attribute structure containing the environment list and paths
 * array.
 *
 * @return 1 if "PATH" environment variable is found, 0 otherwise.
 */
int	paths_finder(t_attr *att)
{
	t_list	*temp_list;

	temp_list = att->env_list;
	while (temp_list)
	{
		if (ft_strncmp(temp_list->content, "PATH=", 5) == 0)
		{
			att->paths = ft_split(temp_list->content + 5, ':');
			return (1);
		}
		temp_list = temp_list->next;
	}
	att->paths = malloc(sizeof(char *) * 1);
	att->paths[0] = 0;
	return (0);
}

/**
 * @brief Performs redirection operations based on the given attributes.
 *
 * This function handles redirection operations by reading from pipes, checking
 *  read files, checking redirections, and writing to pipes. It also updates
 * the attribute's y value based on the index of the redirection or read file.
 * Additionally, it calls the next step sub-function if there are more steps
 * to be executed. Finally, it sets the skip flag if it is the first
 * redirection operation.
 *
 * @param att The attribute structure containing information about the execution.
 */
void	do_redirect(t_attr *att)
{
	int	temp_y;

	if (att->first_redir)
		att->y--;
	temp_y = att->y;
	if (att->read_pipe)
		read_pipe(att);
	check_read_file(att);
	att->y = temp_y;
	check_redirections(att);
	if (att->i_redir > att->i_readfile)
		att->y = att->i_redir + 1;
	else if (att->i_readfile != 0)
		att->y = att->i_readfile + 1;
	if (att->split_array[att->y] && att->split_array[att->y + 1])
		sub_next_step(att);
	if (att->write_pipe && att->read_pipe)
		att->pipe_index_num++;
	if (att->write_pipe)
		write_pipe(att);
	att->y = temp_y;
	if (att->first_redir)
		att->skip = 1;
}

/**
 * @brief This function is responsible for executing the child process in
 * the minishell. It sets the signal handler for the child process, performs
 *  input/output redirection, executes the child command, frees the array of
 *  paths, and exits with the return value of the child command.
 *
 * @param att The attribute structure containing information about the command
 *  execution.
 */
void	if_child(t_attr *att)
{
	set_child_signal();
	if (!att->skip)
		do_redirect(att);
	if (!att->skip)
		att->value = child_command(att);
	free_matrix(att->paths);
	exit(att->value);
}

/**
 * Executes a command by forking a child process and running the appropriate
 * code.
 *
 * @param att The attribute structure containing the necessary information for
 * execution.
 * @return Returns the exit status of the executed command.
 */
int	exec(t_attr *att)
{
	att->pid = fork();
	paths_finder(att);
	if (att->pid == -1)
		return (ft_putstr_fd("fork failed", 2), 1);
	if (att->pid == 0)
		if_child(att);
	set_signal_avoid();
	waitpid(att->pid, &att->value, 0);
	att->value = WEXITSTATUS(att->value);
	set_signal();
	if (g_sig_val == SIGINT)
	{
		printf("\n");
		att->value = 130;
	}
	g_sig_val = 0;
	if (att->value == 127)
		not_found_command(att->array2[0]);
	if (att->read_pipe)
		att->pipe_index_num++;
	close_pipeline(att);
	return (free_matrix(att->paths), att->value);
}
