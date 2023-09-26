/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:26:21 by lde-sous          #+#    #+#             */
/*   Updated: 2022/12/15 12:21:40 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_chck(char to_check)
{
	char	*format;
	int		i;

	i = 0;
	format = "csidxXup%";
	while (format[i])
	{
		if (to_check == format[i])
			return (format[i]);
		i++;
	}
	return (0);
}
