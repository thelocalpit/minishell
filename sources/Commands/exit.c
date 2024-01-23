/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:17:05 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/23 16:25:09 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void exit_free(t_attr *att)
{
	free_arr2(att->arr2, att);
	// if (att->save_y_mx_envp && att->flag$)
	// {
	// 	free(att->save_y_mx_envp);
	// 	free(att->flag$);
	// }
	free_arr(att->split_arr);
	if (att->nb_pipes != 0)
		ft_delete_matrix(att->pipesfd);
	// printf("sono dentro exit_free\n");
	// free_arr(att->env);
	// free_arr(att->paths);
}

int ft_exit_02(t_attr *att)
{
	int i;
	char *str;
	int flag;

	i = 0;
	str = att->arr2[1];
	flag = -1;
	if (str[0] == '+' || str[0] == '-' || str [0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			flag = 0;
			break;
		}
		i++;
	}
	if (flag == 0)
		g_value = ft_atoi(str);
	else
		exit__err(str);
	return (g_value);
}

void ft_exit_custom(t_attr *att)
{
	g_value = 0;
	if (att->count_words == 1)
		g_value = 0;
	else if (att->count_words == 2)
		g_value = ft_exit_02(att);
	else
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		g_value = 1;
		return ;
	}
	exit_free(att);
	exit(g_value);
}