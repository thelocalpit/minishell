/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:55:31 by alesac            #+#    #+#             */
/*   Updated: 2024/01/08 16:57:40 by deggio           ###   ########.fr       */
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
		perror("fork failed");
		return (1);
	}
	else if (child_pid == 0)
	{
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
	char	*name;

	tmp = *local_var;
	name = get_var_name(str);
	if (!str[ft_strlen(name) + 1])
		free(str);
	if (!str)
		str = ft_strjoin(name, "=\"\"");
	free(name);
	while (tmp)
	{
		if (!ft_strcmp(get_var_name(str), get_var_name(tmp->content)))
		{
			free(tmp->content);
			tmp->content = ft_strdup(str);
			return (0);
		}
		tmp = tmp->next;
	}
	tmp = ft_lstnew(ft_strdup(str));
	if (!tmp)
		perror("malloc");
	ft_lstadd_back(local_var, tmp);
	return (0);
}
