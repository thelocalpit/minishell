/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:30:32 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:30:34 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}
/*
int	main(void)
{
	char	str[] = "Lets test this";
	t_list	*testl;

	printf("%s", "str = ");
	printf("%s\n", str);
	testl = ft_lstnew((void *)str);
	printf("%s", "ft_lstnew((void *)str) = ");
	printf("%s\n", (char *)testl->content);
	return (0);
}*/
