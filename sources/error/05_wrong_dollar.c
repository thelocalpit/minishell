/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_wrong_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:52 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/23 16:20:02 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* queste due funzioni servono solamente a ridurre il numero di righe */
void error_dollar_02_b(char *check_envp, int *j, int *len, t_attr *att)
{
	check_envp[*j] = '=';
	check_envp[*j + 1] = '\0';
	len += 1;
	att->y_mx_envp = 0;
	att->x_mx_envp = *len;
}
void error_dollar_02_a(char *s, int *i, int *len)
{
	while (s[*i] != '"' && s[*i] != '\'' && s[*i] != ' ' && s[*i])
	{
		(*i)++;
		(*len)++;
		if (s[*i] == '$')
			break;
	}
}

int error_dollar_02(char *s, int i, t_attr *att)
{
	int len;
	char *check_envp;
	int j;
	int start;

	len = 0;
	j = 0;
	i++;
	start = i;
	if (s[i] == '?')
		return (1);
	error_dollar_02_a(s, &i, &len);
	check_envp = malloc(sizeof(char) * len + 2); 
	i = start;
	while (j < len)
		check_envp[j++] = s[i++];
	error_dollar_02_b(check_envp, &j, &len, att);
	// printf("questa è check_envp: %s\n", check_envp);
	if (error_dollar_03(check_envp, att, len) == -1)
	{
		free(check_envp);
		return (-1);
	}
	free(check_envp);
	return (len - 1);
}
int error_dollar_01(char *s, t_attr *att)
{
	if (count_dollar_sign(s, att) != 0)
	{
		att->save_y_mx_envp = malloc(sizeof(int) * att->nb_$);
		att->flag$ = malloc(sizeof(int) * att->nb_$);
		if (!att->flag$ && !att->save_y_mx_envp)
			return (-1);
		att->i_flag$ = 0;
	}
	return (0);
}
int error_dollar(char *s, t_attr *att)
{
	int i;

	if (error_dollar_01(s, att))
		return (-1);
	i = 0;
	while (s[i] && att->i_flag$ < att->nb_$)
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
				i++;
		}
		else if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1] && s[i +1] != '"')
		{
			if (error_dollar_02(s, i, att) == -1)
				att->flag$[att->i_flag$] = -1;
			else
				i += error_dollar_02(s, i, att);
			att->i_flag$++;
		}
		i++;
	}
	return (0);
}
