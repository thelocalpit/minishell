/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:36:38 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 15:31:50 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Redirects the input from a file to the standard input.
 *
 * This function opens the specified file in read-only mode and redirects its
 *  contents to the standard input. It then closes the file descriptor and
 * sets the value of `att->value` to 0.
 *
 * @param att The attribute structure containing file descriptors and other
 * information.
 * @param path The path of the file to be read.
 * @return Returns 0 if the file is successfully opened and the input is
 * redirected, otherwise returns 1.
 */
int	red_input(t_attr *att, char *path)
{
	att->red_fd = open(path, O_RDONLY);
	if (att->red_fd < 0)
	{
		return (1);
	}
	dup2(att->red_fd, 0);
	close(att->red_fd);
	att->value = 0;
	return (0);
}

/**
 * @brief Reads input from the user until a specified delimiter is encountered.
 * The input is written to a file named ".heredoc".
 *
 * @param att   A pointer to the attribute structure.
 * @param eof   The end-of-file delimiter.
 * @return      0 on success, 1 on error.
 */
int	heredoc_read(t_attr *att, char *eof)
{
	char	*input;

	handler_signal_heredoc();
	att->red_fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (att->red_fd < 0)
		return (ft_putstr_fd("heredoc error\n", 2), 1);
	while (1)
	{
		input = readline(RED_BOLD "> " RESET);
		if (input == NULL || !ft_strcmp(input, eof))
		{
			if (input)
				free(input);
			else
				printf("bash: warning: here-document delimited by\
					end-of-file (wanted `%s')\n", eof);
			break ;
		}
		else
		{
			write(att->red_fd, input, ft_strlen(input));
			write(att->red_fd, "\n", 1);
			free(input);
		}
	}
	return (0);
}

/**
 * @brief the heredoc functionality.
 *
 * @param att The attribute structure.
 * @return 0 if successful, 1 otherwise.
 */
int	heredoc(t_attr *att)
{
	char	**eof;

	eof = ft_split(att->split_array[att->y + 2], ' ');
	if (heredoc_read(att, eof[0]))
		return (free_matrix(eof), 1);
	close(att->red_fd);
	free_matrix(eof);
	if (att->i_readfile != att->y + 1)
	{
		return (0);
	}
	att->red_fd = open(".heredoc", O_RDONLY);
	dup2(att->red_fd, 0);
	if (red_input(att, ".heredoc") || att->red_fd < 0)
	{
		ft_putstr_fd("heredoc error\n", 2);
		return (unlink(".heredoc"), 1);
	}
	close(att->red_fd);
	return (unlink(".heredoc"), 0);
}

/**
 * @brief Reads files and performs necessary operations.
 *
 * This function reads files specified in the `att` structure and performs
 * the necessary operations based on the file content. It trims the file path,
 * checks if the file is a valid input redirection, and handles any errors
 * that occur during the process.
 *
 * @param att The attribute structure containing necessary information.
 * @return 0 on success, or an error code on failure.
 */
int	files_reader(t_attr *att)
{
	char	*file_path;

	file_path = ft_strtrim(att->split_array[att->y + 2], " ");
	if (red_input(att, file_path))
	{
		reader_file_error(att, file_path);
	}
	return (free(file_path), 0);
}

/**
 * @brief Checks and reads files based on the given attributes.
 *
 * @param att The attribute structure containing necessary information.
 */
void	check_read_file(t_attr *att)
{
	while (att->i_readfile > att->y)
	{
		reset_flag2(att);
		sub_next_step(att);
		if (att->heredoc)
		{
			att->value = heredoc(att);
		}
		if (att->read_files && ((att->y + 1) == att->i_readfile))
		{
			files_reader(att);
		}
		att->y = att->y + 2;
	}
}
