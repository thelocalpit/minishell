/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:49:45 by asacchin          #+#    #+#             */
/*   Updated: 2023/09/27 19:49:48 by asacchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "macros.h"

typedef struct s_attr
{
	int		i;
	char	**commands_arr;
	char	**token_arr;
} t_attr;

typedef struct s_token
{
	char	*token;
	int		flag;
	int		pos;
	int		j;
	int		i;
}			t_token;

#endif
