/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:31:25 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:31:28 by pfalasch         ###   ########.fr       */
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
