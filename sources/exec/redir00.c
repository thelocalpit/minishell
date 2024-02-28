/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:36:44 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 15:31:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Creates a file with the specified name and opens it for writing.
 *
 * @param att   A pointer to the t_attr structure.
 * @param str   The name of the file to be created.
 * @param redir The type of redirection (1 for truncation, 0 for appending).
 * @return      0 if the file is successfully created and opened, 1 otherwise.
 */
int	create_file(t_attr *att, char *str, int redir)
{
	char	*name;

	name = ft_strtrim(str, " ");
	if (redir == 1)
	{
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	}
	else
	{
		att->red_fd = open(name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	if (att->red_fd < 0)
	{
		att->value = 1;
		return (ft_putstr_fd("cannot create the file", 2), 1);
	}
	att->value = 0;
	return (free(name), 0);
}

/**
 * @brief Redirects input/output based on the given attributes.
 *
 * This function creates a file with the specified name and redirection mode,
 * and redirects the input/output accordingly. If the redirection is for
 * output, it duplicates the file descriptor to standard output. Finally, it
 * closes the file descriptor.
 *
 * @param att The attributes containing the necessary information for
 * redirection.
 */
void	redir(t_attr *att)
{
	create_file(att, att->split_array[att->y + 2], att->redir);
	if (att->i_redir == att->y + 1)
	{
		dup2(att->red_fd, 1);
	}
	close(att->red_fd);
}

/**
 * @brief Checks and handles redirections in the given attribute structure.
 *
 * This function iterates over the redirections in the attribute structure
 * and performs the necessary actions for each redirection. It resets flags,
 * moves to the next step, and calls the redir() function if a redirection is
 * found.
 *
 * @param att The attribute structure containing the redirection information.
 */
void	check_redirections(t_attr *att)
{
	while (att->i_redir > att->y)
	{
		att->redir = 0;
		att->read_files = 0;
		att->heredoc = 0;
		sub_next_step(att);
		if (att->redir)
		{
			redir(att);
		}
		att->y += 2;
	}
}
