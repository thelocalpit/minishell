/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/19 18:57:29 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* int	g_value;

g_value = 0; */

int	main(int ac, char **av, char **envp)
{
	char	*s;
	t_attr	att;
	t_token toki;

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
			printf("questo è il numero di token: %d\n", att.nb_tokens);
			ft_print_array(att.cmd_arr);
			while (att.cmd_arr[att.i] && att.cmd_arr[att.i][0] != '\0')
			{
				att.matrix_single_cmd = get_cmd_matrix(att.cmd_arr[att.i], &att, &toki);
			}
			reinit_parameters(&att, envp);
		}
		// free(s);
	}
	return (0);
}