/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_error_messages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:45:30 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 11:52:52 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	return_not_required(t_attr *att)
{
	printf("command not required by subject\n");
	att->g_value = 2;
	return (1);
}

int	return_pipe_error(t_attr *att)
{
	printf("parse error near `|'\n");
	att->g_value = 2;
	return (1);
}

int	return_gt_error(t_attr *att)
{
	printf("parse error near `>'\n");
	att->g_value = 2;
	return (1);
}

int	return_lt_error(t_attr *att)
{
	printf("parse error near `<'\n");
	att->g_value = 2;
	return (1);
}

int return_nl_error(t_attr *att)
{
	printf("syntax error near unexpected token 'newline'\n");
	att->g_value = 2;
	return (1);
}
