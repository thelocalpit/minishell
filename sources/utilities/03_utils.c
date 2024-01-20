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
	t_list *tmp_list;
	int	i;

	tmp_list = att->env_list;
	i = 0;
	att->env = malloc(sizeof(char *) * (ft_lstsize(tmp_list) + 1));
	tmp_list = att->env_list;
	printf("envp_to_matrix\n");
	while (tmp_list)
	{
		att->env[i] = ft_strdup(tmp_list->content);
		tmp_list = tmp_list->next;
		i++;
	}
	// i = 0;
	// while(att->env[i])
	// {
	// 	printf("%s\n", att->env[i]);
	// 	i++;
	// }
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