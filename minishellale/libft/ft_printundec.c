/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printundec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:46:35 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/15 16:56:38 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printundec(unsigned int decimal)
{
	int	count;

	count = 0;
	if (decimal >= 10)
	{
		count += ft_printundec(decimal / 10);
		decimal = (decimal % 10);
	}
	if (decimal < 10)
		count += ft_printchar(decimal + '0');
	return (count);
}
/*
int	main(void)
{
	unsigned int	test;

	test = -712310;
	ft_printundec(test);
	write(1, "\n", 1);
	printf("%u\n", test);
	return (0);
}*/
