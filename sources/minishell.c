/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/24 18:10:46 by pfalasch         ###   ########.fr       */
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
			att.cmd_arr = split_init(s, &att);
			printf("questo è il numero di token: %d\n", att.nb_tokens);
			ft_print_array(att.cmd_arr);
			while (att.cmd_arr[att.y] && att.cmd_arr[att.y][0] != '\0' 
				&& !verify_readline(s))
			{
				// printf("sono detro al loop\n");
				// printf("questo è il numero di att.i %d\n", att.i);

				get_cmd_matrix(att.cmd_arr[att.y], &att);
				printf("questo è il numero dei token nella line singola: %d\n", att.count_words);
				// printf("questo è la matrice post: \n");
				// ft_print_array(att.s_line_arr);
				// free_tokens(att.s_line_arr, &att);
				if (att.cmd_arr[att.y + 1][0] == '\0')
					break ;
				att.y = att.y + 2;
			}
			reinit_parameters(&att, envp);
		}
		// free(s);
	}
	return (0);
}
