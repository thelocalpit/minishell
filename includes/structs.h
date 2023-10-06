/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:19:35 by pfalasch          #+#    #+#             */
/*   Updated: 2023/10/06 10:59:41 by pfalasch         ###   ########.fr       */
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
	//------- n di token -------------------
	int		nb_tokens;
	// ------ var per quotes ---------------
	int		n_dquotes;
	int		n_squotes;
	int		inside_single_quotes;
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
