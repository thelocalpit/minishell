/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:19:35 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/25 15:38:39 by pfalasch         ###   ########.fr       */
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
