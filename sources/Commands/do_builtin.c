/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:34:32 by alesac            #+#    #+#             */
/*   Updated: 2024/02/03 19:05:31 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_builtin(t_attr *att)
{
	if (!att->write_to_pipe && ! att->read_from_pipe
		&& !att->read_from_file && !att->redir && !att->heredoc
		&& !att->skip)
	{
		if (ft_strncmp(att->arr2[0], "export\0", 7) == 0)
			return (ft_export(att->arr2, att));
		else if (ft_strncmp(att->arr2[0], "unset\0", 6) == 0)
			return (ft_unset(att->arr2, att));
		else if (ft_strncmp(att->arr2[0], "exit\0", 5) == 0)
		{
			ft_exit_custom(att);
			// ft_exit();
			return (0);
		}
		else if (ft_strncmp(att->arr2[0], "cd\0", 3) == 0)
			return (ft_cd(att->arr2));
		else if (ft_strchr(att->arr2[0], '=') != NULL
			&& ((att->arr2[0][0] >= 65 && att->arr2[0][0] <= 90)
			|| (att->arr2[0][0] >= 97 && att->arr2[0][0] <= 122)))
			return (add_var(att->arr2[0], att));
	}
	exec(att);
	set_signals();
	return (0);
}

int	do_child_cmd(t_attr *att)
{
	if (ft_strncmp(att->arr2[0], "pwd\0", 4) == 0)
		return (pwd(att));
	else if (ft_strncmp(att->arr2[0], "env\0", 4) == 0)
		return (envi(att));
	//else if (strstr(att->arr2[0], "echo") != NULL)
	//	return (echo(att->arr2));
	else
	{
		//printf("do_child_cmd_here\n");
		do_execve(att);
	}
	return (0);
}

void	ft_exit(void)
{
	exit(1);
}
