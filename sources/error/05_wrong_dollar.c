/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_wrong_dollar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:10:52 by pfalasch          #+#    #+#             */
/*   Updated: 2023/12/05 15:28:19 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int count_dollar_sign(char *s, t_attr *att)
{
	int i;

	i = 0;
	att->nb_$ = 0;
	while (s[i])
	{
		if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1])
			att->nb_$++;
		i++;
	}
	return (att->nb_$);
}

int error_dollar_03(char *check_envp, t_attr *att, int len)
{
	// printf("questa è la stringa che viene passata: %c\n", att->mx_envp[att->y_mx_envp][att->x_mx_envp]);
	att->y_mx_envp = 0;
	while (att->mx_envp[att->y_mx_envp])
	{
		// printf("QUESTO è LEN: %d. QUESTO CONFRONTO DELLE STR: %s == %s\n", len, check_envp, att->mx_envp[att->y_mx_envp]);
		if (!ft_strncmp(check_envp, att->mx_envp[att->y_mx_envp], len))
			return (0);
		att->y_mx_envp++;
	}
	return (-1);
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
	while (s[i] != '"' && s[i] != '\'' && s[i] != ' ' && (s[att->index] != '$' && s[att->index + 1] != ' ' && s[att->index + 1]) && s[i])
	{
		i++;
		len++;
	}
	check_envp = malloc(sizeof(char) * len + 2);
	i = start;
	while (j < len)
	{
		check_envp[j++] = s[i++];
	}
	check_envp[j] = '=';
	check_envp[j + 1] = '\0';
	len += 1;
	// printf("questa è envp: %s\n", check_envp);
	att->y_mx_envp = 0;
	att->x_mx_envp = len;
	if (error_dollar_03(check_envp, att, len) == -1)
	{
		// printf("sono qui in error_03\n");
		free(check_envp);
		return (-1);
	}
	free(check_envp);
	return (len);
}

int error_dollar(char *s, t_attr *att)
{
	int i;

	// printf("sono qui\n");
	if (count_dollar_sign(s, att) != 0)
	{
		att->flag$ = malloc(sizeof(int) * att->nb_$);
		if (!att->flag$)
			return (-1);
		att->i_flag$ = 0;
	}
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
				att->flag$[att->i_flag$] = -1;
			else
				i += error_dollar_02(s, i, att);
			att->i_flag$++;
		}
		if (s[i] == '\0')
		{
			printf("att->nb_flag == %d\n", att->nb_$);
			printf("questo sono le flag: [0]%d, [1]%d, [2]%d\n", att->flag$[0], att->flag$[1], att->flag$[2]);
			return (0);
		}
		// printf("questo è i: %d\n", i);
		// printf("questo è il carattere analizzato: %s\n", &s[i]);
		i++;
	}
	printf("att->nb_flag == %d\n", att->nb_$);
	printf("questo sono le flag: [0]%d, [1]%d, [2]%d\n", att->flag$[0], att->flag$[1], att->flag$[2]);
	return (0);
}