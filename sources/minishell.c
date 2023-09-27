/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/27 11:43:58 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* int	g_value;

g_value = 0; */

int	main(int ac, char **av, char **envp)
{
	char	*str;

	(void)ac;
	(void)av;
	(void)envp;

	rl_clear_history();
	set_signals();
	while (1)
	{
		str = prompt();
		if (str == NULL)
		{
			rl_clear_history();
			break ;
		}
		if (str);
		{
			add_history(str);
		}
	}
	return (0);
}