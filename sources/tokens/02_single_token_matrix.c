/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_single_token_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:26 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/27 17:04:15 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


//forse c'è da gestire il dollar sign per le doubleqoutes

void check_args_cmd(char *s, t_attr *att)
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

int ft_strlen_custom(char *s, int flag)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	if (flag == 0)
	{
		while (s[i] || s[i] == ' ')
			i++;
	}
	if (flag == 1)
	{
		while (s[i] == '\'')
			i++;
	}
	if (flag == 2)
	{
		while (s[i] == '"')
			i++;
	}
	return (i);
}

void check_first_cmd(char *s, t_attr *att)
{
	int i;
	int len;
	int flag;

	i = 0;
	if (s[i] == '"')
	{
		i++;
		flag = 2;
		len = ft_strlen_custom(s, flag);
		if (s[i] == '"')
			return ;
		att->arr2[att->y2] = malloc(len + 1);
		if (!(att->arr2[att->y2]))
			return ;
		while (s[i] != '"')
		{
			if (s[i] == '\\' && s[i + 1] == '"')
				i++;
			att->arr2[att->y2][att->x2++] = s[i++];
		}
	}
	else if (s[i] == '\'')
	{
		i++;
		flag = 1;
		len = ft_strlen_custom(s, flag);
		if (s[i] == '\'')
			return ;
		att->arr2[att->y2] = malloc(len + 1);
		if (!(att->arr2[att->y2]))
			return ;
		while (s[i] != '\'')
			att->arr2[att->y2][att->x2++] = s[i++];
	}
	else
	{
		flag = 0;
		len = ft_strlen_custom(s, flag);
		att->arr2[att->y2] = malloc(len + 1);
		if (!(att->arr2[att->y2]))
			return ;
		while (s[i] != ' ' && s[i])
			att->arr2[att->y2][att->x2++] = s[i++];
	}
	att->arr2[att->y2][att->x2] = '\0';
}

void get_cmd_token(char *s, t_attr *att)
{
	
	check_first_cmd(s, att);
	check_args_cmd(s, att);
}

void create_matrix_cmd(char *s, t_attr *att)
{
	att->x2 = 0;
	att->y2 = 0;
	att->arr2 = malloc((att->count_words + 1) * sizeof(char *));
	att->arr2[att->count_words] = NULL;
	if (!att->arr2)
		return ;
	while (att->y2 < att->count_words)
	{
		while (*s == ' ')
			s++;
		get_cmd_token(s, att);
		if (att->arr2[att->y2] == 0 && att->y2 < att->count_words)
		{
			s = NULL;
			return ;
		}
		att->y2++;
	}
}
	/* This function is used for creating la matrice del (cmd + args) */
	void get_cmd_matrix(char *s, t_attr *att)
{
	if (!s)
		return ;
	ft_count_words(s, att);
	create_matrix_cmd(s, att);
}
