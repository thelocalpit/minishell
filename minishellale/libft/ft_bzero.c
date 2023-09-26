/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:46:43 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/08 20:29:47 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n)
	{
		*(char *)s = '\0';
		n--;
		s++;
	}
}
/*
int	main(void)
{
	char	str[] = "You know nothin";
	char	str2[] = "You know nothin";

	ft_bzero(&str[2], 10);
	puts(str);
	bzero(&str2[2], 10);
	puts(str2);
	return (0);
}*/
