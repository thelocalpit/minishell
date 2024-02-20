/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:26:11 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 11:52:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isspace(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' && s[i] == '\t')
			i++;
		else
			return (1);
	}
	return (0);
}

void	envp_to_matrix(t_attr *att)
{
	t_list	*tmp_list;
	int		i;

	tmp_list = att->env_list;
	i = 0;
	att->env = malloc(sizeof(char *) * (ft_lstsize(tmp_list) + 1));
	tmp_list = att->env_list;
	while (tmp_list)
	{
		att->env[i] = ft_strdup(tmp_list->content);
		tmp_list = tmp_list->next;
		i++;
	}
	att->env[i] = NULL;
}

int	matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
