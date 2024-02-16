/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/02/16 00:11:52 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_read_file(t_attr *att)
{
	while (att->i_readfile > att->y)
	{
		reset_flags2(att);
		next_step_sub(att);
		if (att->heredoc)
			att->g_value = heredoc(att);
		if (att->read_from_file && att->y + 1 == att->i_readfile)
			read_from_file(att);
		att->y += 2;
	}
	return (0);
}

int	red_input(t_attr *att, char *path)
{
	att->red_fd = open(path, O_RDONLY);
	if (att->red_fd < 0)
		return (1);
	dup2(att->red_fd, 0);
	close(att->red_fd);
	att->g_value = 0;
	return (0);
}

int	heredoc(t_attr *att)
{
	char	**eof;

	eof = ft_split(att->split_arr[att->y + 2], ' ');
	if (heredoc_read(att, eof[0]))
	{
		free_arr(eof);
		return (1);
	}
	close(att->red_fd);
	free_arr(eof);
	if (att->i_readfile != att->y + 1)
		return (0);
	att->red_fd = open(".heredoc", O_RDONLY);
	dup2(att->red_fd, 0);
	if (red_input(att, ".heredoc") || att->red_fd < 0)
	{
		ft_putstr_fd("heredoc error\n", 2);
		unlink(".heredoc");
		return (1);
	}
	close(att->red_fd);
	unlink(".heredoc");
	return (0);
}

int	heredoc_read(t_attr *att, char *eof)
{
	char	*input;

	signal_heredoc_handler();
	att->red_fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (att->red_fd < 0)
	{
		ft_putstr_fd("heredoc error\n", 2);
		return (1);
	}
	while (1)
	{
		input = readline(RED_BOLD "> " RESET);
		if (ft_strcmp(input, eof) == 0)
		{
			free(input);
			break ;
		}
		write(att->red_fd, input, ft_strlen(input));
		write(att->red_fd, "\n", 1);
		free(input);
	}
	return (0);
}

int	read_from_file(t_attr *att)
{
	char	*file_path;

	file_path = ft_strtrim(att->split_arr[att->y + 2], " ");
	if (red_input(att, file_path))
		read_file_error(att, file_path);
	free(file_path);
	return (0);
}
