/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env-echo-pwd-cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:32:16 by asacchin          #+#    #+#             */
/*   Updated: 2024/03/07 17:21:35 by mcoppola         ###   ########.fr       */
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

void	change_current_dir(t_attr *strc, char *content)
{
	t_list	*buf;

	buf = strc->env_list;
	while (buf)
	{
		if (!ft_strncmp("PWD=", buf->content, 4))
		{
			free(buf->content);
			buf->content = ft_strjoin("PWD=", content);
			break ;
		}
		buf = buf->next;
	}
}

int	ft_cd(char **str, t_attr *strc)
{
	char	*env;
	char	cwd[1000];

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
	change_current_dir(strc, getcwd(cwd, sizeof(cwd)));
	return (0);
}
