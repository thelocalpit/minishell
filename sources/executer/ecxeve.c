/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecxeve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:20:37 by deggio            #+#    #+#             */
/*   Updated: 2024/01/11 20:49:32 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_ecxev(char *path, char **arg, char **env)
{
	if (!access(path, X_OK))
		return (0);
	if (execve(path, arg, env) == -1)
	{
		perror("execve failed");
		return (1);
	}
	return (0);
}

int	absolute_exec(t_attr *att)
{
	ft_ecxev(att->arr2[0], att->arr2, NULL);
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
	//printf("path = %s\n tmp = %s\n current_path = %s\n", path, tmp, current_path);
	ft_ecxev(path, att->arr2, NULL);
	free(path);
	free(tmp);
	free(current_path);
	return (0);
}

int    relative_exec(t_attr *att)
{
	int		i;
	i = att->y;
	printf("relative_exec %d\n", i); // solo per testing non guardate
	return (0);
}