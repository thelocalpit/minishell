/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:31:18 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:31:21 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest2;
	const char		*src2;

	dest2 = dest;
	src2 = src;
	if (!dest && !src)
		return (NULL);
	if (src < dest)
	{
		while (n--)
			dest2[n] = src2[n];
	}
	else
		while (n--)
			*dest2++ = *src2++;
	return (dest);
}
/*
int	main(void)
{
	char	a[] = "123456789";
	char	b[] = "may tests";

	printf("%s\n", (unsigned char *)ft_memmove(a, b + 2, 8));
	printf("%s\n", (unsigned char *)memmove(a, b + 2, 8));
	return (0);
}*/
