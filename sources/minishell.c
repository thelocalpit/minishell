/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:33:28 by asacchin          #+#    #+#             */
/*   Updated: 2024/03/01 13:04:24 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_sig_val;

void	init_main(int ac, char **av, char **envp, t_attr *att)
{
	(void)ac;
	(void)av;
	att->value = 0;
	g_sig_val = 0;
	att->list_index = 0;
	att->i_flag_dol = 0;
	att->list_flag = 0;
	rl_clear_history();
	set_signal();
	att->i_flag_dol = 0;
	init_attr(att);
	att->env_list = copy_env_in_list(envp);
	add_index_env_list(att);
	att->local_list = NULL;
}

void	while_main(char *s, t_attr *att)
{
	while (att->split_array[att->y] && !check_readline(s, att))
	{
		check_next_step(att);
		cmd_matrix(att->split_array[att->y], att);
		att->value = builtin_exec(att);
		add_index_custom_env(att);
		if (att->local_list != NULL)
			add_index_local_list(att);
		free_matrix2(att->array2, att);
		if (!att->split_array[att->y + 1])
			break ;
		att->y += 2;
	}
}

void	utils_main(char *s, t_attr *att)
{
	add_history(s);
	init_split(s, att);
	att->y = 0;
	if (counter_pipes(att))
		init_pipes(att);
	while_main(s, att);
	free_matrix(att->split_array);
	if (att->pipes_num != 0)
		delete_matrix(att->pipes_fd);
	free(s);
}

int	main(int ac, char **av, char **envp)
{
	char	*s;
	t_attr	att;

	init_main(ac, av, envp, &att);
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
			att.value = 130;
		reinit_params(&att);
		if (s && ft_is_space(s))
			utils_main(s, &att);
	}
	return (0);
}
