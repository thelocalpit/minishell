/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   localvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:09:39 by deggio            #+#    #+#             */
/*   Updated: 2024/01/23 21:38:04 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	add_var(char *str, t_attr *att)
{
	t_list	*tmp;
	//t_list	*tmp2;
	char	*name;

	tmp = att->local_var;
	//tmp2 = att->env_list;
	name = get_var_name(str);
	if (!str[ft_strlen(name) + 1])
		free(str);
	if (!str)
		str = ft_strjoin(name, "=\"\"");
	free(name);
	while (tmp)
	{
		if (!ft_strcmp(get_var_name(str), get_var_name(tmp->content)))
		{
			free(tmp->content);
			tmp->content = ft_strdup(str);
			return (0);
		}
		tmp = tmp->next;
	}
	tmp = ft_lstnew(ft_strdup(str));
	if (!tmp)
		perror("malloc");
	ft_lstadd_back(&att->local_var, tmp);
	return (0);
}
