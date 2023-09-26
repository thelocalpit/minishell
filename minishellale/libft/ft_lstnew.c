/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:34:05 by lde-sous          #+#    #+#             */
/*   Updated: 2022/11/16 16:51:48 by lde-sous         ###   ########.fr       */
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
