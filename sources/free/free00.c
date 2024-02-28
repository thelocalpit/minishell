/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:44:06 by mcoppola          #+#    #+#             */
/*   Updated: 2024/02/28 15:05:35 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Frees the memory allocated for the environment list.
 *
 * This function iterates through the environment list and frees the memory
 * allocated for each node and its content. It also updates the environment
 * list pointer to the next node until all nodes are freed.
 *
 * @param att The attribute structure containing the environment list.
 */
void	free_env_list(t_attr *att)
{
	t_list	*temp;

	while (att->env_list)
	{
		temp = att->env_list;
		free(att->env_list->content);
		att->env_list = att->env_list->next;
		free(temp);
	}
}

/**
 * @brief Deletes a dynamically allocated matrix.
 *
 * This function frees the memory allocated for a matrix, including its rows
 * and columns. The matrix is assumed to be a dynamically allocated 2D array
 * of strings.
 *
 * @param matrix The matrix to be deleted.
 */
void	delete_matrix(void *matrix)
{
	int	c;

	c = -1;
	while (((char **)matrix)[++c])
		free(((char **)matrix)[c]);
	free(matrix);
}

/**
 * @brief Frees a dynamically allocated matrix and its contents.
 *
 * This function frees a matrix of strings and its contents. It takes as input
 * the matrix to be freed and a pointer to a structure containing additional
 * attributes. The function iterates over each row of the matrix and frees the
 * corresponding string. Finally, it frees the matrix itself.
 *
 * @param matrix The matrix to be freed.
 * @param att    Pointer to a structure containing additional attributes.
 */
void	free_matrix2(char **matrix, t_attr *att)
{
	int	c;

	c = 0;
	while (c < att->words_counter)
		free(matrix[c++]);
	free(matrix);
}

/**
 * @brief Frees a dynamically allocated matrix.
 *
 * This function frees the memory allocated for a matrix of strings.
 * It first frees each individual string in the matrix, and then frees the
 * matrix itself.
 *
 * @param matrix The matrix to be freed.
 */
void	free_matrix(char **matrix)
{
	int	c;

	c = 0;
	while (matrix[c])
		free(matrix[c++]);
	free(matrix);
}

/**
 * @brief Frees the memory allocated for the local_list in the t_attr
 * structure.
 *
 * This function iterates through the local_list and frees the memory allocated
 * for each node's content.
 *
 * @param att The t_attr structure containing the local_list to be freed.
 */
void	free_local_list(t_attr *att)
{
	while (att->local_list)
	{
		free(att->local_list->content);
		att->local_list = att->local_list->next;
	}
}
