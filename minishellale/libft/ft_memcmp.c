/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:16:53 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/10 18:10:16 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ns1;
	unsigned char	*ns2;

	ns1 = (unsigned char *)s1;
	ns2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (ns1[i] != ns2[i])
			return (ns1[i] - ns2[i]);
		i++;
		n--;
	}
	return (0);
}
/*
int	main(void)
{
	char	a[] = "only another BIG test";
	char	b[] = "only 1nother test";
	printf("%d\n", ft_memcmp(a, b, 7));
}*/
