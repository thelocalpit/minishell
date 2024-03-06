/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:31:59 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/22 13:52:44 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_exec(t_attr *strc)
{
	if (!strc->write_pipe && ! strc->read_pipe
		&& !strc->read_files && !strc->redir && !strc->heredoc
		&& !strc->skip)
	{
		if (ft_strncmp(strc->array2[0], "export\0", 7) == 0)
			return (ft_export(strc->array2, strc));
		else if (ft_strncmp(strc->array2[0], "unset\0", 6) == 0)
			return (unset(strc->array2, strc));
		else if (ft_strncmp(strc->array2[0], "exit\0", 5) == 0)
		{
			custom_exit(strc);
			return (0);
		}
		else if (ft_strncmp(strc->array2[0], "cd\0", 3) == 0)
			return (ft_cd(strc->array2, strc));
		else if (ft_strchr(strc->array2[0], '=') != NULL
			&& ((strc->array2[0][0] >= 65 && strc->array2[0][0] <= 90)
			|| (strc->array2[0][0] >= 97 && strc->array2[0][0] <= 122))
			&& (strc->array2[0][0] != '='))
			return (add_var(strc->array2[0], strc));
	}
	strc->value = exec(strc);
	return (strc->value);
}

int	check_builtin(t_attr *strc)
{
	if ((!ft_strncmp(strc->array2[0], "export\0", 7) && strc->array2[1])
		|| !ft_strncmp(strc->array2[0], "unset\0", 6)
		|| !ft_strncmp(strc->array2[0], "exit\0", 5)
		|| !ft_strncmp(strc->array2[0], "cd\0", 3)
		|| ft_strchr(strc->array2[0], '='))
		return (1);
	return (0);
}

int	child_command(t_attr *strc)
{
	if (check_builtin(strc))
		return (0);
	if (ft_strncmp(strc->array2[0], "pwd\0", 4) == 0)
		return (ft_pwd(strc));
	else if (ft_strncmp(strc->array2[0], "env\0", 4) == 0)
		return (ft_enviorment(strc));
	else if (ft_strncmp(strc->array2[0], "export\0", 7) == 0)
		return (ft_export(strc->array2, strc));
	else if (ft_strncmp(strc->array2[0], "echo\0", 5) == 0)
		return (ft_echo(strc->array2));
	else
		return (do_execve(strc));
}
