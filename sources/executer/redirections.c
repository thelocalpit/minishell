/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by deggio            #+#    #+#             */
/*   Updated: 2024/02/04 06:35:09 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	do_red(t_attr *att)
{
	int	y;

	y = att->y;
	if (att->read_from_pipe)
		read_from_pipe(att);
	check_read_file(att);
	att->y = y;
	check_redir_flag(att);
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

int	check_read_file(t_attr *att)
{
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
	return (0);
}

int	check_redir_flag(t_attr *att)
{
	while (att->i_redir > att->y)
	{
		reset_flags2(att);
		next_step_sub(att);
		if (att->redir)
			redir(att);
		att->y += 2;
	}
	return (0);
}

void	reset_flags2(t_attr *att)
{
	att->redir = 0;
	att->read_from_file = 0;
	att->heredoc = 0;
	att->create_file = 0;
}
