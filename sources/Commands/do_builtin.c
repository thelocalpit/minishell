/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:34:32 by alesac            #+#    #+#             */
/*   Updated: 2023/12/29 13:48:48 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_builtin(char **args, char **env, t_list env_list, t_attr *att)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "pwd\0", 4) == 0)
			return (pwd((char **) env));
		else if (ft_strncmp(args[i], "export\0", 7) == 0)
			return (ft_export((char **) args, env_list));
		else if (ft_strncmp(args[i], "unset\0", 6) == 0)
			return (ft_unset((char **) args, &env_list));
		else if (ft_strncmp(args[i], "env\0", 4) == 0)
			return (envi((char **) env));
		else if (ft_strncmp(args[i], "ls\0", 3) == 0)
			return (ls_l((char **) env, 0));
		else if (strstr(args[i], "echo") != NULL)
			return (echo((char **) args));
		else if (ft_strncmp(args[i], "exit\0", 5) == 0)
		{
			ft_exit();
			return (0);
		}
		else if (ft_strncmp(args[i], "cd\0", 3) == 0)
		{
			ft_cd((char **) args);
			return (0);
		}
		else if (ft_strchr(args[i], '=') != NULL
			&& ((args[i][0] >= 65 && args[i][0] <= 90)
				|| (args[i][0] >= 97 && args[i][0] <= 122)))
			return (add_var(args[i], &(att->local_var)));
		else
			printf("%s: command not found\n", args[i]);
		i++;
	}
	return (0);
}

void	ft_exit(void)
{
	exit(1);
}
