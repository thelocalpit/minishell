/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02a_itoa_custom.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:26:11 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 12:10:37 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_intsize(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

int	ft_ispositive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_itoa_custom(int n, t_attr *att)
{
	char	*str;
	int		i;

	i = ft_intsize(n);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return ;
	str[i] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		i--;
		str[i] = ft_ispositive(n % 10) + '0';
		n = n / 10;
	}
	i = 0;
	while (str[i])
		att->array2[att->y2][att->x2++] = str[i++];
	free(str);
	return ;
}
