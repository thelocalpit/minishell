/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:26:11 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/12 01:52:44 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	envp_to_matrix(t_attr *att)
{
	int	i;

	i = 0;
	att->env = malloc(sizeof(char *) * (ft_lstsize(att->env_list) + 1));
	while (att->env_list)
	{
		att->env[i] = ft_strdup(att->env_list->content);
		att->env_list = att->env_list->next;
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