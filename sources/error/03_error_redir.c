/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_error_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:06:22 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/18 19:01:32 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int error_last_redir(t_attr *att)
{
	int i;

	i = 0;
	while (att->split_arr[i])
		i++;
	i--;
	if ((att->split_arr[i][0] == '>' && att->split_arr[i][1] == '\0')
		|| (att->split_arr[i][0] == '>' && att->split_arr[i][1] == '>'
			&& att->split_arr[i][2] == '\0')
		|| (att->split_arr[i][0] == '<' && att->split_arr[i][1] == '\0')
		|| (att->split_arr[i][0] == '<' && att->split_arr[i][1] == '<'
			&& att->split_arr[i][2] == '\0')
		|| (att->split_arr[i][0] == '|' && att->split_arr[i][1] == '\0'))
	{
		printf("Error: redir as last cmd in the line\n");
		return (1);
	}
	return (0);
}

