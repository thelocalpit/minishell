/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:24:47 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/18 20:03:21 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		i;

	i = 0;
	sdup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sdup)
		return (NULL);
	while (s[i])
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = 0;
	return (sdup);
}
