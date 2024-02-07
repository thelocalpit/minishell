/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:27:15 by deggio            #+#    #+#             */
/*   Updated: 2024/02/07 18:41:39 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_paths(t_attr *att)
{
	t_list *tmp_list;

	tmp_list = att->env_list;
	while (tmp_list)
	{
		if (ft_strncmp(tmp_list->content, "PATH=", 5) == 0)
		{
			att->paths = ft_split(tmp_list->content + 5, ':');
			// ft_print_array(att->paths);
			return (1);
		}
		tmp_list = tmp_list->next;
	}
	return (0);
}

int	do_execve(t_attr *att)
{
	envp_to_matrix(att);
	if (ft_strchr(att->arr2[0], '.') || ft_strchr(att->arr2[0], '/'))
		absolute_exec(att);
	else
		bin_exec(att);
	free_arr(att->env);
	return (0);
}

// VANNO GESTITI I SEGNALI PER QUITTARE I PROCESSI FIGLI

//controllare la gestione di g_value 

int	exec(t_attr *att)
{
	set_signals2();
	att->pid = fork();
	if (!find_paths(att))
	{
		perror("PATH not found");
		return (1);
	}
	if (att->pid == -1)
	{
		perror("fork failed");
		return (1);
	}
	if (att->pid == 0)
	{
		if (!att->skip)
			do_red(att);
		if (!att->skip)
			do_child_cmd(att);
		free_arr(att->paths);
		// free(att->paths);
		exit(g_value);
	}
	else
		waitpid(att->pid, &g_value, 0);
	if (att->read_from_pipe)
		att->pipe_index++;
	close_pipeline(att);
	free_arr(att->paths);
	// free(att->paths);
	return (0);
}
