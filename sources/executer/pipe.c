/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 19:45:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/10 20:26:34 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_pipes(char *s, t_attr *att)
{
	int	i;

	att->nb_pipes = 0;
	i = 0;
	while (att->split_arr[i])
	{
		if (ft_strcmp(att->split_arr[i], "|"))
			att->nb_pipes++;
		i++;
	}
}

void init_pipes(t_attr *att)
{
	int i;

	att->pipesfd = ft_calloc(att->nb_pipes + 1, sizeof(int *));
	if (!att->pipesfd)
		return;
	i = -1;
	while (++i < att->nb_pipes)
	{
		att->pipesfd[i] = malloc(2 * sizeof(int));
		pipe(att->pipesfd[i]);
	}
}