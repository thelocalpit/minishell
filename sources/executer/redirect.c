/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/01/11 06:50:27 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_redir(t_attr *att)
{
	char	*name;

	while (att->split_arr[att->y + 3]
		&& (!ft_strcmp(att->split_arr[att->y + 3], ">")
			|| !ft_strcmp(att->split_arr[att->y + 3], ">>")))
	{
		att->y = att->y + 2;
		name = ft_strtrim(att->split_arr[att->y + 2], " ");
		att->red_fd = open(name, O_CREAT, 0644);
		if (att->red_fd < 0)
		{
			perror("cannot create the file");
			return (-1);
		}
		close(att->red_fd);
	}
	return (0);
}

int	redir(t_attr *att)
{
	char	*name;

	check_redir(att);
	name = ft_strtrim(att->split_arr[att->y + 2], " ");
	printf("name: %s\n", name);
	if (att->redir == 1)
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (att->redir == 2)
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	printf("red_fd: %d\n", att->red_fd);
	printf("att->redir: %d\n", att->redir);
	if (att->red_fd < 0)
	{
		perror("cannot create the file");
		return (-1);
	}
	printf(" DOPO if \n");
	dup2(att->red_fd, 1);
	printf(" DOPO dup2 \n");
	close(att->red_fd);
	printf(" DOPO CLOSE \n");
	free(name);
	return (0);
}

int	do_red(t_attr *att)
{
	if (att->heredoc)
		heredoc(att);
	if (att->read_from_file)
		read_from_file(att);
	if (att->redir)
		redir(att);
	return (0);
}
