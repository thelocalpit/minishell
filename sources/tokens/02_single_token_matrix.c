/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_single_token_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:26 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/08 15:30:37 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_strlen_custom(char *s, int flag)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	if (flag == 0)
	{
		while (s[i] != ' ' && s[i])
			i++;
		// printf("sono dentro strlen\n");
	}
	if (flag == 1)
	{
		while (s[i] != '\'')
			i++;
	}
	if (flag == 2)
	{
		while (s[i] != '"')
			i++;
	}
	return (i);
}


char *ft_write_word(char *s, t_attr *att, int flag, int i)
{
	int len;

	len = ft_strlen_custom(s, flag);
	att->arr2[att->y2] = malloc(len + 1);
	if (!att->arr2[att->y2])
		return (NULL);
	if (flag == 2)
	{
		while (s[i] != '"')
		{
			if (s[i] == '\\' && s[i + 1] == '"')
				i++;
			att->arr2[att->y2][att->x2++] = s[i++];
		}
	}
	else if (flag == 1)
	{
		while (s[i] != '\'')
			att->arr2[att->y2][att->x2++] = s[i++];
	}
	else
	{
		while (s[i] != ' ' && s[i])
			att->arr2[att->y2][att->x2++] = s[i++];
	}
	att->arr2[att->y2][att->x2] = '\0';
	return (&s[++i]);
}

//forse c'è da gestire il dollar sign per le doubleqoutes

char *get_cmd_token(char *s, t_attr *att)
{
	int i;
	int flag;

	i = 0;
	if (s[i] == '"')
	{
		i++;
		if (s[i] == '"')
			return (NULL);
		flag = 2;
		return (ft_write_word(s, att, flag, i));
	}
	else if (s[i] == '\'')
	{
		i++;
		if (s[i] == '\'')
			return (NULL);
		flag = 1;
		return (ft_write_word(s, att, flag, i));
	}
	else
	{
		flag = 0;
		return (ft_write_word(s, att, flag, i));
	}
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
		att->x2 = 0;
		// printf("questa è s prima della funzione: %s\n", s);
		while (*s == ' ')
			s++;
		s = get_cmd_token(s, att);
		if (att->arr2[att->y2] == 0 && att->y2 < att->count_words)
		{
			s = NULL;
			return ;
		}
		att->y2++;
	}
}

void	get_cmd_matrix(char *s, t_attr *att)
{
	if (!s)
		return ;
	ft_count_words(s, att);
	create_matrix_cmd(s, att);
}

