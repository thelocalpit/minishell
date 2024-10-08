/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   localvar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:09:39 by deggio            #+#    #+#             */
/*   Updated: 2024/02/16 18:25:11 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	add_var(char *str, t_attr *att)
{
	int		skip;
	int		add;
	int		empty;
	char	*name;

	skip = 0;
	add = 0;
	empty = 0;
	name = get_var_name(str);
	if (str[ft_strlen(name)] == '+')
		add = 1;
	if (!str[ft_strlen(name) + 1] || ((!str[ft_strlen(name) + 2]) && add))
		empty = 1;
	if (update_var(str, att->local_var, add))
		skip = 1;
	if (update_var(str, att->env_list, add))
		skip = 1;
	if (!skip)
		new_var(str, att, add, empty);
	free(name);
	return (0);
}

int	update_var(char *str, t_list *list, int add)
{
	t_list	*tmp;
	char	*temp;

	tmp = list;
	while (tmp)
	{
		if (!ft_strncmp(str, tmp->content, var_name_length(str)))
		{
			if (!add)
			{
				free(tmp->content);
				tmp->content = var_no_content_quote(str);
				return (1);
			}
			temp = ft_strjoin(tmp->content,
				str + var_name_length(str) + 2);
			free(tmp->content);
			tmp->content = var_no_content_quote(temp);
			free(temp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	new_var(char *str, t_attr *att, int add, int empty)
{
	t_list	*tmp;
	char	*name;
	char	*temp;

	name = get_var_name(str);
	if (add && empty)
	{
		free(str);
		str = ft_strjoin(name, "=");
	}
	else if (add && !empty)
	{
		temp = ft_strjoin(name, str + ft_strlen(name) + 1);
		free(str);
		str = var_no_content_quote(temp);
		free(temp);
	}
	tmp = att->local_var;
	tmp = ft_lstnew(var_no_content_quote(str));
	// da capire se va lasciato perche in questa funzione ce un leak
	// if (add && !empty)
	// 	free(str);
	if (!tmp)
		ft_putstr_fd("malloc", 2);
	ft_lstadd_back(&att->local_var, tmp);
	free(name);
	return (0);
}
