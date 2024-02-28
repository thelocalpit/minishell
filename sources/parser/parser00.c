/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:09:04 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 15:55:44 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Redirects the input/output based on the given command attributes.
 *
 * This function searches for redirection symbols in the split_array of the
 * given attributes and updates the corresponding index variables accordingly.
 * The index variables att->i_redir and att->i_readfile are updated to the
 * index of the redirection symbol in the split_array.
 *
 * @param att The command attributes containing the split_array.
 */
void	redirect_index(t_attr *att)
{
	int	temp;

	temp = att->y + 1;
	while (att->split_array[temp])
	{
		if (!ft_strcmp(att->split_array[temp], ">>")
			|| !ft_strcmp(att->split_array[temp], ">"))
			att->i_redir = temp;
		else if (!ft_strcmp(att->split_array[temp], "<<")
			|| !ft_strcmp(att->split_array[temp], "<"))
			att->i_readfile = temp;
		if (!ft_strcmp(att->split_array[temp], "|"))
			break ;
		temp = temp + 2;
	}
}

/**
 * @brief Resets the flags in the given attribute structure.
 *
 * This function sets all the flags in the t_attr structure to 0.
 * The flags indicate various conditions or states in the parsing process.
 *
 * @param att The attribute structure to reset the flags for.
 */
void	flags_reset(t_attr *att)
{
	att->read_files = 0;
	att->redir = 0;
	att->write_pipe = 0;
	att->heredoc = 0;
	att->first_redir = 0;
	att->read_pipe = 0;
	att->skip = 0;
}

/**
 * @brief Determines the next step based on the current token in the split
 * array.
 *
 * This function checks the next token in the split array and sets the
 * appropriate flags in the t_attr structure based on the token's value. If the
 * next token is "|", the write_pipe flag is set to 1. If the next token is
 * ">>", the redir flag is set to 2. If the next token is ">", the redir flag
 * is set to 1. If the next token is "<<", the heredoc flag is set to 1. If the
 * next token is "<", the read_files flag is set to 1.
 *
 * @param att The t_attr structure containing the split array and flags.
 */
void	sub_next_step(t_attr *att)
{
	if (!ft_strcmp(att->split_array[att->y + 1], "|"))
		att->write_pipe = 1;
	else if (!ft_strcmp(att->split_array[att->y + 1], ">>"))
		att->redir = 2;
	else if (!ft_strcmp(att->split_array[att->y + 1], ">"))
		att->redir = 1;
	else if (!ft_strcmp(att->split_array[att->y + 1], "<<"))
		att->heredoc = 1;
	else if (!ft_strcmp(att->split_array[att->y + 1], "<"))
		att->read_files = 1;
}

/**
 * @brief Checks the previous token in the split array and sets the appropriate
 * flags in the attribute structure.
 *
 * This function checks the previous token in the split array and sets the
 * read_pipe flag to 1 if the token is "|".
 * It also sets the skip flag to 1 if the token is ">>", ">", "<", or "<<".
 *
 * @param att The attribute structure containing the split array and flags.
 */
void	sub_next_step2(t_attr *att)
{
	if (!ft_strcmp(att->split_array[att->y - 1], "|"))
	{
		att->read_pipe = 1;
	}
	if (!ft_strcmp(att->split_array[att->y - 1], ">>")
		|| !ft_strcmp(att->split_array[att->y - 1], ">")
		|| !ft_strcmp(att->split_array[att->y - 1], "<")
		|| !ft_strcmp(att->split_array[att->y - 1], "<<"))
	{
		att->skip = 1;
	}
}

/**
 * @brief Checks the next step in the parsing process.
 *
 * This function resets the flags in the attribute structure and checks the
 * next step based on the current split array element. If the current element
 * is "<", "<<", ">>", or ">", it performs the corresponding action based on
 * the value of att->y. If att->y is 2, it decrements att->y and calls
 * sub_next_step2(). If att->y is 0, it calls frist_redir(). If none of the
 * above conditions are met, it calls sub_next_step() and sub_next_step2()
 * based on the values of att->y. Finally, it calls redirect_index() to handle
 * redirection.
 *
 * @param att The attribute structure containing the necessary information for
 * parsing.
 * @return 0 indicating successful execution.
 */
int	check_next_step(t_attr *att)
{
	flags_reset(att);
	if ((att->y == 2 || att->y == 0) && (!ft_strcmp(att->split_array[0], "<")
			|| !ft_strcmp(att->split_array[0], "<<")
			|| !ft_strcmp(att->split_array[0], ">>")
			|| !ft_strcmp(att->split_array[0], ">")))
	{
		if (att->y == 2)
		{
			att->y--;
			sub_next_step2(att);
		}
		else if (att->y == 0)
		{
			frist_redir(att);
		}
	}
	else
	{
		if (att->split_array[att->y] && att->split_array[att->y + 1])
			sub_next_step(att);
		if (att->y > 1)
			sub_next_step2(att);
		redirect_index(att);
	}
	return (0);
}
