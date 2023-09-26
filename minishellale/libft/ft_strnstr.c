/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:04:38 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/18 19:59:58 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	o;

	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (big[i] && i < len)
	{
		o = 0;
		while (big[i + o] == little[o]
			&& big[i + o] && little[o] && (i + o) < len)
		{
			if (little[o + 1] == '\0')
				return ((char *)&(big[i]));
			o++;
		}
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "";
	char	s2[] = "hi";

	printf("%s\n", ft_strnstr((void *)0, s2, 0));
	printf("%s\n", strnstr(s1, s2, 5));
	return (0);
}*/
