/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesac <alesac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/26 12:47:53 by alesac           ###   ########.fr       */
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
			do_builtin(att.cmd_arr,(char **) envp);
			// while (att.cmd_arr[att.i] && att.cmd_arr[att.i][0] != '\0')
			// {
			// 	printf("sono detro al loop");
			// 	att.i++;
			// 	get_cmd_matrix(att.cmd_arr[att.i], &att);
			// 	printf("questo è la matrice post: \n");
			// 	ft_print_array(att.matrix_single_cmd);
			// 	free_tokens(att.matrix_single_cmd, &att);
			// 	if (att.cmd_arr[att.i + 1])
			// 		break ;
			// 	att.i = att.i + 2; 
			// }
			reinit_parameters(&att, envp);
		}
		// free(s);
	}
	return (0);
}
