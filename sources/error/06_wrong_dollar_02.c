/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_wrong_dollar_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:46:01 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/10 18:46:25 by pfalasch         ###   ########.fr       */
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
		if (s[i] == '$' && s[i + 1] != ' ' && s[i + 1] && s[i + 1] != '"')
			att->nb_$++;
		i++;
	}
	return (att->nb_$);
}

int error_dollar_03(char *check_envp, t_attr *att, int len)
{
	att->y_mx_envp = 0;
	while (att->mx_envp[att->y_mx_envp])
	{
		if (!ft_strncmp(check_envp, att->mx_envp[att->y_mx_envp], len))
			return (0);
		if (!ft_strncmp(check_envp, "?", 1))
			return (0);
		att->y_mx_envp++;
	}
	return (-1);
}