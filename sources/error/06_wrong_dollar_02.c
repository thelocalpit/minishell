/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_wrong_dollar_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:46:01 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/17 15:51:46 by pfalasch         ###   ########.fr       */
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
	t_list *current;

	current = att->env_list;
	att->y_mx_envp = 0;
	while (att->env_list != NULL)
	{
		if (!ft_strncmp(check_envp, att->env_list->content, len))
			return (0);
		if (!ft_strncmp(check_envp, "?", 1))
			return (0);
		att->env_list = att->env_list->next;
		att->y_mx_envp++;
	}
	att->env_list = current;
	return (-1);
}
