/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecxeve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:20:37 by mcoppola            #+#    #+#             */
/*   Updated: 2024/02/20 11:51:08 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_ecxev(char *path, char **arg, char **env)
{
	if (access(path, X_OK))
		return (127);
	if (execve(path, arg, env) != 0)
	{
		ft_putstr_fd("execve failed\n", 2);
		return (126);
	}
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
	i = -1;
	while (att->paths[++i])
		path[i] = ft_strjoin(att->paths[i], tmp);
	free(tmp);
	i = -1;
	while (path[++i])
	{
		if (ft_ecxev(path[i], att->arr2, att->env) == 0)
		{
			free_arr(path);
			return (0);
		}
	}
	free_arr(path);
	return (127);
}

