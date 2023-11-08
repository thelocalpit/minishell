/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/08 15:48:33 by pfalasch         ###   ########.fr       */
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
		reinit_parameters(&att, envp);
		if (s)
		{
			add_history(s);
			split_init(s, &att);
			ft_print_array(att.split_arr);
			att.y = 0;
			while (att.split_arr[att.y] && !verify_readline(s))
			{
				get_cmd_matrix(att.split_arr[att.y], &att);
				ft_print_array(att.arr2);
				free_arr2(att.arr2, &att);
				if (!att.split_arr[att.y + 1])
					break;
				att.y += 2;
			}
			free_arr(att.split_arr);
			free(s);
		}
	}
	return (0);
}
