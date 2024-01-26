/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/01/26 04:17:08 by deggio           ###   ########.fr       */
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
		att->red_fd = open(name, O_CREAT, 0644);
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
	if (att->redir == 1)
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (att->redir == 2)
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
	if (att->read_from_file)
		read_from_file(att);
	if (att->redir)
		redir(att);
	if (att->read_from_pipe)
		read_from_pipe(att);
	if (att->write_to_pipe && att->read_from_pipe)
		att->pipe_index++;
	if (att->write_to_pipe)
		write_to_pipe(att);
	if (att->write_to_pipe && att->read_from_pipe && att->pipe_index <= att->nb_pipes)
		close_pipeline(att);
	return (0);
}
