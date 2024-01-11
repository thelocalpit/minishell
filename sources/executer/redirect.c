/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/01/11 06:02:25 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	red_input(t_attr *att, char *path)
{
	att->red_fd = open(path, O_RDONLY);
	if (att->red_fd < 0)
	{
		perror("cannot open file");
		return (-1);
	}
	dup2(att->red_fd, 0);
	close(att->red_fd);
	return (0);
}

int heredoc(t_attr *att)
{
	char	*eof;
	char	*input;
	int		fd;

	eof = ft_strdup(att->split_arr[att->y + 2]);
	fd = open("objects/heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while (1)
	{
		input = readline(RED_BOLD "> " RESET);
		if (ft_strcmp(input, eof) == 0)
		{
			free(input);
			break ;
		}
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
	}
	free(eof);
	close(fd);
	red_input(att, "objects/heredoc");
	unlink("objects/heredoc");
	return (0);
}

int	read_from_file(t_attr *att)
{
	char	*file_path;

	file_path = ft_strtrim(att->split_arr[att->y + 2], " ");
	red_input(att, file_path);
	att->read_from_file = 0;
	free(file_path);
	return (0);
}

int	do_red(t_attr *att)
{
	if (att->heredoc)
		heredoc(att);
	if (att->read_from_file)
		read_from_file(att);
	return (0);
}
