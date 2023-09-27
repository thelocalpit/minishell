/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printundec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:36:04 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:36:06 by pfalasch         ###   ########.fr       */
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
