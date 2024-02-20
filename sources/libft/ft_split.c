/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:36:56 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 12:10:37 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_stringcounterer(const char *s, char c)
{
	int	i;
	int	nstrings;

	i = ft_strlen(s) - 1;
	nstrings = 0;
	while (i >= 0)
	{
		if (s[i] != c)
		{
			nstrings++;
			while (i > 0 && s[i] != c)
				i--;
		}
		if (s[i] == c)
			i--;
		if (i == 0)
			break ;
	}
	return (nstrings);
}

static int	ft_strlentoc(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		o;
	int		nofstrs;

	o = 0;
	if (!s)
		return (NULL);
	nofstrs = ft_stringcounterer(s, c);
	result = malloc(sizeof(char *) * (nofstrs + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			result[o++] = ft_substr(s, 0, ft_strlentoc(s, c));
		while (*s && *s != c)
			s++;
	}
	result[o] = 0;
	return (result);
}
/*
int	main(void)
{
	char	*c = "s_ola___os_meu_nome_e_luis_";
	char	s = 's';
	int	i = 0;
	char	**temp;
	temp = ft_split(c, s);
	while (temp[i])
	{
		printf("%s\n", temp[i]);
		i++;
	}
}*/
