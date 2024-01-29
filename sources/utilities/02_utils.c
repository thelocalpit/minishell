/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:26:11 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/29 16:35:40 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @return the content of the variable
 * @param char* full_var: the variable with the content
 * @example: "VAR=content" -> "content"
*/
char	*get_var_content(char *full_var)
{
	char	*p;

	p = ft_strchr(full_var, '=');
	if (!p)
		return ("");
	return (++p);
}

char    *removePlus(char *full_var)
{
	char    *name;
	char	*varName;

	varName = get_var_name(full_var);
	name = ft_strjoin(varName, ft_strchr(full_var, '='));
	free(varName);
	return (name);
}

int	var_name_length(char *full_var)
{
	char	*p;
	int		var_name_length;

	p = ft_strchr(full_var, '=');
	if (p)
		var_name_length = ft_strlen(full_var) - ft_strlen(p);
	else
		var_name_length = ft_strlen(full_var);
	if (full_var[var_name_length - 1] == '+')
		var_name_length--;
	return (var_name_length);
}
