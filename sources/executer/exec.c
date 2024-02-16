/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:27:15 by deggio            #+#    #+#             */
/*   Updated: 2024/02/16 12:02:06 by mcoppola         ###   ########.fr       */
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
	att->paths = malloc(sizeof(char *) * 1);
	att->paths[0] = 0;
	return (0);
}

int	do_execve(t_attr *att)
{
	envp_to_matrix(att);
	if (ft_strchr(att->arr2[0], '.') || ft_strchr(att->arr2[0], '/'))
		att->g_value = ft_ecxev(att->arr2[0], att->arr2, att->env);
	else
	{
		att->g_value = bin_exec(att);
	}
	free_arr(att->env);
	return (att->g_value);
}

// VANNO GESTITI I SEGNALI PER QUITTARE I PROCESSI FIGLI

//controllare la gestione di att.g_value

int	exec(t_attr *att)
{
	att->pid = fork();
	find_paths(att);
	if (att->pid == -1)
	{
		ft_putstr_fd("fork failed", 2);
		return (1);
	}
	if (att->pid == 0)
	{
		set_signal_child();
		if (!att->skip)
			do_red(att);
		if (!att->skip)
			att->g_value = do_child_cmd(att);
		free_arr(att->paths);
		// free(att->paths);
		exit(att->g_value);
	}
	set_signal_avoid(); //SIGNAL SPENTI
	waitpid(att->pid, &att->g_value, 0);
	att->g_value = WEXITSTATUS(att->g_value);
	set_signal();
	if (g_signal == SIGINT)
	{
		printf("\n");
		att->g_value = 130;
	}
	if (att->g_value == 127)
		command_not_found(att->arr2[0]);
	if (att->read_from_pipe)
		att->pipe_index++;
	close_pipeline(att);
	free_arr(att->paths);
	// free(att->paths);
	return (att->g_value);
}
