/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/01/29 17:26:56 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_redir(t_attr *att)
{
	char	*name;

	if (att->y + 1 < att->i_redir)
	{
		name = ft_strtrim(att->split_arr[att->y + 2], " ");
		//printf("name: %s\n", name);
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

int	do_red(t_attr *att)
{
	int	y;

	y = att->y;
	if (att->only_create)  // secondo me va tolto e inizializato att->y = -1
		create_file(att);
	if (att->read_from_pipe)
		read_from_pipe(att);
	while (att->i_readfile > att->y)
	{
		reset_flags2(att);
		next_step_sub(att);
		if (att->heredoc)
			heredoc(att);
		if (att->read_from_file && att->y + 1 == att->i_readfile)
			read_from_file(att);
		att->y += 2;
	}
	att->y = y;
	while (att->i_redir > att->y)
	{
		reset_flags2(att);
		next_step_sub(att);
		if (att->redir)
			redir(att);
		att->y += 2;
	}
	if (att->i_redir > att->i_readfile)
		att->y = att->i_redir + 1;
	else if (att->i_readfile != 0)
		att->y = att->i_readfile + 1;
	if (att->split_arr[att->y] && att->split_arr[att->y + 1])
		next_step_sub(att);
	if (att->write_to_pipe && att->read_from_pipe)
		att->pipe_index++;
	if (att->write_to_pipe)
		write_to_pipe(att);
	att->y = y;
	return (0);
}

void	reset_flags2(t_attr *att)
{
	att->redir = 0;
	att->read_from_file = 0;
	att->heredoc = 0;
	att->create_file = 0;
	att->only_create = 0;
}
