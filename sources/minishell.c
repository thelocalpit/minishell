/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/26 18:30:09 by pfalasch         ###   ########.fr       */
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
		reinit_parameters(&att, envp);
		if (s)
		{
			add_history(s);
			split_init(s, &att);
			printf("numero di token: %d\n", att.nb_tokens);
			ft_print_array(att.split_arr);
			att.y = 0;
			while (att.split_arr[att.y] && att.split_arr[att.y][0] != '\0' && !verify_readline(s))
			{
				get_cmd_matrix(att.split_arr[att.y], &att);
				printf("numero dei token nella line singola: %d\n", att.count_words);
				ft_print_array(att.arr2);
				att.y = att.y + 2;
			}
			free_arr(att.split_arr);
			free(s);
		}
		// free(s);
	}
	return (0);
}
