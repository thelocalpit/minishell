/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/01/26 06:26:26 by deggio           ###   ########.fr       */
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
		name = ft_strtrim(att->split_arr[att->y], " ");
		printf("name: %s\n", name);
		if (!ft_strcmp(att->split_arr[att->y - 1], ">"))
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
	}
	return (0);
}

int	redir(t_attr *att)
{
	char	*name;
	int		y;

	y = att->y;
	check_redir(att);
	name = ft_strtrim(att->split_arr[att->y + 2], " ");
	if (!ft_strcmp(att->split_arr[att->y + 1], ">"))
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
	att->y = y;
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


// Da gestire:
//  FIXARE "code ignetion" nell'heredoc, e creazione di file chiamati come parti di codice per le redir
//  se bisogna solo creare il file vuoto
//  le redir nelle built in prima dell'exec, tanto devono solo creare file vuoti
//  controllari segnali per here doc
//	dare un occhiata alle pipe

int	do_red(t_attr *att)
{
	if (att->heredoc)
		heredoc(att);
	if (att->read_from_pipe)
		read_from_pipe(att);
	else if (att->read_from_file)
		read_from_file(att);
	if (att->redir)
		redir(att);
	if (att->only_create)
		create_file(att);
	if (att->write_to_pipe && att->read_from_pipe)
		att->pipe_index++;
	if (att->write_to_pipe)
		write_to_pipe(att);
	// if (att->write_to_pipe && att->read_from_pipe
	// 	&& att->pipe_index <= att->nb_pipes)
	// 	close_pipeline(att);
	return (0);
}
