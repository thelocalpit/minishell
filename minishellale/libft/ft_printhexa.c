/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:46:21 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/21 15:08:54 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lencount(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_printhexa(unsigned int to_hex, char s)
{
	char	*hexbase;

	if (s == 'x')
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	if (to_hex >= 16)
	{
		ft_printhexa((to_hex / 16), s);
		ft_printhexa((to_hex % 16), s);
	}
	if (to_hex < 16)
		ft_printchar(hexbase[to_hex]);
	return (ft_lencount(to_hex));
}
/*
int	main(void)
{
	ft_printhexa(0, 'X');
	write(1, "\n", 1);
	ft_printhexa(-1, 'x');
	write(1, "\n", 1);
	ft_printhexa(1, 'x');
	write(1, "\n", 1);
	ft_printhexa(9, 'x');
	write(1, "\n", 1);
	ft_printhexa(11, 'x');
	return (0);
}*/
