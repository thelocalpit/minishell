/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04a_error_messages.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:22:38 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:16:03 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	not_found_command(char *src)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(src, 2);
	ft_putstr_fd(": command not found\n", 2);
}

void	reader_file_error(t_attr *strct, char *src)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(src, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
	strct->value = 1;
	strct->skip = 1;
}

int	error_exit(char *c, t_attr *strct)
{
	printf("exit: %s: numeric argument required\n", c);
	strct->value = 2;
	return (strct->value);
}
