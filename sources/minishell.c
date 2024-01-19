/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2024/01/19 16:44:20 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_value = 0;

int	main(int ac, char **av, char **envp)
{
	char	*s;
	t_attr	att;
	// t_list *env_list;

	(void)ac;
	(void)av;
	att.index_list = 0;
	rl_clear_history();
	set_signals();
	init_parameters(&att);
	// questo è l'init del env per il momento fatto cosi, poi va sistemato dove volete voi
	// e va sostituito ovunque, per il momento lo aggiungo come parametro in piu dove
	// serve a me e ricordiamoci di freearlo (Marco)
	att.env_list = copy_env_in_list(envp);
	add_index_to_env_list(&att);
	// CREARE LISTA VARIABILI       INIZIALIZZARE A NULL
	att.local_var = NULL;
	printlist(&att);
	while (1)
	{
		s = prompt();
		if (s == NULL)
		{
			rl_clear_history();
			break ;
		}
		reinit_parameters(&att, envp);
		// start_env(envp, &att);

		if (s)
		{
			add_history(s);
			split_init(s, &att);
			//ft_print_array(att.split_arr);
			att.y = 0;
			if (count_pipes(&att))
				init_pipes(&att);
			while (att.split_arr[att.y] && !verify_readline(s, &att))
			{
				check_next_step(&att);
				get_cmd_matrix(att.split_arr[att.y], &att);
				// ft_print_array(att.arr2);
				do_builtin(&att);
				if (att.local_var != NULL)
					add_index_to_local_var(&att);
				// command(&att);
				free_arr2(att.arr2, &att);
				if (!att.split_arr[att.y + 1])
					break;
				att.y += 2;
				if (att.i_flag$ > 0)
					free(att.flag$);
				//free(att.save_y_mx_envp);						// DA RISOLVERE
			}
			//free_arr(att.split_arr);
			// free(att.flag$);
			if (att.nb_pipes != 0)
				ft_delete_matrix(att.pipesfd);

			free(s);
		}
	}
	return (0);
}
