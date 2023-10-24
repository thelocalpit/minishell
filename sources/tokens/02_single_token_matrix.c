/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_single_token_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:26 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/24 17:36:38 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


//forse c'è da gestire il dollar sign per le doubleqoutes

/* void ft_get_arg(char *s, t_attr *att)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s[i] == '"')
	{
		i++;
		if (s[i] == '"')
			return ;
		while (s[i] != '"')
		{
			if (s[i] == '\\' && s[i + 1] == '"')
				i++;
			att->matrix_single_cmd[att->count][j++] = s[i++];
		}
	}
	else if (s[i] == '\'')
	{
		i++;
		if (s[i + 1] == '\'')
			return ;
		while (s[i] != '\'')
				att->matrix_single_cmd[att->count][j++] = s[i++];
	}
	else
	{
		while (s[i] == ' ' || s[i])
			att->matrix_single_cmd[att->count][j++] = s[i++];
	}
}

void check_first_cmd(char *s, t_attr *att)
{
	int i;

	i = 0;
	if (s[i] == '"')
	{
		i++;
		if (s[i] == '"')
			return ;
		while (s[i] != '"')
		{
			if (s[i] == '\\' && s[i + 1] == '"')
				i++;
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				att->cmd_arr[att->y][att->x++] = s[i++];
			else
				return ;
		}
		att->flag_cmd_valid = 1;
	}
	else if (s[i] == '\'')
	{
		i++;
		if (s[i + 1] == '\'')
			return ;
		while (s[i] != '\'')
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				att->matrix_single_cmd[att->count][j++] = s[i++];
			else
				return ;
		}
		att->x = i;
	}
	else
	{
		while (s[i] != ' ' || s[i])
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
				att->matrix_single_cmd[att->count][j++] = s[i++];
			else
				return ;
		}
		att->x = i;
	}
} */


void	get_cmd_matrix(char *s, t_attr *att)
{
	if (!s)
		return ;
	ft_count_words(s, att);
	// check_first_cmd(s, att);
}