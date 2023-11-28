/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_wrong_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:52 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/28 17:50:14 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int error_dollar_03(char *s, char *check_envp, t_attr *att, int len) 
{
	while (att->mx_envp[att->y_mx_envp])
	{
		if (!ft_strncmp(check_envp, att->mx_envp[att->y_mx_envp], len))
		{
			free(check_envp);
			return (len);
		}
		att->y_mx_envp++;
	}
	free(check_envp);
	return (-1);
}


int error_dollar_02(char *s, int i, t_attr *att)
{
	int len;
	char *check_envp;

	i++;
	len = i;
	while (s[len] != '"' && s[len] != '\'' && s[len] != ' ' && s[len] != '$' && s[len])
		len++;
	check_envp = malloc(sizeof(char) * len + 1);
	while(i < len)
	{
		check_envp[i - 1] = s[i];
		i++;
	}
	check_envp[i - 1] = '=';
	check_envp[i] = '\0';
	att->y_mx_envp = 0;
	att->x_mx_envp = len;
	if (error_dollar_03(s, check_envp, att, len) == -1)
	{
		free(check_envp);
		return (-1);
	}
	free(check_envp);
	return (error_dollar_03(s, check_envp, att, len));
}

int error_dollar(char *s, t_attr *att)
{
	int i;
	int len;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'')
		{
			i++;
			while (s[i] != '\'')
				i++;
		}
		
		else if (s[i] == '$')
		{
			if (error_dollar_02(s, i, att) == -1)
			{
				printf("ERROR: check close to '$'");
				return (-1);
			}
			else
				i += error_dollar_02(s, i, att);
		}
		i++;
	}
	return (0);
}