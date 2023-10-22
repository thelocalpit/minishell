/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_single_token_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:26 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/22 13:12:56 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


//forse c'è da gestire il dollar sign per le doubleqoutes

char	*get_arg(char *s, t_attr *att, t_token *toki)
{
	int i;
	int j;
	char *token_arg;

	i = 0;
	j = 0;
	if (s[i] == '"')
	{
		i++;
		if (s[i] == '"')
			return (NULL);
		while (s[i] != '"')
		{
			if (s[i] == '\\' && s[i + 1] == '"')
				i++;
			token_arg[j++] = s[i++];
			if (s[i])
				ft_error_unclosed_quotes;
		}
		return (token_arg);
	}
	else if (s[i] == '\'')
	{
		i++;
		if (s[i + 1] == '\'')
			return (NULL);
		while (s[i] != '\'')
		{
				token_arg[j++] = s[i++];
				if (s[i])
					ft_error_unclosed_quotes;
		}
		return (token_arg);
	}
	else
	{
		while (s[i] == ' ' || s[i])
			token_arg[j++] = s[i++];
		return (token_arg);
	}

char *get_first_cmd(char *s, t_attr *att, t_token *toki)
{
	int i;
	int j;
	char *token_cmd;

	i = 0;
	j = 0;
	if (s[i] == '"')
	{
		i++;
		if (s[i] == '"')
			return (NULL);
		while (s[i] != '"')
		{
			if (s[i] == '\\' && s[i + 1] == '"')
				i++;
			if ((s[i] >= 'a' && s[i] <= 'z') || s[i] <= 'A' && s[i] <= 'Z')
				token_cmd[j++] = s[i++];
			else
				return (NULL);
		}
	}
	else if (s[i] == '\'')
	{
		i++;
		if (s[i + 1] == '\'')
			return (NULL);
		while (s[i] != '\'')
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || s[i] <= 'A' && s[i] <= 'Z')
				token_cmd[j++] = s[i++];
			else
				return (NULL);
		}
	}
	else
	{
		while (s[i] != ' ' || s[i])
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || s[i] <= 'A' && s[i] <= 'Z')
				token_cmd[j++] = s[i++];
			else
				return (NULL);
		}
	}
	return (token_cmd);
}

char *get_single_token(char *s, t_attr *att, t_token *toki, int count)
{
	int i;
	while (s[i] == ' ')
		i++;
	if (s[i] == '>')
	{
		//add flag nel caso in cui prima parola della stringa sia una redirection
		//che crea un file nuovo vuoto con il nome della parola successiva. 
		//es: > ciao crea un file dal nome ciao
	}
	else if (s[i] != '|' && s[i] != '>' != '<' && count == 0)
		return (get_first_cmd(s, att, toki));
	else if (count > 0)
	{
		while (s[i] == ' ')
			i++;
		return (get_arg(s, att, toki));
	}
}

void count_elements_cmd(char *s, t_attr *att, t_token *toki)
{
	int len;
	int i;

	toki->nb_elements_toki = 0;
	len = ft_strlen(s) - 1;
	i = 0;
	while (i <= len)
	{
		if (s[i] == ' ')
			i++;
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
				i++;
			toki->nb_elements_toki++;
		}
		else if (s[i] == '"')
		{
			i++;
			while (s[i] != '"')
			{
				if (s[i] == '\\' && s[i + 1] == '"')
					i++;
				i++;
			}
			toki->nb_elements_toki++;
		}
		else
		{
			while (s[i] != ' ' || s[i])
				i++;
			toki->nb_elements_toki++;
		}
	}
}
void	create_matrix_cmd(char *s, t_attr *att, t_token *toki)
{
	int count;

	att->i_matrix_token = 0;
	att->matrix_single_cmd = malloc((toki->nb_elements_toki + 1) * sizeof(char *));
	att->matrix_single_cmd[toki->nb_elements_toki] = NULL;
	if (!att->matrix_single_cmd)
		return;
	count = 0;
	while (count < toki->nb_elements_toki)
	{
		while (*s == ' ')
			s++;
		att->matrix_single_cmd[count] = get_single_token(s, att, toki, count);
		if (att->matrix_single_cmd[count] == 0 && count < toki->nb_elements_toki)
		{
			s = NULL;
			return;
		}
		s += att->i_matrix_token;
		count++;
	}
	/* quello che c'è da scorrere qua è la matrice, e capire cosa è cosa e effettivamente
	tokenizzare.  */
}

void	get_cmd_matrix(char *s, t_attr *att, t_token *toki)
{
	if (!s)
		return (NULL);
	count_elements_cmd(s, att, &toki);
	create_matrix_cmd(s, &att, &toki);
}