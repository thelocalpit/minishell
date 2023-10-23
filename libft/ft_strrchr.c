/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:38:07 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:38:08 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i])
	{
		i++;
		str++;
	}
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (str);
		i--;
		str--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "this is a test";

	printf("%s\n", ft_strrchr(str, 105));
	return (0);
}*/
