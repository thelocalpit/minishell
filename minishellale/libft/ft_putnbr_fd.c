/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:56:17 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/14 21:10:34 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = (unsigned int)(n * -1);
	}
	else
		number = (unsigned int)n;
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd((char)(number % 10 + '0'), fd);
}
