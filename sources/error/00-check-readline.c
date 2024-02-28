/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00-check-readline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:00:05 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:23:04 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	negative_return(t_attr *strct)
{
	strct->value = 2;
	return (1);
}

int	check_readline(char *src, t_attr *strct)
{
	if (end_error(src, '>', strct) || end_error(src, '<', strct)
		|| end_error(src, '|', strct))
		return (negative_return(strct));
	else if (begin_error_2(src, strct))
		return (negative_return(strct));
	else if (quotes_counter(src))
		return (negative_return(strct));
	else if (begin_error(src, strct))
		return (negative_return(strct));
	else if (mixed_error_start(src, strct))
		return (negative_return(strct));
	else if (dollar_error(src, strct))
		return (negative_return(strct));
	return (0);
}
