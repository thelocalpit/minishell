/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:20 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 11:52:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*allocated;

	if (!s1 || !s2)
		return (NULL);
	allocated = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!allocated)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		allocated[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		allocated[i] = s2[j];
		i++;
		j++;
	}
	allocated[i] = '\0';
	return (allocated);
}
