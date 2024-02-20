/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05a_wrong_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcoppola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:15:44 by asacchin          #+#    #+#             */
/*   Updated: 2024/02/20 13:14:29 by mcoppola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* queste due funzioni servono solamente a ridurre il numero di righe */
void	error_dollar_02_b(char *check_envp, int *j, int *len, t_attr *att)
{
	check_envp[*j] = '=';
	check_envp[*j + 1] = '\0';
	len += 1;
	att->y_mtx_envp = 0;
	att->x_mtx_envp = *len;
}

void	error_dollar_02_a(char *s, int *i, int *len)
{
	while (s[*i] != '"' && s[*i] != '\'' && s[*i] != ' ' && s[*i])
	{
		(*i)++;
		(*len)++;
		if (s[*i] == '$')
			break ;
	}
}

int	error_dollar_02(char *s, int i, t_attr *att)
{
	int		len;
	char	*check_envp;
	int		j;
	int		start;

	len = 0;
	j = 0;
	i++;
	start = i;
	if (s[i] == '?')
		return (1);
	error_dollar_02_a(s, &i, &len);
	check_envp = malloc(sizeof(char) * len + 2);
	i = start;
	while (j < len)
		check_envp[j++] = s[i++];
	error_dollar_02_b(check_envp, &j, &len, att);
	if (error_dollar_03(check_envp, att, len) == 1)
	{
		free(check_envp);
		return (1);
	}
	free(check_envp);
	return (len - 1);
}
