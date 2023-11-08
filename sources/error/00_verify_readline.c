/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_verify_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:43:57 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/08 15:11:00 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int count_quotes(char *s)
{
	int i;
	int count_quotes;

	count_quotes = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			count_quotes++;
		i++;
	}
	if (count_quotes % 2 != 0)
		return (1);
	i = 0;
	count_quotes = 0;
	while (s[i])
	{
		if (s[i] == '\\' && s[i + 1] == '"')
			i += 2;
		if (s[i] == '"')
			count_quotes++;
		i++;
	}
	if (count_quotes % 2 != 0)
		return (1);
	return (0);
}

int	verify_readline(char *s)
{
	if (count_quotes(s))
	{
		printf(ERROR_UNCLOSED);
		return (1);
	}
	return (0);
}

/* int check_cmd_quotes(char *cmd, char *s, t_attr *att)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			printf(ERROR_CMD);
			free_arr2(att->arr2, att);
			free_arr(att->split_arr);
			free(s);
			return (1);
		}
		i++;
	}
	return (0);
} */
/* 
void check_readline_pipe_redi(char *word, char *s, t_attr *att)
{
	if (ft_strncmp(att->split_arr[att->nb_tokens - 1], "|", 1)
		|| ft_strncmp(att->split_arr[att->nb_tokens - 1], ">", 1)
		|| ft_strncmp(att->split_arr[att->nb_tokens - 1], "<", 1)
		|| ft_strncmp(att->split_arr[att->nb_tokens - 1], ">>", 2)
		|| ft_strncmp(att->split_arr[att->nb_tokens - 1], "<<", 2))
	{
		printf(ERROR_PIPE);
		free_arr(att->split_arr);
		free(s);
	}
} */
