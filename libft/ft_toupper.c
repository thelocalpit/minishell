/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:38:30 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:38:31 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <unistd.h>*/
int	ft_toupper(int x)
{
	if (x > 96 && x < 123)
		x = (x - 32);
	return (x);
}
/*
int	main(void)
{
	char	x;
	char	y;
	char	z;

	x = ft_toupper('a');
	y = ft_toupper('+');
	z = ft_toupper('1');
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, &z, 1);
return (0);
}*/
