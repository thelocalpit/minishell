/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_single_token_matrix.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:53:26 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/23 17:58:44 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


//forse c'è da gestire il dollar sign per le doubleqoutes

void ft_get_arg(char *s, t_attr *att)
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

void get_first_cmd(char *s, t_attr *att)
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
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] <= 'A' && s[i] <= 'Z'))
				att->matrix_single_cmd[att->count][j++] = s[i++];
			else
				return ;
		}
		att->i_matrix_token = i;
	}
	else if (s[i] == '\'')
	{
		i++;
		if (s[i + 1] == '\'')
			return ;
		while (s[i] != '\'')
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] <= 'A' && s[i] <= 'Z'))
				att->matrix_single_cmd[att->count][j++] = s[i++];
			else
				return ;
		}
		att->i_matrix_token = i;
	}
	else
	{
		while (s[i] != ' ' || s[i])
		{
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] <= 'A' && s[i] <= 'Z'))
				att->matrix_single_cmd[att->count][j++] = s[i++];
			else
				return ;
		}
		att->i_matrix_token = i;
	}
}

void	get_single_token(char *s, t_attr *att)
{
	int i;

	i = 0;
	while (s[i] == ' ')
		i++;
	/* if (s[i] == '>')
	{
		//add flag nel caso in cui prima parola della stringa sia una redirection
		//che crea un file nuovo vuoto con il nome della parola successiva. 
		//es: > ciao crea un file dal nome ciao
	} */
	if (s[i] != '|' && s[i] != '>' && s[i] != '<' && att->count == 0)
	{
		get_first_cmd(s, att);
		att->i_matrix_token = i;
	}
	else if (att->count > 0)
	{
		while (s[i] == ' ')
			i++;
		ft_get_arg(s, att);
		att->i_matrix_token = i;
	}
}

void count_elements_cmd(char *s, t_attr *att)
{
	printf("ciao sono in count\n");
	int len;
	int i;

	att->nb_elements_token = 0;
	len = ft_strlen(s) - 1;
	i = 0;
	while (i < len)
	{
		if (s[i] == ' ')
			i++;
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
				i++;
			att->nb_elements_token++;
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
			att->nb_elements_token++;
		}
		else
		{
			printf("sono entrato nell'else\n");
			while (s[i] != ' ' || s[i])
				i++;
			att->nb_elements_token++;
		}
	}
	printf("ciao sono in count alla fine\n");
}
void	create_matrix_cmd(char *s, t_attr *att)
{
	att->i_matrix_token = 0;
	att->matrix_single_cmd = malloc((att->nb_elements_token + 1) * sizeof(char *));
	att->matrix_single_cmd[att->nb_elements_token] = NULL;
	if (!att->matrix_single_cmd)
		return ;
	att->count= 0;
	while (att->count < att->nb_elements_token)
	{
		while (*s == ' ')
			s++;
		get_single_token(s, att);
		s += att->i_matrix_token;
		att->count++;
	}
	/* quello che c'è da scorrere qua è la matrice, e capire cosa è cosa e effettivamente
	tokenizzare.  */
}

void	get_cmd_matrix(char *s, t_attr *att)
{
	printf("ciao sono in get_cmd_matrix\n");
	if (!s)
		return ;
	count_elements_cmd(s, att);
	printf("ciao sono in get_cmd_matrix\n");
	printf("questo è il numero di token del cmd: %d\n", att->nb_elements_token);
	create_matrix_cmd(s, att);
}