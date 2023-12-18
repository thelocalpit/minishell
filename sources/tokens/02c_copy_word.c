/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02c_copy_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:16:38 by pfalasch          #+#    #+#             */
/*   Updated: 2023/12/18 13:01:26 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_strlen_name_var(char *s, int *i, int len_name_var)
{
	len_name_var = (*i);
	while (s[*i] != '"' && s[*i] != ' ' && s[*i] != '$' && s[*i])
		(*i)++;
	len_name_var = (*i) - len_name_var;
	return (len_name_var);
}

int copy_g_value(t_attr *att, int i)
{
	ft_itoa_custom(g_value, att);
	i += 2;
	return (i);
}

int copy_no_quotes(char *s, int i, t_attr *att, int len_name_var)
{
	while (s[i] != ' ' && s[i])
	{
		if (s[i] == '$' && s[i + 1] == '?')
			i = copy_g_value(att, i);
		else if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1])
		{
			i++;
			if (att->flag$[att->i_flag$] == 0)
			{
				len_name_var = ft_strlen_name_var(s, &i, len_name_var);
				copy_expanded_str(att, len_name_var, 0);
			}
			else
			{
				while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
					i++;
			}
			att->i_flag$++;
		}
		else
			att->arr2[att->y2][att->x2++] = s[i++];
	}
	return (i);
}

int copy_double_quotes(char *s, int i, t_attr *att, int len_name_var)
{
	while (s[i] != '"')
	{
		if (s[i] == '$' && s[i + 1] == '?')
			i = copy_g_value(att, i);
		else if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1] && s[i + 1] != '"')
		{
			i++;
			if (att->flag$[att->i_flag$] == 0)
			{
				len_name_var = ft_strlen_name_var(s, &i, len_name_var);
				copy_expanded_str(att, len_name_var, 2);
			}
			else
			{
				while (s[i] != '"' && s[i] != ' ' && s[i] != '$' && s[i])
					i++;
			}
			att->i_flag$++;
		}
		else
			att->arr2[att->y2][att->x2++] = s[i++];
	}
	return (i);
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
		i = copy_double_quotes(s, i, att, len_name_var);
	}
	else if (flag == 1)
	{
		while (s[i] != '\'')
			att->arr2[att->y2][att->x2++] = s[i++];
	}
	else
	{
		i = copy_no_quotes(s, i, att, len_name_var);
	}
	att->arr2[att->y2][att->x2] = '\0';
	return (&s[++i]);
}
