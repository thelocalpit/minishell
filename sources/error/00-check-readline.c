/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_verify_readline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:00:05 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:07:52 by mcoppola         ###   ########.fr       */
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
	if (end_error(src, '>', strct) || end_error(src, '<', strct) || end_error(src, '|', strct))
		return (negative_return(strct));
	else if (error_begin_02(src, strct))
		return (negative_return(strct));
	else if (quotes_counter(src))
		return (negative_return(strct));
	else if (begin_error(src, strct))
		return (negative_return(strct));
	else if (error_mixed_start(src, strct))
		return (negative_return(strct));
	else if (error_dollar(src, strct))
		return (negative_return(strct));
	return (0);
}
