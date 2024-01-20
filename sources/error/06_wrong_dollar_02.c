/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_wrong_dollar_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:46:01 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/18 11:24:44 by pfalasch         ###   ########.fr       */
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
	t_list *tmp_list;

	tmp_list = att->local_var;
	while (tmp_list != NULL)
	{
		if (!ft_strncmp(check_envp, tmp_list->content, len))
			return (0);
		tmp_list = tmp_list->next;
		att->y_mx_envp++;
	}
	return (-1);
}

int error_dollar_03(char *check_envp, t_attr *att, int len)
{
	t_list *tmp_list;

	tmp_list = att->env_list;
	att->y_mx_envp = 0;
	printf("111111111111111111111111111111111111111111111111\n");
	while (tmp_list != NULL)
	{
		if (!ft_strncmp(check_envp, tmp_list->content, len))
		{
			printf("PRIMO IF\n");
			return (0);
		}
		if (!ft_strncmp(check_envp, "?", 1))
		{
			printf("SECONDO IF\n");
			return (0);
		}
		tmp_list = tmp_list->next;
		att->y_mx_envp++;
	}
	printf("SIAMO QUI CHE CAZZ ONNE SSO PORCO DIO\n");
	if (!check_local_list(check_envp, att, len))
		return (0);
	return (-1);
}
