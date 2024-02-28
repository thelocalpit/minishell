/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:32:10 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 13:32:11 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Concatenates the string pointed to by src to the end of the string
 * pointed to by dest.
 *
 * @param dest The destination string where the concatenated string will be
 * stored.
 * @param src The source string to be concatenated.
 * @return A pointer to the destination string.
 */
char	*ft_strcat(char *dest, const char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr)
		ptr++;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

/**
 * @brief Copies the first n characters of the source string to the destination
 * string. If the length of the source string is less than n, the remaining
 * characters in the destination string are filled with null terminators.
 *
 * @param dest The destination string where the copied characters will be
 * stored.
 * @param src The source string from which the characters will be copied.
 * @param n The maximum number of characters to be copied.
 * @return The pointer to the destination string.
 */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * @brief Compare two strings lexicographically.
 *
 * This function compares the two strings str1 and str2 lexicographically.
 * It returns an integer value less than, equal to, or greater than zero
 * if str1 is found, respectively, to be less than, to match, or be greater
 * than str2.
 *
 * @param str1 The first string to be compared.
 * @param str2 The second string to be compared.
 * @return An integer less than, equal to, or greater than zero if str1 is
 * found, respectively, to be less than, to match, or be greater than str2.
 */
int	ft_strcmp(const char *str1, const char *str2)
{
	int	c;

	c = 0;
	if (!str1[c] || !str2[c])
		return (2);
	while (str1[c] || str2[c])
	{
		if (str1[c] == str2[c])
			c++;
		else if (str1[c] > str2[c])
			return (1);
		else if (str2[c] > str1[c])
			return (-1);
	}
	return (0);
}
