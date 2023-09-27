/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:28:36 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:28:39 by pfalasch         ###   ########.fr       */
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
