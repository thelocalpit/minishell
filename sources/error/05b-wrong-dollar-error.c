/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05b-wrong-dollar-error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:15:44 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/23 12:25:39 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dollar_error_2_a(char *c, int *j, int *n)
{
	while (c[*j] != '"' && c[*j] != '\'' && c[*j] != ' ' && c[*j])
	{
		(*j)++;
		(*n)++;
		if (c[*j] == '$')
			break ;
	}
}

void	dollar_error_2_b(char *envp_check, int *n, int *c, t_attr *strc)
{
	envp_check[*n] = '=';
	envp_check[*n + 1] = '\0';
	c += 1;
	strc->y_mtx_envp = 0;
	strc->xmnvp = *c;
}

int	dollar_error_2(char *c, int a, t_attr *strc)
{
	int		n;
	char	*envp_check;
	int		b;
	int		inizio;

	n = 0;
	b = 0;
	a++;
	inizio = a;
	if (c[a] == '?')
		return (1);
	dollar_error_2_a(c, &a, &n);
	envp_check = malloc(sizeof(char) * n + 2);
	a = inizio;
	while (b < n)
		envp_check[b++] = c[a++];
	dollar_error_2_b(envp_check, &b, &n, strc);
	if (dollar_error_3(envp_check, strc, n) == 1)
	{
		free(envp_check);
		return (1);
	}
	free(envp_check);
	return (n - 1);
}
