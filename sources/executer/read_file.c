/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/01/29 15:32:09 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	red_input(t_attr *att, char *path)
{
	att->red_fd = open(path, O_RDONLY);
	if (att->red_fd < 0)
		return (1);
	dup2(att->red_fd, 0);
	close(att->red_fd);
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
	free_arr(eof);
	if (att->i_readfile != att->y + 1)
		return (0);
	att->red_fd = open(".heredoc", O_RDONLY);
	dup2(att->red_fd, 0);
	if (red_input(att, ".heredoc") || att->red_fd < 0)
		printf("heredoc error\n");
	close(att->red_fd);
	unlink(".heredoc");
	return (0);
}

int	heredoc_read(t_attr *att, char *eof)
{
	char	*input;

	att->red_fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (att->red_fd < 0)
	{
		printf("heredoc error\n");
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
	close(att->red_fd);
	return (0);
}

int	read_from_file(t_attr *att)
{
	char	*file_path;
	char	*current_path;
	char	*tmp;

	file_path = ft_strtrim(att->split_arr[att->y + 2], " ");
	if (file_path[0] != '/')
	{
		current_path = malloc(sizeof(char) * PATH_MAX);
		getcwd(current_path, PATH_MAX);
		tmp = ft_strjoin(current_path, "/");
		free(current_path);
		current_path = ft_strjoin(tmp, file_path);
		free(tmp);
		free(file_path);
		file_path = ft_strdup(current_path);
		free(current_path);
	}
	if (red_input(att, file_path))
	{
		printf("minishell: %s: No such file or directory\n",
			att->split_arr[att->y + 2]);
		att->skip = 1;
	}
	free(file_path);
	return (0);
}
