/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <mcoppola@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:05:37 by mcoppola            #+#    #+#             */
/*   Updated: 2024/02/09 18:55:56 by mcoppola           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


int	check_redir(t_attr *att)
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

int	redir(t_attr *att)
{
	create_file(att, att->split_array[att->y + 2], att->redir);
	if (att->i_redir == att->y + 1)
		dup2(att->red_fd, 1);
	close(att->red_fd);
	return (0);
}

int	create_file(t_attr *att, char *str, int redir)
{
	char	*name;

	name = ft_strtrim(str, " ");
	if (redir == 1)
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (att->red_fd < 0)
	{
		att->value = 1;
		ft_putstr_fd("cannot create the file", 2);
		return (1);
	}
	free(name);
	att->value = 0;
	return (0);
}
