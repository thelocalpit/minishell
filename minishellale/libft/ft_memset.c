/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:58:22 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/08 14:46:52 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*top;

	top = s;
	i = 0;
	while (i < n)
	{
		top[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	int		t;
	char	a[] = "its a test";

	t = 0;

	printf("%s\n", (char *)ft_memset(a, t, 6));
	printf("%s\n", (char *)memset(a, t, 6));
	return (0);
}*/
