/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:23:19 by mcoppola            #+#    #+#             */
/*   Updated: 2024/02/09 07:47:40 by mcoppola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	do_red(t_attr *att)
{
	int	y;

	if (att->first_redir)
		att->y--;
	y = att->y;
	if (att->read_pipe)
		read_pipe(att);
	check_read_file(att);
	att->y = y;
	check_redir(att);
	if (att->i_redir > att->i_readfile)
		att->y = att->i_redir + 1;
	else if (att->i_readfile != 0)
		att->y = att->i_readfile + 1;
	if (att->split_array[att->y] && att->split_array[att->y + 1])
		next_step_sub(att);
	if (att->write_pipe && att->read_pipe)
		att->pipe_index_num++;
	if (att->write_pipe)
		write_pipe(att);
	att->y = y;
	if (att->first_redir)
		att->skip = 1;
	return (0);
}

void	reset_flags2(t_attr *att)
{
	att->redir = 0;
	att->read_files = 0;
	att->heredoc = 0;
}

int	frist_redir(t_attr *att)
{
	att->y--;
	next_step_sub(att);
	red_index(att);
	att->y++;
	att->first_redir = 1;
	return (0);
}
// int	frist_redirect(t_attr *att)
// {
// 	char	*eof;

// 	att->y--;
// 	next_step_sub(att);
// 	if (att->redirect)
// 		create_file(att, att->split_array[att->y + 2], att->redirect);
// 	if (att->heredoc)
// 	{
// 		eof = ft_strtrim(att->split_array[att->y + 2], " ");
// 		heredoc_read(att, eof);
// 		free(eof);
// 		unlink(".heredoc");
// 	}
// 	close(att->red_fd);
// 	reset_flags(att);
// 	att->y += 2;
// 	att->skip = 1;
// 	return (0);
// }
