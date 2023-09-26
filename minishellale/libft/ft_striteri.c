/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:01:38 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/14 17:11:34 by lde-sous         ###   ########.fr       */
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
