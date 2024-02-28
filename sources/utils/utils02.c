/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:32:31 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 13:32:32 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Calculates the length of the variable name in a given string.
 * The variable name is considered to be the substring before the first
 * occurrence of '=' character. If the string ends with '+', the length
 * is adjusted accordingly.
 *
 * @param full_var The string containing the variable name.
 * @return The length of the variable name.
 */
int	var_name_length(char *full_var)
{
	char	*content;
	int		name_length;

	content = ft_strchr(full_var, '=');
	if (content)
	{
		name_length = ft_strlen(full_var) - ft_strlen(content);
	}
	else
	{
		name_length = ft_strlen(full_var);
	}
	if (full_var[name_length - 1] == '+')
	{
		name_length--;
	}
	return (name_length);
}

/**
 * @brief Creates a new string with the variable name and content, without
 * quotes.
 *
 * This function takes a string `str` that represents a variable assignment
 * with quotes, and returns a new string without the quotes. It extracts the
 * variable name using the `get_variable_name` function, and the variable
 * content using the `get_variable_content` function. It then concatenates the
 * variable name, "=", and the variable content to form the new string. Memory
 * is allocated for the new string, which should be freed by the caller when no
 * longer needed.
 *
 * @param str The string representing the variable assignment with quotes.
 * @return A new string without quotes, containing the variable name and
 * content.
 */
char	*var_no_quote_on_content(char *str)
{
	char	*name;
	char	*new_string;
	char	*temp;

	name = get_variable_name(str);
	temp = ft_strjoin(name, "=");
	new_string = ft_strjoin(temp, get_variable_content(str));
	free(name);
	free(temp);
	return (new_string);
}

/**
 * @brief Retrieves the content of a variable from a string in the format
 * "VAR=content". If the variable is not found or the content is empty,
 * an empty string is returned. If the content is enclosed in double quotes,
 *  the quotes are removed.
 *
 * @param full_var The string containing the variable and its content.
 * @return The content of the variable, or an empty string if not found or
 * empty.
 */
char	*get_variable_content(char *full_var)
{
	char	*content;
	int		content_len;

	content = ft_strchr(full_var, '=');
	if (!content)
	{
		return ("");
	}
	content++;
	content_len = ft_strlen(content);
	if (*content == '\"' && content[content_len - 1] == '\"')
	{
		content[content_len - 1] = '\0';
		content++;
	}
	return (content);
}
