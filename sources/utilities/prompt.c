/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:49:58 by pfalasch          #+#    #+#             */
/*   Updated: 2023/12/23 17:05:00 by mcoppola         ###   ########.fr       */
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
