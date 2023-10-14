/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/13 18:42:35 by pfalasch         ###   ########.fr       */
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
		if (s && !verify_readline(s))
		{
			add_history(s);
			att.cmd_arr = split_init(s, &att);
			// verify_readline(s);
		
			printf("questo è il numero di token: %d\n", att.nb_tokens);
			ft_print_array(att.cmd_arr);
			reinit_parameters(&att, envp);
		}
		// free(s);
	}
	return (0);
}