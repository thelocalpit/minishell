/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:34:32 by alesac            #+#    #+#             */
/*   Updated: 2024/02/10 15:22:58 by pfalasch         ###   ########.fr       */
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
			|| (att->arr2[0][0] >= 97 && att->arr2[0][0] <= 122))
			&& (att->arr2[0][0] != '='))
			return (add_var(att->arr2[0], att));
	}
	g_value = exec(att);
	set_signals();
	return (g_value);
}

int	do_child_cmd(t_attr *att)
{
	if (built_in_check(att))
		return (0);
	if (ft_strncmp(att->arr2[0], "pwd\0", 4) == 0)
		return (pwd(att));
	else if (ft_strncmp(att->arr2[0], "env\0", 4) == 0)
		return (envi(att));
	else if (ft_strncmp(att->arr2[0], "export\0", 7) == 0)
		return (ft_export(att->arr2, att));
	else if (ft_strncmp(att->arr2[0], "echo\0", 5) == 0)
		return (echo(att->arr2));
	else
	{
		// printf("entro qui quando faccio minishell\n");
		return (do_execve(att));
	}
}

int	built_in_check(t_attr *att)
{
	if ((!ft_strncmp(att->arr2[0], "export\0", 7) && att->arr2[1])
		|| !ft_strncmp(att->arr2[0], "unset\0", 6)
		|| !ft_strncmp(att->arr2[0], "exit\0", 5)
		|| !ft_strncmp(att->arr2[0], "cd\0", 3)
		|| ft_strchr(att->arr2[0], '='))
		return (1);
	return (0);
}

void	ft_exit(void)
{
	exit(1);
}
