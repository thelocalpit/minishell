/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02a-custom-itoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:26:11 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 12:10:37 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	nsize(int i)
{
	int	number;

	number = 0;
	if (i <= 0)
		number++;
	while (i != 0)
	{
		number++;
		i = i / 10;
	}
	return (number);
}

int	is_positive(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	custom_itoa(int c, t_attr *strct)
{
	char	*tmp;
	int		j;

	j = nsize(c);
	tmp = malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return ;
	tmp[j] = '\0';
	if (c < 0)
		tmp[0] = '-';
	else if (c == 0)
		tmp[0] = '0';
	while (c != 0)
	{
		j--;
		tmp[j] = is_positive(c % 10) + '0';
		c = c / 10;
	}
	j = 0;
	while (tmp[j])
		strct->array2[strct->y2][strct->x2++] = tmp[j++];
	free(tmp);
	return ;
}

void	exp_print_counter_error(t_attr *strct)
{
	strct->mem_space = nsize(strct->value);
	strct->i += 2;
	strct->i_flag_dol++;
}
