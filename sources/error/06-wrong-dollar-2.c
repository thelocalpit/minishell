/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06-wrong-dollar-2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:46:01 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:51:07 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	local_list_check(char *envp_check, t_attr *strc, int n)
{
	t_list	*tmp_list;

	tmp_list = strc->local_list;
	while (tmp_list != NULL)
	{
		if (!ft_strncmp(envp_check, tmp_list->content, n))
			return (0);
		tmp_list = tmp_list->next;
		strc->y_mtx_envp++;
	}
	return (-1);
}

int	dollar_sign_counter(char *c, t_attr *strc)
{
	int	j;

	j = 0;
	strc->num_dol = 0;
	while (c[j])
	{
		if (c[j] == '$' && c[j + 1] != ' ' && c[j + 1] && c[j + 1] != '"')
			strc->num_dol++;
		j++;
	}
	return (strc->num_dol);
}

int	dollar_error_3(char *envp_check, t_attr *strc, int n)
{
	t_list	*tmp_list;

	tmp_list = strc->env_list;
	strc->y_mtx_envp = 0;
	while (tmp_list != NULL)
	{
		if (!ft_strncmp(envp_check, tmp_list->content, n))
			return (0);
		if (!ft_strncmp(envp_check, "?", 1))
			return (0);
		tmp_list = tmp_list->next;
		strc->y_mtx_envp++;
	}
	strc->y_mtx_envp = 0;
	if (!local_list_check(envp_check, strc, n))
		return (0);
	return (1);
}
