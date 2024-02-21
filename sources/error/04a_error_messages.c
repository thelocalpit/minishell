/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04a_error_messages.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:22:38 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/21 12:19:13 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exit__err(char *str, t_attr *att)
{
	printf("exit: %s: numeric argument required\n", str);
	att->value = 2;
	return (att->value);
}

void	file_error_reader(t_attr *att, char *file)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	att->value = 1;
	att->skip = 1;
}

void	command_not_found(char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}
