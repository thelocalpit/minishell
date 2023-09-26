/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:12:25 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/10 18:20:15 by lde-sous         ###   ########.fr       */
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
