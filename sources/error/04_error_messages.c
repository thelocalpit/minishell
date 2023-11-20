/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_error_messages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:30 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/20 20:26:44 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int return_not_required(void)
{
	printf("command not required by subject\n");
	return (1);
}
int return_pipe_error(void)
{
	printf("parse error near `|'\n");
	return (1);
}

int return_gt_error(void)
{
	printf("parse error near `>'\n");
	return (1);
}

int return_lt_error(void)
{
	printf("parse error near `<'\n");
	return (1);
}

int return_nl_error(void)
{
	printf("syntax error near unexpected token 'newline'\n");
	return (1);
}