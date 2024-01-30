/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:05:37 by deggio            #+#    #+#             */
/*   Updated: 2024/01/30 16:05:52 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_redir(t_attr *att)
{
	char	*name;

	if (att->y + 1 < att->i_redir)
	{
		name = ft_strtrim(att->split_arr[att->y + 2], " ");
		if (att->redir == 1)
			att->red_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		else
			att->red_fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (att->red_fd < 0)
		{
			perror("cannot create the file");
			return (-1);
		}
		close(att->red_fd);
		free(name);
		return (1);
	}
	return (0);
}

int	redir(t_attr *att)
{
	char	*name;

	if (check_redir(att))
		return (0);
	name = ft_strtrim(att->split_arr[att->y + 2], " ");
	if (att->redir == 1)
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (att->red_fd < 0)
	{
		perror("cannot create the file");
		return (-1);
	}
	dup2(att->red_fd, 1);
	close(att->red_fd);
	free(name);
	return (0);
}

int	create_file(t_attr *att)
{
	char	*name;

	name = ft_strtrim(att->split_arr[att->y + 1], " ");
	if (att->only_create == 1)
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (att->red_fd < 0)
	{
		perror("cannot create the file");
		return (-1);
	}
	close(att->red_fd);
	free(name);
	return (0);
}
