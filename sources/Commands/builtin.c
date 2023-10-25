/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesac <alesac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:55:31 by alesac            #+#    #+#             */
/*   Updated: 2023/10/25 15:10:25 by alesac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_builtin(char **args, char **env)
{
	int i;
	
	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "echo\0", 5) == 0 || ft_strncmp(args[i], "pwd\0", 4) == 0 || ft_strncmp(args[i], "env\0", 4) == 0)
		{
			if (ft_strncmp(args[i], "echo\0", 5) == 0)
				return (echo((char **) args));
			if (ft_strncmp(args[i], "pwd\0", 4) == 0)
				return (pwd((char **) env));
			if (ft_strncmp(args[i], "env\0", 4) == 0)
				return (envi((char **) env));
		}
		i++;
	}
	return (0);
}

int	echo(char **args)
{
	int	i;
	int newline;

	i = 1;
	if(args[1] && !strcmp(args[1], "-n"))
	{
		newline = 1;
		i++;
	}
	else 
		newline = 0;
	while (args[i])
	{
		printf("%s", args[i]);
		i++;
	}
	if(!newline)
	{
		printf("\n");
	}
	return (0);
}

int	pwd(char **env)
{
	(void)env;
	
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd error!");
		return (1);
	}
	printf("%s\n", cwd);
	return (0);
}

int	envi(char **env)
{
	int	i;

	i = -1;
	while (env[++i] != NULL)
		printf("%s\n", env[i]);
	return(0);
}

void fake_parser()
{
	
}