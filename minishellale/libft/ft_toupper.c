/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:55:31 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/04 14:40:54 by lde-sous         ###   ########.fr       */
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
