/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:00:38 by deggio            #+#    #+#             */
/*   Updated: 2024/02/16 23:32:47 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_arr3(t_attr *att)
{
    int y;
	int y2;
    
    if (!att->flag3)
        return ;
    y = att->y;
	att->y3 = 0;
	att->arr3 = malloc((count_arr3(att) + 1) * sizeof(char *));
    while (y <= att->i_redir + 1 || y <= att->i_readfile + 1)
    {
						free_arr(att->arr2);
		get_cmd_matrix(att->split_arr[y], att);
		if (att->y3 == 0)
			y2 = 0;
		else
			y2 = 1;
		while (att->arr2[y2])
		{
			att->arr3[att->y3] = ft_strdup(att->arr2[y2]);
			att->y3++;
			y2++;
		}
		y += 2;
    }
	att->arr3[att->y3] = NULL;
	free_arr(att->arr2);
		get_cmd_matrix(att->split_arr[y], att);
}

int	count_arr3(t_attr *att)
{
	int y;
	int count;

	y = att->y;
	count = 0;
	while (y <= att->i_redir + 1 || y <= att->i_readfile + 1)
	{
		ft_count_words(att->split_arr[y], att);
		count += att->count_words - 1;
		y += 2;
	}
	return (count);
}
