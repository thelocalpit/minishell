/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/01/11 04:40:28 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	att->red_fd = open("objects/heredoc", O_RDONLY);
	dup2(att->red_fd, 0);
	close(att->red_fd);
	unlink("objects/heredoc");
	return (0);
}

int do_red(t_attr *att)
{
	if (att->heredoc)
		heredoc(att);
	return (0);
}
