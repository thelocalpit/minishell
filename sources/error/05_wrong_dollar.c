/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_wrong_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:52 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/29 11:28:35 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int error_dollar_03(char *check_envp, t_attr *att, int len) 
{
	// printf("questa è la stringa che viene passata: %c\n", att->mx_envp[att->y_mx_envp][att->x_mx_envp]);
	while (att->mx_envp[att->y_mx_envp])
	{
		if (!ft_strncmp(check_envp, att->mx_envp[att->y_mx_envp], len))
			return (len);
		att->y_mx_envp++;
	}
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
		// printf("questo è il n di i - 1: %d\n", i - 1);
		// write(1, &check_envp[i - 1], 1);
		// write(1, "\n", 1);
		i++;
	}
	check_envp[i - 1] = '=';
	check_envp[i] = '\0';
	// printf("questo è check_exp: %s\n", att->check_exp);
	att->y_mx_envp = 0;
	att->x_mx_envp = len;
	if (error_dollar_03(check_envp, att, len) == -1)
	{
		free(check_envp);
		return (-1);
	}
	free(check_envp);
	return (len);
}

int error_dollar(char *s, t_attr *att)
{
	int i;

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
				printf("ERROR: check close to '$'\n");
				return (-1);
			}
			else
				i += error_dollar_02(s, i, att);
		}
		i++;
	}
	return (0);
}