/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:16:28 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/02 11:32:08 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	j;

	j = 0;
	if ((start > ft_strlen(s)) || (!s) || (len == 0))
	{
		sub = (char *)malloc(sizeof(char) * 1);
		sub[0] = 0;
		return (sub);
	}
	else
	{
		if (len >= ft_strlen(s))
			len = ft_strlen(s) - start;
		sub = (char *)malloc(sizeof(char) * (len + 1));
		if (!sub)
			return (NULL);
		while (j < ft_strlen(s) && len > 0)
		{
			sub[j++] = s[start++];
			len--;
		}
		sub[j] = 0;
	}
	return (sub);
}
/*
int	main(void)
{
	const char	str[] = "This is a test";
	unsigned int	i;
	size_t		size;
	char	*lolo;

	i = 5;
	size = 11;
	lolo = ft_substr(str, i, size);
	puts(lolo);
	free(lolo);
	return (0);
}*/
