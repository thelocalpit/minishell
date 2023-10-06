/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:35:50 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:35:52 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_loncount(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	ft_printaux(unsigned long to_hex)
{
	char	*hexbase;

	hexbase = "0123456789abcdef";
	if (to_hex >= 16)
	{
		ft_printaux(to_hex / 16);
		ft_printaux(to_hex % 16);
	}
	if (to_hex < 16)
		ft_printchar(hexbase[to_hex]);
	return (1);
}

int	ft_printpointer(unsigned long point)
{
	if (!point)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	ft_printaux(point);
	return (ft_loncount(point) + 2);
}
/*
int	main(void)
{
	char	*string;

	string = "qualquer coisa";
	ft_printpointer((unsigned long)string);
	return (0);
}*/
