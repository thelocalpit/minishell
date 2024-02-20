/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:17:05 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:10:25 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_free(t_attr *att)
{
	free_array2(att->array2, att);
	free_arr(att->split_array);
	free_local_list(att);
	free_env_list(att);
	if (att->pipes_num != 0)
		ft_delete_matrix(att->pipes_fd);
	// free_arr(att->env);
	// free_arr(att->paths);
}

int	ft_exit_02(t_attr *att)
{
	int		i;
	char	*str;
	int		flag;

	i = 0;
	str = att->array2[1];
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
		att->value = ft_atoi(str);
	else
		exit__err(str, att);
	return (att->value);
}

void	ft_exit_custom(t_attr *att)
{
	att->value = 0;
	if (att->words_counter == 1)
		att->value = 0;
	else if (att->words_counter == 2)
		att->value = ft_exit_02(att);
	else
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		att->value = 1;
		return ;
	}
	exit_free(att);
	write(1, "exit\n", 5);
	exit(att->value);
}
