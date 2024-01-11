/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:27:15 by deggio            #+#    #+#             */
/*   Updated: 2024/01/11 18:01:30 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exec(t_attr *att)
{
	att->pid = fork();
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
	return (0);
}
