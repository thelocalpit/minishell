/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_a_error_messages.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:22:38 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/22 18:23:48 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int exit__err(char *str)
{
	printf("exit: %s: numeric argument required\n", str);
	g_value = 2;
	return (g_value);
}
