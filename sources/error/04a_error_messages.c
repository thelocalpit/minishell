/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04a_error_messages.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:22:38 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/07 18:09:40 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exit__err(char *str)
{
	printf("exit: %s: numeric argument required\n", str);
	g_value = 2;
	return (g_value);
}
