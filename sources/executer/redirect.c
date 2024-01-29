/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/01/29 05:35:26 by deggio           ###   ########.fr       */
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
	while (att->i_redir > att->y || att->i_readfile > att->y)
	{
		reset_flags(att);
		next_step_sub(att);
		if (att->redir)
			redir(att);
		if (att->heredoc)
			heredoc(att);
		if (att->read_from_file && att->y + 1 == att->i_readfile)
			read_from_file(att);
		att->y += 2;
	}
	if (att->write_to_pipe && att->read_from_pipe)
		att->pipe_index++;
	if (att->write_to_pipe)
		write_to_pipe(att);
	att->y = y;
	return (0);
}

// Da gestire:
//  FIXARE "code ignetion" nell'heredoc, e creazione di file chiamati come parti di codice per le redir
//  se bisogna solo creare il file vuoto
//  le redir nelle built in prima dell'exec, tanto devono solo creare file vuoti
//  controllari segnali per here doc
//	dare un occhiata alle pipe

// int	do_red(t_attr *att)
// {
// 	if (att->heredoc)
// 		heredoc(att);
// 	if (att->read_from_pipe)
// 		read_from_pipe(att);
// 	else if (att->read_from_file)
// 		read_from_file(att);
// 	if (att->redir)
// 		redir(att);
// 	if (att->only_create)
// 		create_file(att);
// 	if (att->write_to_pipe && att->read_from_pipe)
// 		att->pipe_index++;
// 	if (att->write_to_pipe)
// 		write_to_pipe(att);
// 	return (0);
// }

// int	do_red(t_attr *att)
// {
// 	// printf("only create: %d | read from pipe: %d | read from file: %d | heredoc: %d | write to pipe: %d | redir: %d\n", att->only_create, att->read_from_pipe, att->read_from_file, att->heredoc, att->write_to_pipe, att->redir);
// 	// printf("pipe index: %d | i redir: %d | i readfile: %d\n", att->pipe_index, att->i_redir, att->i_readfile);
// 	if (att->only_create)
// 		create_file(att);
// 	if (att->read_from_pipe && att->y > att->i_readfile)
// 		read_from_pipe(att);
// 	// else if (att->read_from_file)
// 	// 	read_from_file(att);
// 	// if (att->heredoc)
// 	// 	heredoc(att);
// 	if (att->y < att->i_redir)
// 		redir(att);
// 	if (att->y < att->i_readfile)
// 		read_from_file(att);
// 	if (att->write_to_pipe && att->read_from_pipe)
// 		att->pipe_index++;
// 	if (att->write_to_pipe)
// 		write_to_pipe(att);
// 	// if (att->redir)
// 	// 	redir(att);
// 	return (0);	
// }
