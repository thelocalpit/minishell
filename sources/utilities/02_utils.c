/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 21:26:11 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/16 19:56:30 by mcoppola         ###   ########.fr       */
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
		return (full_var);
	return (++p);
}
