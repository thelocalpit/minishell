/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:38:12 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:38:14 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(char const c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*temp;
	int		i;
	int		init;
	int		end;

	i = 0;
	init = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[init] && checker(s1[init], set))
		init++;
	while (end > init && checker(s1[end - 1], set))
		end--;
	temp = (char *)(malloc(sizeof(char) * (end - init + 1)));
	if (!temp)
		return (NULL);
	while (init != end)
		temp[i++] = s1[init++];
	temp[i] = '\0';
	return (temp);
}
/*
int	main(void)
{
	char	str[] = "bugIs strange!gub";
	char	totrim[] = "bug";
	printf("%s\n", ft_strtrim(str, totrim));
	return (0);
}*/
