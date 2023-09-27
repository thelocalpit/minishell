/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:34:54 by asacchin          #+#    #+#             */
/*   Updated: 2023/09/27 19:48:27 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_tokens(char *s, t_attr *att)
{
	char	*token;
	int		i;
	int		j;

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
		check_redir();
	return (token);
}