/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_single_token_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:26 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/29 20:29:40 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_strlen_custom(char *s, int flag, t_attr *att)
{

	att->mem_space = 0;
	att->index = 0;
	if (!s)
		return (0);
	if (flag == 0)
	{
		while (s[att->index] != ' ' && s[att->index])
		{
			if (s[att->index] == '$')
			{
				att->index++;
				count_expanded_token(att, s);
				printf("questa è s[i]: %s\n", &s[att->index]);
			}
			else
			{
				att->mem_space++;
				att->index++;
			}
		}
	}
	if (flag == 1)
	{
		att->index++;
		while (s[att->index] != '\'')
		{
			att->mem_space++;
			att->index++;
		}
	}
	if (flag == 2)
	{
		att->index++;
		while (s[att->index] != '"')
		{
			if (s[att->index] == '$')
			{
				att->index++;
				count_expanded_token(att, s);
				printf("questa è s[i]: %s\n", &s[att->index]);
			}
			else
			{
				att->mem_space++;
				att->index++;
				
			}
		}
	}
	return (att->mem_space);
}


char *ft_write_word(char *s, t_attr *att, int flag, int i)
{
	int len;
	int len_name_var;

	// printf("questa è s: %s\n", s);
	len_name_var = 0;
	len = ft_strlen_custom(s, flag, att);
	printf("questo è il numero di celle di memoria alloc: %d\n", len);
	att->arr2[att->y2] = malloc(len + 1);
	if (!att->arr2[att->y2])
		return (NULL);
	if (flag == 2)
	{
		while (s[i] != '"')
		{
			// if ((s[i] == '\\' && s[i + 1] == '"') || (s[i] == '\\' && s[i +1] == '$'))
			// 	i++;
			if (s[i] == '$')
			{
				i++;
				len_name_var = i;
				while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
					i++;
				len_name_var = i - len_name_var;
				copy_expanded_str(att, len_name_var);
				copy_expanded_str(att, i);
				printf("questo s[i]: %s\n", &s[i]);
			}
			// att->flag$[att->y2] = 1;
			else
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
		{
			if (s[i] == '$')
			{
				i++;
				len_name_var = i;
				while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
					i++;
				len_name_var = i - len_name_var;
				copy_expanded_str(att, len_name_var);
				printf("questo s[i]: %s\n", &s[i]);	
			}
			else
				att->arr2[att->y2][att->x2++] = s[i++];
		}
	}
	att->arr2[att->y2][att->x2] = '\0';
	return (&s[++i]);
}

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
		return;
	att->flag$ = malloc((att->count_words + 1) * sizeof(int));
	if (!att->flag$)
		return;
	while (att->y2 < att->count_words)
	{
		att->x2 = 0;
		while (*s == ' ')
			s++;
		// printf("sono qui\n");
		s = get_cmd_token(s, att);
		if (att->arr2[att->y2] == 0 && att->y2 < att->count_words)
		{
			s = NULL;
			return ;
		}
		att->y2++;
	}
}

void get_cmd_matrix(char *s, t_attr *att)
{
	if (!s)
		return ;
	ft_count_words(s, att);
	// printf("sono qui\n");
	create_matrix_cmd(s, att);
}

