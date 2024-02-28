/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecxeve00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:36:13 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 14:47:12 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Execute the command with the given path and arguments and
 * environment variables
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
		return (ft_putstr_fd("Execve Failed\n", 2), 126);
	return (0);
}

/**
 * @brief
 *
 * @param att the global structure of the program
 * @return int the error code of the command executed
*/
int	binary_executer(t_attr *att)
{
	char	**paths;
	char	*temp;
	int		c;

	temp = ft_strjoin("/", att->array2[0]);
	paths = malloc(sizeof(char *) * (matrix_len(att->paths) + 1));
	paths[matrix_len(att->paths)] = NULL;
	c = -1;
	while (att->paths[++c])
		paths[c] = ft_strjoin(att->paths[c], temp);
	free(temp);
	c = -1;
	while (paths[++c])
	{
		if (ft_ecxev(paths[c], att->array2, att->env) == 0)
			return (free_matrix(paths), 0);
	}
	return (free_matrix(paths), 127);
}
