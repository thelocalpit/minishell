/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:39:25 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/22 16:16:14 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char *custom_getenv(const char *var_name, t_attr *att)
{
	int i;
	char *entry;
	char *delimiter;
	size_t variable_length;

	if (att->g_env == NULL)
		return (NULL);
	i = 0;
	while (att->g_env[i] != NULL)
	{
		entry = att->g_env[i];
		delimiter = ft_strchr(entry, '=');
		if (delimiter != NULL)
		{
			variable_length = delimiter - entry;
			if (ft_strncmp(entry, var_name, variable_length) == 0 && var_name[variable_length] == '\0')
				return (delimiter + 1);
		}
		i++;
	}
	return (NULL);
}

void init_var(t_attr *att)
{
	att->var_name = NULL;
	att->value = NULL;
	att->expanded_length = 0;
	att->token_length = 0;
	att->expanded_token = 0;
	att->i = 0;
	att->j = 0;
	att->has_quote = 0;
}
void expand_tokens2(char **tokens, t_attr *att, int j)
{
	att->expanded_length = ft_strlen(att->value);
	att->token_length = ft_strlen(tokens[att->i]) - j + 1;
	att->expanded_token = malloc((att->token_length + att->expanded_length + 1) * sizeof(char));
	ft_strncpy(att->expanded_token, tokens[att->i], j);
	att->expanded_token[j] = '\0';
	ft_strcat(att->expanded_token, att->value);
	ft_strcat(att->expanded_token, tokens[att->i] + j + ft_strlen(att->var_name) + 1);
	free(tokens[att->i]);
	tokens[att->i] = att->expanded_token;
	if (att->has_quote)
		free(att->var_name);
	j += att->expanded_length;
}

char *correct_name(char *str)
{
	int i;
	int j;
	char *correct;

	correct = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\'')
		{
			correct[j] = str[i];
			j++;
		}
		i++;
	}
	correct[j] = 0;
	return (correct);
}

char **expand_tokens(char **tokens, t_attr *att)
{
	int j;

	printf("sono qui\n");
	init_var(att);
	while (tokens[att->i])
	{
		j = 0;
		while (tokens[att->i][j])
		{
			if (tokens[att->i][j] == '"')
				att->has_quote = 1;
			else if ((tokens[att->i][j] == '$' && tokens[att->i][j + 1]))
			{
				att->var_name = tokens[att->i] + j + 1;
				if (att->has_quote == 1)
					att->var_name = correct_name(tokens[att->i] + j + 1);
				att->value = custom_getenv(att->var_name, att);
				if (att->value)
					expand_tokens2(tokens, att, j);
			}
			j++;
		}
		att->i++;
	}
	return (tokens);
}