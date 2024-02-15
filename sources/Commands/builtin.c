/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:55:31 by alesac            #+#    #+#             */
/*   Updated: 2024/02/13 16:48:54 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo(char **args)
{
	int	i;
	int	newline;

	i = 1;
	if (args[1] && !strcmp(args[1], "-n"))
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
	if (!newline)
	{
		printf("\n");
	}
	return (0);
}

int	pwd(t_attr *att)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		ft_putstr_fd("getcwd error!", 2);
		return (1);
	}
	if (att->redir || att->write_to_pipe)
		printf("%s\n", cwd);
	else
		printf(YELLOW_BOLD "%s\n", cwd);
	return (0);
}

int	envi(t_attr *att)
{
	t_list	*env;

	env = att->env_list;
	while (env)
	{
		printf("%s\n", (char *)env->content);
		env = env->next;
	}
	return (0);
}

int	ls_l(char **env, int j)
{
	pid_t	child_pid = fork();
	char	*option;
	int		status;

	if (j == 1)
		option = "-l";
	else if (j == 0)
		option = "-h";
	if (child_pid == -1)
	{
		ft_putstr_fd("fork failed", 2);
		return (1);
	}
	else if (child_pid == 0)
	{
		// Questo è il processo figlio
		char *ls_args[] = {"/bin/ls", option, NULL};
		execve("/bin/ls", ls_args, env);
		ft_putstr_fd("execve failed", 2);
		exit(1);
	}
	else
		waitpid(child_pid, &status, 0);
	return (0);
}

int	ft_cd(char **args)
{
	char	*tmp;

	if (args[1] == NULL)
	{
		tmp = getenv("HOME");
		chdir(tmp);
	}
	else if (chdir(args[1]) == -1)
	{
		printf(RED "cd: no such file or directory: %s", args[1]);
		printf("\n");
		return (1);
	}
	return (0);
}
