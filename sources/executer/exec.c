/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:27:15 by mcoppola            #+#    #+#             */
/*   Updated: 2024/02/16 18:32:43 by asacchin         ###   ########.fr       */
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
	// signal(SIGQUIT, SIG_IGN);
	envp_to_matrix(att);
	if (ft_strchr(att->array2[0], '.') || ft_strchr(att->array2[0], '/'))
		att->value = ft_ecxev(att->array2[0], att->array2, att->env);
	else
	{
		att->value = bin_executer(att);
	}
	free_arr(att->env);
	return (att->value);
}

// VANNO GESTITI I SEGNALI PER QUITTARE I PROCESSI FIGLI

//controllare la gestione di att.value

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
			att->value = do_child_cmd(att);
		free_arr(att->paths);
		// free(att->paths);
		exit(att->value);
	}
	set_signal_avoid(); //SIGNAL SPENTI
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
		command_not_found(att->array2[0]);
	if (att->read_pipe)
		att->pipe_index_num++;
	close_pipeline(att);
	free_arr(att->paths);
	// free(att->paths);
	return (att->value);
}
