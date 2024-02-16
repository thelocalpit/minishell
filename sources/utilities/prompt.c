/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:49:58 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/16 18:21:09 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* con questa funzione andiamo a prenderci printiamo un custom prompt */
char	*prompt(void)
{
	char	*str;

	str = readline(RESET "┗━" RED_BOLD " minihell" RED_BOLD " " RESET "");
	return (str);
}
