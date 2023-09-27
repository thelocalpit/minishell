/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chck.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:28:49 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:28:51 by pfalasch         ###   ########.fr       */
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
