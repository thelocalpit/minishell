/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:33:02 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/22 18:46:46 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	var_update(char *src, t_list *list, int n)
{
	t_list	*clone;
	char	*clone2;

	clone = list;
	while (clone)
	{
		if (!ft_strncmp(src, clone->content, var_name_length(src)))
		{
			if (!n)
			{
				free(clone->content);
				clone->content = var_no_quote_on_content(src);
				return (1);
			}
			clone2 = ft_strjoin(clone->content, src + var_name_length(src) + 2);
			free(clone->content);
			clone->content = var_no_quote_on_content(clone2);
			free(clone2);
			return (1);
		}
		clone = clone->next;
	}
	return (0);
}

int	add_var(char *str, t_attr *att)
{
	int		next;
	int		tot;
	int		clear;
	char	*src;

	next = 0;
	tot = 0;
	clear = 0;
	src = get_variable_name(str);
	if (str[ft_strlen(src)] == '+')
		tot = 1;
	if (!str[ft_strlen(src) + 1] || ((!str[ft_strlen(src) + 2]) && tot))
		clear = 1;
	if (var_update(str, att->local_list, tot))
		next = 1;
	if (var_update(str, att->env_list, tot))
		next = 1;
	if (!next)
		var_new(str, att, tot, clear);
	free(src);
	return (0);
}

int	var_new(char *src, t_attr *strc, int tot, int clear)
{
	char	*name;
	char	*c;
	t_list	*clone;

	name = get_variable_name(src);
	if (tot && clear)
	{
		free(src);
		src = ft_strjoin(name, "=");
	}
	else if (tot && !clear)
	{
		c = ft_strjoin(name, src + ft_strlen(name) + 1);
		free(src);
		src = var_no_quote_on_content(c);
		free(c);
	}
	clone = strc->local_list;
	clone = ft_lstnew(var_no_quote_on_content(src));
	if (!clone)
		ft_putstr_fd("malloc", 2);
	ft_lstadd_back(&strc->local_list, clone);
	free(name);
	return (0);
}
