/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:02:57 by lde-sous          #+#    #+#             */
/*   Updated: 2023/02/15 18:03:50 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t	ft_cstrlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_mod(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == 0)
		return (&str[ft_strlen(str)]);
	while (str[i])
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*str_join_mod(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*jointstr;

	if (!str1)
	{
		str1 = malloc(sizeof(char));
		str1[0] = 0;
	}
	if (!str1 && !str2)
		return (NULL);
	jointstr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!jointstr)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		jointstr[i++] = str1[j++];
	j = 0;
	while (str2[j])
		jointstr[i++] = str2[j++];
	jointstr[ft_strlen(str1) + ft_strlen(str2)] = 0;
	free(str1);
	return (jointstr);
}

/* main para testar str_join_mod
int	main(void)
{
	char	s1[] = "This is ";
	char	s2[] = "A TESSTTT!!!!!";
	printf("%s", "s1 = ");
	printf("%s\n", s1);
	printf("%s", "s2 = ");
	printf("%s\n\n", s2);
	printf("%s", "str_join_mod = ");
	printf("%s\n", str_join_mod(s1, s2));
	return (0);
}*/
