/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotavare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:55:06 by lde-sous          #+#    #+#             */
/*   Updated: 2023/06/20 06:18:46 by jotavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_delimiter(char c, char *delims)
{
	int	i;

	i = 0;
	while (delims[i])
	{
		if (delims[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_mod(char *str, char *delims)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_delimiter(str[i], delims))
		i++;
	return (i);
}

char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(n + 1);
	if (dup == NULL)
		return (NULL);
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_wordcount(char *str, char *delims)
{
	int	i;
	int	len;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && ft_is_delimiter(str[i], delims))
			i++;
		len = ft_strlen_mod(str + i, delims);
		if (len > 0)
			words++;
		i += len;
	}
	return (words);
}

char	**ft_split_set(char *str, char *charset)
{
	int		i;
	int		k;
	int		len;
	char	**words;

	k = 0;
	i = 0;
	words = (char **)malloc((ft_wordcount(str, charset) + 1) * sizeof(char *));
	if (words == NULL || str == NULL || charset == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_is_delimiter(str[i], charset))
			i++;
		len = ft_strlen_mod(str + i, charset);
		if (len > 0)
			words[k++] = ft_strndup(str + i, len);
		i += len;
	}
	words[k] = NULL;
	return (words);
}
