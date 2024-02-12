/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:27:15 by deggio            #+#    #+#             */
/*   Updated: 2024/02/12 19:55:48 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_paths(t_attr *att)
{
	t_list	*tmp_list;

	tmp_list = att->env_list;
	while (tmp_list)
	{
		if (ft_strncmp(tmp_list->content, "PATH=", 5) == 0)
		{
			att->paths = ft_split(tmp_list->content + 5, ':');
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
		g_value = ft_ecxev(att->arr2[0], att->arr2, att->env);
	else
	{
		set_signals();
		g_value = bin_exec(att);
		set_signals2();
	}
	free_arr(att->env);
	return (g_value);
}

// VANNO GESTITI I SEGNALI PER QUITTARE I PROCESSI FIGLI

//controllare la gestione di g_value 

int	exec(t_attr *att)
{
	set_signals2();
	att->pid = fork();
	if (!find_paths(att))
	{
		ft_putstr_fd("PATH not found", 2);
		return (1);
	}
	if (att->pid == -1)
	{
		ft_putstr_fd("fork failed", 2);
		return (1);
	}
	if (att->pid == 0)
	{
		if (!att->skip)
			do_red(att);
		if (!att->skip)
			g_value = do_child_cmd(att);
		free_arr(att->paths);
		// free(att->paths);
		exit(g_value);
	}
	else
		waitpid(att->pid, &g_value, 0);
	g_value = WEXITSTATUS(g_value);
	errno = -1;
	if (g_value == 127)
		command_not_found(att->arr2[0]);
	if (att->read_from_pipe)
		att->pipe_index++;
	close_pipeline(att);
	free_arr(att->paths);
	// free(att->paths);
	return (g_value);
}
