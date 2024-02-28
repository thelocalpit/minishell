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

int	ft_intsize(int i)
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

int	ft_ispositive(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	ft_itoa_custom(int c, t_attr *strct)
{
	char	*tmp;
	int		j;

	j = ft_intsize(c);
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
		tmp[j] = ft_ispositive(c % 10) + '0';
		c = c / 10;
	}
	j = 0;
	while (tmp[j])
		strct->array2[strct->y2][strct->x2++] = tmp[j++];
	free(tmp);
	return ;
}
