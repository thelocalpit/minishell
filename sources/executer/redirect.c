/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/01/08 19:46:02 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int heredoc(t_attr *att)
{
	char	*eof;
	char	*input;

	eof = ft_strdup(att->split_arr[att->y + 2]);
	while (1)
	{
		input = readline(RED_BOLD "> " RESET);
		if (ft_strcmp(input, eof) == 0)
		{
			free(input);
			break ;
		}
	}
	free(eof);
	return (0);
}

int do_red(t_attr *att)
{
	if (att->heredoc)
		heredoc(att);
	return (0);
}
