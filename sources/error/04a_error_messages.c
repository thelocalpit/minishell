/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04a_error_messages.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deggio <deggio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:22:38 by pfalasch          #+#    #+#             */
/*   Updated: 2024/02/09 20:11:04 by deggio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int exit__err(char *str)
{
	printf("exit: %s: numeric argument required\n", str);
	g_value = 2;
	return (g_value);
}

void	read_file_error(t_attr *att, char *file)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	g_value = 1;
	att->skip = 1;
}

void	command_not_found(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}
