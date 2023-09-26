/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:46:17 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/15 14:18:09 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnum(long num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = (num * -1);
		count++;
	}
	if (num >= 10)
	{
		count += ft_printnum(num / 10);
		num = (num % 10);
	}
	if (num < 10)
	{
		count += ft_printchar(num + '0');
	}
	return (count);
}
/*
int	main(void)
{
	long	numa;
	long	numb;
	long	numc;
	long	numd;
	long	nume;

	numa = -34;
	numb = 0;
	numc = 5;
	numd = -95555555555550000;
	nume = 6666666666660000;
	ft_printnum(numa);
	write(1, "\n", 1);
	ft_printnum(numb);
	write(1, "\n", 1);
	ft_printnum(numc);
	write(1, "\n", 1);
	ft_printnum(numd);
	write(1, "\n", 1);
	ft_printnum(nume);
	return (0);
}*/
