/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:32:47 by mcoppola          #+#    #+#             */
/*   Updated: 2024/03/07 17:33:22 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Calculates the length of a matrix (array of strings).
 *
 * @param matrix The matrix to calculate the length of.
 * @return The length of the matrix.
 */
int	matrix_len(char **matrix)
{
	int	len;

	len = 0;
	while (matrix[len])
		len++;
	return (len);
}

/**
 * @brief Converts the environment variables stored in the linked list
 * `env_list` to a matrix `env`. The matrix `env` is allocated dynamically
 * and contains copies of the environment variables. The last element of the
 * matrix `env` is set to NULL.
 *
 * @param att The attribute structure containing the environment variables.
 */
void	env_to_matrix(t_attr *att)
{
	int		c;
	t_list	*temp_list;

	c = 0;
	temp_list = att->env_list;
	att->env = malloc(sizeof(char *) * ft_lstsize(temp_list) + 1);
	temp_list = att->env_list;
	while (temp_list)
	{
		att->env[c] = ft_strdup(temp_list->content);
		c++;
		temp_list = temp_list->next;
	}
	att->env[c] = NULL;
}

/**
 * @brief Checks if a character is a whitespace character (space or tab).
 *
 * @param s The character to check.
 * @return 1 if the character is a whitespace character, 0 otherwise.
 */
int	ft_is_space(char *s)
{
	int	c;

	c = 0;
	while (s[c])
	{
		if (s[c] == ' ' || s[c] == '\t' || s[c] == '\n'
			|| s[c] == '\f' || s[c] == '\r')
		{
			c++;
		}
		else
			return (1);
	}
	return (0);
}

/**
 * @brief Adds an index to each element in the local_list of t_attr structure.
 *
 * This function assigns a unique index to each element in the local_list of
 * the t_attr structure. The index is stored in the dol_flag field of each
 * element.
 *
 * @param att The t_attr structure containing the local_list.
 */
void	add_index_local_list(t_attr *att)
{
	t_list	*temp_list;
	int		c;

	c = 0;
	temp_list = att->local_list;
	while (att->local_list != NULL)
	{
		att->local_list->dol_flag = c;
		att->local_list = att->local_list->next;
		c++;
	}
	att->local_list = temp_list;
}

/**
 * @brief Adds an index to each element in the custom environment list.
 *
 * This function assigns a unique index to each element in the custom
 * environment list. The index is stored in the 'dol_flag' field of each
 * element.
 *
 * @param att The attribute structure containing the custom environment list.
 */
void	add_index_custom_env(t_attr *att)
{
	t_list	*temp_list;
	int		c;

	temp_list = att->env_list;
	c = 0;
	while (att->env_list != NULL)
	{
		att->env_list->dol_flag = c;
		att->env_list = att->env_list->next;
		c++;
	}
	att->env_list = temp_list;
}
