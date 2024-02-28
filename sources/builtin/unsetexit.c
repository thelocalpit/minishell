/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetexit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:31:40 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 14:48:03 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../includes/minishell.h"

void	node_remove(t_list **src, char *str)
{
	t_list	*clone;
	t_list	*old;

	clone = *src;
	old = NULL;
	while (clone)
	{
		if (ft_strncmp(str, (char *)clone->content, ft_strlen(str)) == 0)
		{
			if (old == NULL)
				*src = clone->next;
			else
				old->next = clone->next;
			free(clone->content);
			free(clone);
			return ;
		}
		old = clone;
		clone = clone->next;
	}
}

int	unset(char **str, t_attr *strc)
{
	int	j;

	j = 1;
	while (str[j])
	{
		node_remove(&(strc->env_list), str[j]);
		node_remove(&(strc->local_list), str[j]);
		j++;
	}
	return (0);
}

int	ft_exit_02(t_attr *strc)
{
	int		j;
	char	*array;
	int		n;

	n = -1;
	j = 0;
	array = strc->array2[1];
	if (array[0] == '+' || array[0] == '-' || array [0] == '+')
		j++;
	while (array[j])
	{
		if (ft_isdigit(array[j]))
		{
			n = 0;
			break ;
		}
		j++;
	}
	if (n == 0)
		strc->value = ft_atoi(array);
	else
		error_exit(array, strc);
	return (strc->value);
}

void	exit_free(t_attr *strc)
{
	free_matrix2(strc->array2, strc);
	free_matrix(strc->split_array);
	free_local_list(strc);
	free_env_list(strc);
	if (strc->pipes_num != 0)
		delete_matrix(strc->pipes_fd);
}

void	custom_exit(t_attr *strc)
{
	strc->value = 0;
	if (strc->words_counter == 1)
		strc->value = 0;
	else if (strc->words_counter == 2)
		strc->value = ft_exit_02(strc);
	else
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		strc->value = 1;
		return ;
	}
	exit_free(strc);
	write(1, "exit\n", 5);
	exit(strc->value);
}
