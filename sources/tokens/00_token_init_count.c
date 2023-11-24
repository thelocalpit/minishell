/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_token_init_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:12:26 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/23 15:38:28 by pfalasch         ###   ########.fr       */
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
/* to count tokens we get the len of s. 
	with those conditions we intend to count (cmd + args) and (|,>,<)
	 */
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
/* this funciton is the start of the split of the line.
	first of all, we'll count how many tokens we have.
	with tokens I mean: (cmd + args) or a (|, >, <). 
	this will be useful later when we'll split again each
	(cmd + args) to actually the pass it to the exec.
	In the meantime, we isolate also the (|, >, <). 
	This way we'll later know where to redirect the output
	and eventually get the input of all (cmd + args)
	 */
void	split_init(char *s, t_attr *att)
{
	if (!s)
		return ;
	att->nb_tokens = 0;
	att->split_arr = NULL;
	count_tokens(s, att);
	create_array(s, att);;
}
