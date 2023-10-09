/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/09 19:10:19 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* int	g_value;

g_value = 0; */

int	main(int ac, char **av, char **envp)
{
	char	*s;
	t_attr	att;

	(void)ac;
	(void)av;
	(void)envp;

	rl_clear_history();
	set_signals();
	init_parameters(&att, envp);
	while (1)
	{
		s = prompt();
		if (s == NULL)
		{
			rl_clear_history();
			break ;
		}
		if (s)
		{
			add_history(s);
			count_tokens(s, &att);
			printf("questo è il numero di token: %d", att.nb_tokens);
			reinit_parameters(&att, envp);
		}
	}
	return (0);
}