/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:27:15 by deggio            #+#    #+#             */
/*   Updated: 2024/01/12 05:02:47 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_paths(t_attr *att)
{
	while (att->env_list)
	{
		if (ft_strncmp(att->env_list->content, "PATH=", 5) == 0)
		{
			att->paths = ft_split(att->env_list->content + 5, ':');
			return (1);
		}
		att->env_list = att->env_list->next;
	}
	return (0);
}

int	do_execve(t_attr *att)
{
	envp_to_matrix(att);
	if (att->arr2[0][0] == '/')
		absolute_exec(att);
	else if (att->arr2[0][0] == '.')
		binary_exec(att);
	else
		bin_exec(att);
	free_arr(att->env);
	return (0);
}

// VANNO GESTITI I SEGNALI PER QUITTARE I PROCESSI FIGLI

//controllare la gestione di g_value 

int	exec(t_attr *att)
{
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
		do_red(att);
		if (!att->skip)
			do_child_cmd(att);
		exit(g_value);
	}
	else
		waitpid(att->pid, &g_value, 0);
	free(att->paths);
	return (0);
}
