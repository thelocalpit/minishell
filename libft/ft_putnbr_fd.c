/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:36:22 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:36:25 by pfalasch         ###   ########.fr       */
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
