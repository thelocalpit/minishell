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

/**
 * @brief Execute the command with the given path and arguments and environment variables
 *
 * @param path the path of the command to execute
 * @param arg the arguments of the command to execute
 * @param env the environment of the command to execute
 * @return int the error code of the command
*/
int	ft_ecxev(char *path, char **arg, char **env)
{
	if (access(path, X_OK))
	{
		return (127);
	}
	else if (execve(path, arg, env) != 0)
	{
		ft_putstr_fd("Execve Failed\n", 2);
		return (126);
	}
	return (0);
}

/**
 * @brief
 *
 * @param att the global structure of the program
 * @return int the error code of the command executed
*/
int	bin_executer(t_attr *att)
{
	char	**path;
	char	*temp;
	int		i;

	temp = ft_strjoin("/", att->array2[0]);
	path = malloc(sizeof(char *) * (matrix_len(att->paths) + 1));
	path[matrix_len(att->paths)] = NULL;
	i = -1;
	while (att->paths[++i])
		path[i] = ft_strjoin(att->paths[i], temp);
	free(temp);
	i = -1;
	while (path[++i])
	{
		if (ft_ecxev(path[i], att->array2, att->env) == 0)
		{
			free_arr(path);
			return (0);
		}
	}
	free_arr(path);
	return (127);
}

