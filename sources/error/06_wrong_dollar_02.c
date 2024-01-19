/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_wrong_dollar_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:46:01 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/19 18:08:59 by pfalasch         ###   ########.fr       */
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

int check_local_list(char *check_envp, t_attr *att, int len)
{
	t_list *current;

	current = att->local_var;
	while (att->local_var != NULL)
	{
		if (!ft_strncmp(check_envp, att->local_var->content, len))
			return (0);
		att->local_var = att->local_var->next;
		att->i_env++;
	}
	att->local_var = current;
	return (-1);
}

int error_dollar_03(char *check_envp, t_attr *att, int len)
{
	t_list *current;

	current = att->env_list;
	att->i_env = 0;
	while (att->env_list != NULL)
	{
		if (!ft_strncmp(check_envp, att->env_list->content, len))
			return (0);
		if (!ft_strncmp(check_envp, "?", 1))
			return (0);
		att->env_list = att->env_list->next;
		att->i_env++;
	}
	att->env_list = current;
	if (!check_local_list(check_envp, att, len))
		return (0);
	return (-1);
}
