/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:34:32 by alesac            #+#    #+#             */
/*   Updated: 2023/12/23 16:40:42 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_builtin(char **args, char **env, t_list env_list)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "pwd\0", 4) == 0)
			return (pwd((char **) env));
		if (ft_strncmp(args[i], "export\0", 7) == 0)
			return (ft_export((char **) args, env_list));
		if (ft_strncmp(args[i], "unset\0", 6) == 0)
			return (ft_unset((char **) args, &env_list));
		if (ft_strncmp(args[i], "env\0", 4) == 0)
			return (envi((char **) env));
		if (ft_strncmp(args[i], "ls\0", 3) == 0)
			return (ls_l((char **) env, 0));
		if (strstr(args[i], "echo") != NULL)
			return (echo((char **) args));
		if (ft_strncmp(args[i], "exit\0", 5) == 0)
			ft_exit();
		if (ft_strncmp(args[i], "cd\0", 3) == 0)
			ft_cd((char **) args);
		printf("%s: command not found\n", args[i]);
		i++;
	}
	return (0);
}

void	ft_exit()
{
	exit(1);
}
