/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_token_init_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:12:26 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/13 17:18:32 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	process_special_token(t_attr *att, char *s, int i)
{
	if (s[i] == '|' || s[i] == '>' || s[i] == '<')
	{
		att->nb_tokens++;
		if (s[i] == '|')
			return (++i);
		else if (s[i] == '>' && s[i + 1] == '>')
			return (i + 2);
		else if (s[i] == '>' && s[i + 1] != '>')
			return (++i);
		else if (s[i] == '<' && s[i + 1] == '<')
			return (i + 2);
		else /* if (s[i] == '<' && s[i + 1] != '<') */
			return (++i);
	}
	else
		return (++i);
}

int	count_tokens(char *s, t_attr *att)
{
	int i;
	int len;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s) - 1;
	while (i <= len)
	{
		if (s[i] != ' ' && s[i] != '|' && s[i] != '<' && s[i] != '>')
		{
			att->nb_tokens++;
			while (i <= len && (s[i] != '|' && s[i] != '<' && s[i] != '>'))
				i++;
		}
		if (s[i] == ' ')
			i++;
		else
			i = process_special_token(att, s, i);
	}
	return (att->nb_tokens);
}

char	**split_init(char *s, t_attr *att)
{
	if (!s)
		return (NULL);
	att->nb_tokens = 0;
	att->split_arr = NULL;
	count_tokens(s, att);
	create_array(s, att);
	return (att->split_arr);
}
