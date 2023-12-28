/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:55:31 by alesac            #+#    #+#             */
/*   Updated: 2023/12/28 01:51:28 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

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
	char	*option;
	int		status;

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
	else
		waitpid(child_pid, &status, 0);
	return (0);
}

void	ft_cd(char **args)
{
	char	*tmp;

	if (args[1] == NULL)
	{
		tmp = getenv("HOME");
		chdir(tmp);
	}
	else if (chdir(args[1]) == -1)
	{
		printf(RED"cd : diocane non ce sta la cartella");
		printf("\n");
	}
}

int	add_var(char *str, t_list **local_var)
{
	t_list	*tmp;

	//printf("1 add_var PORCO DIOOOOOOOOOO\n");
	tmp = *local_var;
	//printf("2 add_var PORCO DIOOOOOOOOOO\n");
	if (tmp)
	{
	//printf("3 DENTRO IF               add_var PORCO DIOOOOOOOOOO\n");
		while (tmp->next)
		{
			//printf("4 DENTRO WHILE               add_var PORCO DIOOOOOOOOOO\n");
			if (!ft_strcmp(get_var_name(str), get_var_name(tmp->content)))
			{
				tmp->content = ft_strdup(str);
				return (0);
			}
			tmp = tmp->next;
		}
	}
	//printf("5  dopo if  PORCO DIOOOOOOOOOO\n");
	tmp = ft_lstnew(str);
	//printf("6  dopo tmp  PORCO DIOOOOOOOOOO\n");
	if (!tmp)
		perror("malloc");
	ft_lstadd_back(local_var, tmp);
	//printf("7  dopo addback  PORCO DIOOOOOOOOOO\n");
	//printvar(local_var);
	return (0);
}
