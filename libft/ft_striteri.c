/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:37:14 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:37:16 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

/*void	experimental_func(unsigned int i, char *s)
{
	i = 0;
	while (s[i])
	{
		s[i] = 'a';
		i++;
	}
}

int	main(void)
{
	char	str[] = "This is Sparta!";
	ft_striteri(str, experimental_func);

	printf("%s\n", str);
	return (0);
}*/
