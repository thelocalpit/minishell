/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:34:32 by alesac            #+#    #+#             */
/*   Updated: 2024/02/21 11:07:02 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_builtin(t_attr *att)
{
	if (!att->write_pipe && ! att->read_pipe
		&& !att->read_files && !att->redir && !att->heredoc
		&& !att->skip)
	{
		if (ft_strncmp(att->array2[0], "export\0", 7) == 0)
			return (ft_export(att->array2, att));
		else if (ft_strncmp(att->array2[0], "unset\0", 6) == 0)
			return (ft_unset(att->array2, att));
		else if (ft_strncmp(att->array2[0], "exit\0", 5) == 0)
		{
			ft_exit_custom(att);
			// ft_exit();
			return (0);
		}
		else if (ft_strncmp(att->array2[0], "cd\0", 3) == 0)
			return (ft_cd(att->array2));
		else if (ft_strchr(att->array2[0], '=') != NULL
			&& ((att->array2[0][0] >= 65 && att->array2[0][0] <= 90)
			|| (att->array2[0][0] >= 97 && att->array2[0][0] <= 122))
			&& (att->array2[0][0] != '='))
			return (add_var(att->array2[0], att));
	}
	att->value = exec(att);
	return (att->value);
}

int	do_child_command(t_attr *att)
{
	if (built_in_check(att))
		return (0);
	if (ft_strncmp(att->array2[0], "pwd\0", 4) == 0)
		return (pwd(att));
	else if (ft_strncmp(att->array2[0], "env\0", 4) == 0)
		return (envi(att));
	else if (ft_strncmp(att->array2[0], "export\0", 7) == 0)
		return (ft_export(att->array2, att));
	else if (ft_strncmp(att->array2[0], "echo\0", 5) == 0)
		return (echo(att->array2));
	else
	{
		// printf("entro qui quando faccio minishell\n");
		return (do_execve(att));
	}
}

int	built_in_check(t_attr *att)
{
	if ((!ft_strncmp(att->array2[0], "export\0", 7) && att->array2[1])
		|| !ft_strncmp(att->array2[0], "unset\0", 6)
		|| !ft_strncmp(att->array2[0], "exit\0", 5)
		|| !ft_strncmp(att->array2[0], "cd\0", 3)
		|| ft_strchr(att->array2[0], '='))
		return (1);
	return (0);
}

void	ft_exit(void)
{
	exit(1);
}
