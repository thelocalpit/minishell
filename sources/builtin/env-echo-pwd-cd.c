/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env-echo-pwd-cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:32:16 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/22 13:32:19 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_attr *strc)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		ft_putstr_fd("getcwd error!", 2);
		return (1);
	}
	if (strc->redir || strc->write_pipe)
		printf("%s\n", cwd);
	else
		printf(YELLOW_BOLD "%s\n", cwd);
	return (0);
}

int	ft_enviorment(t_attr *strc)
{
	t_list	*str;

	str = strc->env_list;
	while (str)
	{
		printf("%s\n", (char *)str->content);
		str = str->next;
	}
	return (0);
}

int	ft_echo(char **str)
{
	int	nl;
	int	j;

	j = 1;
	if (str[1] && !strcmp(str[1], "-n"))
	{
		nl = 1;
		j++;
	}
	else
		nl = 0;
	while (str[j])
	{
		printf("%s ", str[j]);
		j++;
	}
	if (nl == 0)
	{
		printf("\n");
	}
	return (0);
}

int	ft_cd(char **str)
{
	char	*env;

	if (str[1] == NULL || str[1][0] == '~')
	{
		env = getenv("HOME");
		chdir(env);
	}
	else if (chdir(str[1]) == -1)
	{
		printf(RED "cd: no such file or directory: %s", str[1]);
		printf("\n");
		return (1);
	}
	return (0);
}
