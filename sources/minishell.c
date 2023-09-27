/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:11:23 by asacchin          #+#    #+#             */
/*   Updated: 2023/09/27 20:01:09 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_value = 0;

int	main(int ac, char **av, char **envp)
{
	t_attr	att;
	char	*str;

	(void)ac;
	(void)av;
	(void)envp;

	rl_clear_history();
	set_signals();
	while (1)
	{
		str = prompt();
		if (str == NULL)
		{
			rl_clear_history();
			break ;
		}
		if (str)
		{
			add_history(str);
			att.commands_arr = get_tokens(str, &att);
		}
	}
	return (0);
}