/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:16:54 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/26 12:51:45 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "commands.h"
# include "error.h"
# include "executer.h"
# include "initialize.h"
# include "macros.h"
# include "parser.h"
# include "sanitize.h"
# include "structs.h"
# include "signals.h"
# include "tokens.h"
# include "utilities.h"

extern int	g_value;

#endif
