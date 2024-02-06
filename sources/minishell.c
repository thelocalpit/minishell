/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/05 20:41:25 by deggio           ###   ########.fr       */
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
	att.i_flag$ = 0;
	att.flag_list = 0;
	rl_clear_history();
	set_signals();
	att.i_flag$ = 0;
	init_parameters(&att);
	// questo è l'init del env per il momento fatto cosi, poi va sistemato dove volete voi
	// e va sostituito ovunque, per il momento lo aggiungo come parametro in piu dove
	// serve a me e ricordiamoci di freearlo (Marco)
	att.env_list = copy_env_in_list(envp);
	add_index_to_env_list(&att);
	att.local_var = NULL;
	// printlist(&att);
	while (1)
	{
		s = prompt();
		if (s == NULL)
		{
			rl_clear_history();
			break ;
		}
		reinit_parameters(&att, envp);
		//start_env(envp, &att);

		if (s && ft_isspace(s))
		{
			add_history(s);
			split_init(s, &att);
			//ft_print_array(att.split_arr);
			att.y = 0;
			if (count_pipes(&att))
				init_pipes(&att);
			while (att.split_arr[att.y] && !verify_readline(s, &att))
			{
				printf("att.y = %d\n", att.y);
				check_next_step(&att);
				get_cmd_matrix(att.split_arr[att.y], &att); //IL PROBLEMA È QUIO CIRCA PORCO DIOSTO CON MARCO E SMADONMNO
				// ft_print_array(att.arr2);
				do_builtin(&att);
				add_index_to_custom_env(&att);
				if (att.local_var != NULL)
					add_index_to_local_var(&att);
				// command(&att);
				free_arr2(att.arr2, &att);
				if (!att.split_arr[att.y + 1])
					break ;
				printf("att.y = %d\n", att.y);
				att.y += 2;
				printf("att.y = %d\n", att.y);
				// if (att.flag$ && att.save_y_mx_envp)
				// {
				// 	free(att.flag$);
				// 	free(att.save_y_mx_envp);						// DA RISOLVERE
				// }
			}
			free_arr(att.split_arr);
			if (att.nb_pipes != 0)
				ft_delete_matrix(att.pipesfd);

			free(s);
		}
	}
	return (0);
}
