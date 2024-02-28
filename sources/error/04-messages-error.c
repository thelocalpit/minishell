/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_error_messages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:30 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:00:50 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	nl_error(t_attr *strct)
{
	printf("syntax error near unexpected token 'newline'\n");
	strct->value = 2;
	return (1);
}

int	pipe_error(t_attr *strct)
{
	printf("parse error near `|'\n");
	strct->value = 2;
	return (1);
}

int	not_required(t_attr *strct)
{
	printf("command not required by subject\n");
	strct->value = 2;
	return (1);
}

int	gt_error(t_attr *strct)
{
	printf("parse error near `>'\n");
	strct->value = 2;
	return (1);
}

int	lt_error(t_attr *strct)
{
	printf("parse error near `<'\n");
	strct->value = 2;
	return (1);
}
