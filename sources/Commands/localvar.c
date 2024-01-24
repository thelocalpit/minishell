/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   localvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:09:39 by deggio            #+#    #+#             */
/*   Updated: 2024/01/24 04:42:54 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	add_var(char *str, t_attr *att)
{
	int		skip;
	t_list	*tmp;
	char	*name;

	skip = 0;
	tmp = att->local_var;
	name = get_var_name(str);
	if (!str[ft_strlen(name) + 1])
		free(str);
	if (!str)
		str = ft_strjoin(name, "=\"\"");
	free(name);
	if (update_var(str, att->local_var))
		skip = 1;
	if (update_var(str, att->env_list))
		skip = 1;
	if (!skip)
	{
		tmp = ft_lstnew(ft_strdup(str));
		if (!tmp)
			perror("malloc");
		ft_lstadd_back(&att->local_var, tmp);
	}
	return (0);
}

int	update_var(char *str, t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (!ft_strcmp(get_var_name(str), get_var_name(tmp->content)))
		{
			free(tmp->content);
			tmp->content = ft_strdup(str);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
