/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_single_token_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:26 by pfalasch          #+#    #+#             */
/*   Updated: 2023/12/14 10:12:56 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_intsize(int n)
{
	int count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static int ft_ispositive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void ft_itoa_custom(int n, t_attr *att)
{
	char *str;
	int i;

	i = ft_intsize(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return ;
	str[i] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		i--;
		str[i] = ft_ispositive(n % 10) + '0';
		n = n / 10;
	}
	i = 0;
	while (str[i])
	{
		att->arr2[att->y2][att->x2++] = str[i++];
	}
	free(str);
	return ;
}


int ft_strlen_custom(char *s, int flag, t_attr *att)
{
	int save_$;

	save_$ = 0;
	att->mem_space = 0;
	att->index = 0;
	if (!s)
		return (0);
	if (flag == 0)
	{		
		save_$ = att->i_flag$;
		while (s[att->index] != ' ' && s[att->index])
		{
			if (s[att->index] == '$' && s[att->index + 1] == '?')
			{
				att->mem_space = ft_intsize(g_value);
				att->index += 2;
				att->i_flag$++;
			}
			if (s[att->index] == '$' && s[att->index + 1] != ' ' && s[att->index + 1])
			{
				// printf("questa è kla cazzo di flag: %d\n", att->flag$[att->i_flag$]);
				if (att->flag$[att->i_flag$] == 0)
				{
					att->index++;
					count_expanded_token(att, s);
				}
				else
				{
					att->index++;
					while (s[att->index] != '"' && s[att->index] != ' ' && s[att->index] != '$' && s[att->index])
					{
						// printf("sono qui\n");
						att->index++;
					}
				}
				att->i_flag$++;
			}
			else
			{
				att->mem_space++;
				att->index++;
			}
			
		}
		att->i_flag$ = save_$;
	}
	if (flag == 1)
	{
		att->index++;
		while (s[att->index] != '\'')
		{
			// if (att->index == '$')
			// 	att->i_flag$++;
			att->mem_space++;
			att->index++;
		}
	}
	if (flag == 2)
	{
		
		save_$ = att->i_flag$;
		att->index++;
		while (s[att->index] != '"')
		{
			if (s[att->index] == '$' && s[att->index + 1] != ' ' && s[att->index + 1] && s[att->index + 1] != '"')
			{
				if (att->flag$[att->i_flag$] == 0)
				{
					att->index++;
					count_expanded_token(att, s);
					// att->i_flag$++;
				}
				else
				{
					att->index++;
					// printf("QUESTO è S[ATT->INDEX] = %c\n", s[att->index]);
					while (s[att->index] != '"' && s[att->index] != ' ' && s[att->index] != '$' && s[att->index])
						att->index++;
				}
				att->save_y_mx_envp[att->i_flag$] = att->y_mx_envp;
				att->i_flag$++;
			}
			else
			{
				// printf("sono qui e questo è l'else e dovrebbe essere un $: %c\n", s[att->index]);
				att->mem_space++;
				att->index++;
			}
		}
		att->i_flag$ = save_$;
	}
	// printf("questa è s: %s\n", s);
	// printf("att->mem_space: %d\n", att->mem_space);
	return (att->mem_space);
}


char *ft_write_word(char *s, t_attr *att, int flag, int i)
{
	int len;
	int len_name_var;

	len_name_var = 0;
	len = ft_strlen_custom(s, flag, att);
	att->arr2[att->y2] = malloc(len + 1);
	if (!att->arr2[att->y2])
		return (NULL);
	if (flag == 2)
	{
		while (s[i] != '"')
		{
			if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1] && s[i + 1] != '"')
			{
				if (att->flag$[att->i_flag$] == 0)
				{
					i++;
					len_name_var = i;
					while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
						i++;
					len_name_var = i - len_name_var;
					copy_expanded_str(att, len_name_var, flag);
				}
				else
				{
					i++;
					while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
						i++;
				}
				att->i_flag$++;
			}
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
			if (s[i] == '$' && s[i + 1] == '?')
			{
				ft_itoa_custom(g_value, att);
				i += 2;
			}
			// printf("questo è att_y_mx_envp: %d\n", att->y_mx_envp);
			if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1])
			{
				if (att->flag$[att->i_flag$] == 0)
				{
					i++;
					len_name_var = i;
					while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
						i++;
					len_name_var = i - len_name_var;
					copy_expanded_str(att, len_name_var, flag);
					// printf("questo s[i]: %s\n", &s[i]);
				}
				else
				{
					i++;
					while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
						i++;
				}
				att->i_flag$++;
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
	att->i_flag$ = 0;
	att->x2 = 0;
	att->y2 = 0;
	att->arr2 = malloc((att->count_words + 1) * sizeof(char *));
	att->arr2[att->count_words] = NULL;
	if (!att->arr2)
		return;
	// att->flag$ = malloc((att->count_words + 1) * sizeof(int));
	// if (!att->flag$)
	// 	return;
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

