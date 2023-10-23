/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:49:58 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/22 17:14:21 by pfalasch         ###   ########.fr       */
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
		printf("┏━" GREEN_BOLD " %s@:" GREEN_BOLD, user);
		printf(CYAN_BOLD "%s\n" CYAN_BOLD, pwd);
	}
	str = readline(RESET "┗━" RED_BOLD " minihell" RED_BOLD " " RESET "");
	return (str);
}