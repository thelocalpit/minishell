/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:26:11 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/16 18:19:28 by pfalasch         ###   ########.fr       */
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
	int		p_len;

	p = ft_strchr(full_var, '=');
	if (!p)
		return ("");
	p++;
	p_len = ft_strlen(p);

	if (*p == '\"' && p[p_len - 1] == '\"')
	{
		p[p_len - 1] = '\0';
		p++;
	}
	return (p);
}

char	*removeplus(char *full_var)
{
	char	*name;
	char	*varname;

	varname = get_var_name(full_var);
	name = ft_strjoin(varname, ft_strchr(full_var, '='));
	free(varname);
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

/**
 * Return the variable string without the  quote ("") on the content
 *
 * ex1: ciao="pippo" => ciao=pippo
 * ex2: prova=casa   => prova=casa
*/
char	*var_no_content_quote(char *str)
{
	char	*new_str;
	char	*tmp;
	char	*var_name;

	var_name = get_var_name(str);

	tmp = ft_strjoin(var_name, "=");
	new_str = ft_strjoin(tmp, get_var_content(str));
	free(tmp);
	free(var_name);
	return (new_str);
}
