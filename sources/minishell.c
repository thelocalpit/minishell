/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/28 10:34:41 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_sig_val;

		//	if (!s)
		//	{
		//		ft_exit_custom(&att);
		//		return (0);
		//	}

int	main(int ac, char **av, char **envp)
{
	char	*s;
	t_attr	att;
	// t_list *env_list;

	(void)ac;
	(void)av;
	att.value = 0;
	g_sig_val = 0;
	att.list_index = 0;
	att.i_flag_dol = 0;
	att.list_flag = 0;
	rl_clear_history();
	set_signal();
	att.i_flag_dol = 0;
	init_parameters(&att);
	// questo è l'init del env per il momento fatto cosi, poi va sistemato dove volete voi
	// e va sostituito ovunque, per il momento lo aggiungo come parametro in piu dove
	// serve a me e ricordiamoci di freearlo (Marco)
	att.env_list = copy_env_in_list(envp);
	add_index_env_list(&att);
	att.local_list = NULL;
	// printlist(&att);
	while (1)
	{
		s = prompt();
		if (s == NULL)
		{
			rl_clear_history();
			write(1, "exit\n", 5);
			exit(0);
			return (1);
		}
		g_sig_val = 0;
		if (g_sig_val == SIGINT)
		{
			att.value = 130;
		}
		reinit_parameters(&att, envp);
		//start_env(envp, &att);

		if (s && ft_is_space(s))
		{
			add_history(s);
			init_split(s, &att);
			// ft_print_array(att.split_array);
			att.y = 0;
			if (counter_pipes(&att))
				init_pipes(&att);
			while (att.split_array[att.y] && !check_readline(s, &att))
			{
				check_next_step(&att);
				get_cmd_matrix(att.split_array[att.y], &att); //IL PROBLEMA È QUIO CIRCA PORCO DIOSTO CON MARCO E SMADONMNO
				// ft_print_array(att.array2);
				att.value = builtin_exec(&att);
				add_index_custom_env(&att);
				if (att.local_list != NULL)
					add_index_local_list(&att);
				// command(&att);
				free_array2(att.array2, &att);
				if (!att.split_array[att.y + 1])
					break ;
				att.y += 2;
			}
			free_array(att.split_array);
			if (att.pipes_num != 0)
				ft_delete_matrix(att.pipes_fd);
			free(s);
		}
	}
	return (0);
}
