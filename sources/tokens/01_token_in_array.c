/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_token_in_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:04:54 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/13 18:31:33 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void check_next_special_token(char *s, int i, char **token)
{
	if (s[i] == '|')
	{
		*token = malloc(sizeof(char) * 2);
		(*token)[0] = s[i];
		(*token)[1] = 0;
	}
	else if (s[i] == '>' && s[i + 1] != '>')
	{
		*token = malloc(sizeof(char) * 2);
		(*token)[0] = s[i];
		(*token)[1] = 0;
	}
	else if (s[i] == '>' && s[i + 1] == '>')
	{
		*token = malloc(sizeof(char) * 3);
		(*token)[0] = s[i];
		(*token)[1] = s[i + 1];
		(*token)[2] = 0;
	}
	else if (s[i] == '<' && s[i + 1] != '<')
	{
		*token = malloc(sizeof(char) * 2);
		(*token)[0] = s[i];
		(*token)[1] = 0;
	}
	else if (s[i] == '<' && s[i + 1] == '<')
	{
		*token = malloc(sizeof(char) * 3);
		(*token)[0] = s[i];
		(*token)[1] = s[i + 1];
		(*token)[2] = 0;
	}
}

char *get_token(char *s)
{
	char	*token;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s[i] != '|' && s[i] != '>' && s[i] != '<')
	{
		while (s[i] != '|' && s[i] != '>' && s[i] != '<' && s[i] != '\0')
			i++;
		token = malloc(sizeof(char) * (j + 1));
		if (!token)
			return (NULL);
		token[i] = '\0';
		while (j < i)
		{
			token[j] = s[j];
			j++;
		}
	}
	else
		check_next_special_token(s, i, &token);
	return (token);
}

void	create_array(char *s, t_attr *att)
{
	int i;
	int j;

	i = 0;
	j = 0;
	att->split_arr = malloc((att->nb_tokens + 1) * sizeof(char *));
	att->split_arr[att->nb_tokens] = NULL;
	if (!att->split_arr)
		return ;
	while (i < att->nb_tokens)
	{
		while (s[j] == ' ')
			j++;
		att->split_arr[i] = get_token(s);
		s += ft_strlen(att->split_arr[i]);
		i++;
	}
}

