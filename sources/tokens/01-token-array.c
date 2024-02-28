/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01-token-array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:04:54 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 12:07:06 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	special_token_check(char *c, int j, char **str)
{
	if (c[j] == '|')
	{
		*str = malloc(sizeof(char) * 2);
		(*str)[0] = c[j];
		(*str)[1] = 0;
	}
	else if (c[j] == '>' && c[j + 1] != '>')
	{
		*str = malloc(sizeof(char) * 2);
		(*str)[0] = c[j];
		(*str)[1] = 0;
	}
	else if (c[j] == '>' && c[j + 1] == '>')
	{
		*str = malloc(sizeof(char) * 3);
		(*str)[0] = c[j];
		(*str)[1] = c[j + 1];
		(*str)[2] = 0;
	}
}

int	token_1(char *c, int i)
{
	while (c[i] != '|' && c[i] != '>' && c[i] != '<' && c[i] != '\0')
	{
		if (c[i] == '\'' || c[i] == '"')
			i = s_d_quotes(c, i);
		i++;
	}
	return (i);
}

void	special_token_check2(char *c, int j, char **str)
{
	if (c[j] == '<' && c[j + 1] != '<')
	{
		*str = malloc(sizeof(char) * 2);
		(*str)[0] = c[j];
		(*str)[1] = 0;
	}
	else if (c[j] == '<' && c[j + 1] == '<')
	{
		*str = malloc(sizeof(char) * 3);
		(*str)[0] = c[j];
		(*str)[1] = c[j + 1];
		(*str)[2] = 0;
	}
}

char	*get_token(char *c)
{
	char	*str;
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (c[b] != '|' && c[b] != '>' && c[b] != '<')
	{
		b += token_1(c, b);
		str = malloc(sizeof(char) * (b + 1));
		if (!str)
			return (NULL);
		str[b] = '\0';
		while (a < b)
		{
			str[a] = c[a];
			a++;
		}
	}
	else
	{
		special_token_check(c, b, &str);
		special_token_check2(c, b, &str);
	}
	return (str);
}

void	build_array(char *c, t_attr *strc)
{
	int	j;

	j = 0;
	strc->split_array = malloc((strc->num_tokens + 1) * sizeof(char *));
	strc->split_array[strc->num_tokens] = NULL;
	if (!strc->split_array)
		return ;
	while (j < strc->num_tokens)
	{
		while (*c == ' ')
			c++;
		strc->split_array[j] = get_token(c);
		c += ft_strlen(strc->split_array[j]);
		j++;
	}
}
