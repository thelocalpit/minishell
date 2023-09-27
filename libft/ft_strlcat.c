/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:25 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:37:27 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	i;
	size_t	dstlng;
	size_t	srclng;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	dstlng = ft_strlen(dst);
	srclng = ft_strlen(src);
	j = dstlng;
	if (j >= size)
		return (srclng + size);
	while (i < (size - dstlng - 1) && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dstlng + srclng);
}
/*
int	main(void)
{
//	char	str1[] = "Luis";
//	char	str2[] = "Eduardo";
	char	b[0xF] = "nigh !";
	printf("%zu\n", ft_strlcat(((void *)0), b, 0));
//	printf("%zu\n", ft_strlcat(str1, str2, 13));
//	puts(str1);
}*/
