/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:17:05 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/08 17:06:40 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_free(t_attr *att)
{
	free_arr2(att->arr2, att);
	free_arr(att->split_arr);
	free_local_var(att);
	free_env_list(att);
	if (att->nb_pipes != 0)
		ft_delete_matrix(att->pipesfd);
	// free_arr(att->env);
	// free_arr(att->paths);
}

int	ft_exit_02(t_attr *att)
{
	int		i;
	char	*str;
	int		flag;

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
			break ;
		}
		i++;
	}
	if (flag == 0)
		att->g_value = ft_atoi(str);
	else
		exit__err(str, att);
	return (att->g_value);
}

void	ft_exit_custom(t_attr *att)
{
	att->g_value = 0;
	if (att->count_words == 1)
		att->g_value = 0;
	else if (att->count_words == 2)
		att->g_value = ft_exit_02(att);
	else
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		att->g_value = 1;
		return ;
	}
	exit_free(att);
	exit(att->g_value);
}
