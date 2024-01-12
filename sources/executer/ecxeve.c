/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecxeve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:20:37 by deggio            #+#    #+#             */
/*   Updated: 2024/01/12 02:14:57 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_ecxev(char *path, char **arg, char **env)
{
	if (access(path, X_OK))
		return (1);
	if (execve(path, arg, env) != 0)
	{
		perror("execve failed");
		return (1);
	}
	return (0);
}

int	absolute_exec(t_attr *att)
{
	ft_ecxev(att->arr2[0], att->arr2, att->env);
	return (0);
}

int	binary_exec(t_attr *att)
{
	char	*tmp;
	char	*path;
	char	*current_path;

	tmp = ft_strtrim(att->arr2[0], ".");
	current_path = malloc(sizeof(char) * PATH_MAX);
	getcwd(current_path, PATH_MAX);
	path = ft_strjoin(current_path, tmp);
	ft_ecxev(path, att->arr2, att->env);
	free(path);
	free(tmp);
	free(current_path);
	return (0);
}

int	bin_exec(t_attr *att)
{
	char	**path;
	char	*tmp;
	int		i;

	tmp = ft_strjoin("/", att->arr2[0]);
	path = malloc(sizeof(char *) * (matrix_len(att->paths) + 1));
	path[matrix_len(att->paths)] = NULL;
	i = 0;
	while (att->paths[i])
	{
		path[i] = ft_strjoin(att->paths[i], tmp);
		i++;
	}
	free(tmp);
	i = 0;
	while (path[i])
	{
		if (ft_ecxev(path[i], att->arr2, att->env) == 0)
		{
			free_arr(path);
			return (0);
		}
		i++;
	}
	free_arr(path);
	return (0);
}
