/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_token_in_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:04:54 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/23 15:38:46 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* in this ft we check every single options that can occur with (|,<,>) */

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

/* in this function we, as the function say, get the token to put in the
	matrix. to do so, we scan the str and check if it's a special char or if
	it's a str of character. */
	
char *get_token(char *s)
{
	char *token;
	int i;
	int j;

	i = 0;
	j = 0;
	token = 0;
	if (s[j] != '|' && s[j] != '>' && s[j] != '<')
	{
		while (s[j] != '|' && s[j] != '>' && s[j] != '<' && s[j] != '\0')
			j++;
		token = malloc(sizeof(char) * (j + 1));
		if (!token)
			return (NULL);
		token[j] = '\0';
		while (i < j)
		{
			token[i] = s[i];
			i++;
		}
	}
	else
		check_next_special_token(s, j, &token);
	return (token);
}
/* In this function I'm creating a matrix, allocating space thanks to the
	number of tokens we found. 
	In the while loop, we continue untile the variable i reach the same value
	of nb_tokens. it's important to get rid of the spaces so another while
	is necessary.
	when we find something different from a ' ', we call the function
	get_token that we'll return a str. we do this process for all the tokens 
	we have.  */
	
void	create_array(char *s, t_attr *att)
{
	int i;

	i = 0;
	att->split_arr = malloc((att->nb_tokens + 1) * sizeof(char *));
	att->split_arr[att->nb_tokens] = NULL;
	if (!att->split_arr)
		return ;
	while (i < att->nb_tokens)
	{
		while (*s == ' ')
			s++;
		att->split_arr[i] = get_token(s);
		s += ft_strlen(att->split_arr[i]);
		i++;
	}
}

