/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesac <alesac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:49:58 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/26 20:44:03 by alesac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* con questa funzione andiamo a prenderci l'user e il pwd.
	poi printiamo un custom prompt */

char	*prompt(void)
{
	char	*str;
	char	*user;
	char	*pwd;

	user = getenv("USER");
	pwd = getenv("PWD");
	if (pwd != NULL && user != NULL)
	{
		printf(RESET"┏━" GREEN_BOLD " %s@:" GREEN_BOLD, user);
		printf(CYAN_BOLD "%s\n" CYAN_BOLD, pwd);
	}
	str = readline(RESET "┗━" RED_BOLD " minihell" RED_BOLD " " RESET "");
	return (str);
}