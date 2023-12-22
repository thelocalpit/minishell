/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesac <alesac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:55:31 by alesac            #+#    #+#             */
/*   Updated: 2023/12/22 10:39:47 by alesac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_builtin(char **args, char **env, t_list env_list)
{
	int 	i;
	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], "export\0", 7) == 0 || ft_strncmp(args[i], "unset\0", 6) == 0 || ft_strncmp(args[i], "echo\0", 5) == 0 || ft_strncmp(args[i], "pwd\0", 4) == 0 || ft_strncmp(args[i], "env\0", 4) == 0 || ft_strncmp(args[i], "ls\0", 3) == 0 || ft_strncmp(args[i], "ls -l\0", 6) == 0 || strstr(args[i], "echo\0") != NULL || ft_strncmp(args[i], "exit\0", 5) == 0 || ft_strncmp(args[i], "cd\0", 3) == 0)
		{
			// if (ft_strncmp(args[i], "echo\0", 5) == 0)
			// 	return (echo((char **) args));
			if (ft_strncmp(args[i], "pwd\0", 4) == 0)
				return (pwd((char **) env));

			if (ft_strncmp(args[i], "export\0", 7) == 0)
				return (ft_export((char **) args, env_list));

			if (ft_strncmp(args[i], "unset\0", 6) == 0)
				return (ft_unset((char **) args, &env_list));

			if (ft_strncmp(args[i], "env\0", 4) == 0)
				return (envi((char **) env));

			if (ft_strncmp(args[i], "ls -l\0", 6) == 0)
				return (ls_l((char **) env, 1));

			if (ft_strncmp(args[i], "ls\0", 3) == 0)
				return (ls_l((char **) env, 0));

			if (strstr(args[i], "echo") != NULL)
				return (echo((char **) args));

			if (ft_strncmp(args[i], "exit\0", 5) == 0)
				ft_exit();
			if (ft_strncmp(args[i], "cd\0", 3) == 0)
				ft_cd((char **) args);
		}
		//else
			//printf("Comando «%s» non trovato\n", args[i]);
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
		printf("%s ", args[i]);
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
	printf(YELLOW_BOLD "%s\n", cwd);
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

int	ls_l(char **env, int j)
{
	pid_t child_pid = fork();
	char *option;

	if (j == 1)
		option = "-l";
	else if (j == 0)
		option = "-h";
	if (child_pid == -1) {
		perror("fork failed");
		return 1;
	} else if (child_pid == 0) {
		// Questo è il processo figlio
		char *ls_args[] = {"/bin/ls", option, NULL};
		execve("/bin/ls", ls_args, env);
		perror("execve failed");
		exit(1);
	}
	return (0);
}

void	ft_cd(char **args)
{
	char	*tmp;

	if (args[1] == NULL)
	{
		tmp = getenv("HOME");
		chdir(tmp);
		//cd_path(main);
	}
	else if (chdir(args[1]) == -1)
	{
		printf(RED"cd : diocane non ce sta la cartella");
		printf("\n");
	}
	//else
		//cd_path(main);
}

void	ft_exit()
{
	exit(1);
}
