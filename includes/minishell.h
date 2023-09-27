/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asacchin <asacchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:50:13 by asacchin          #+#    #+#             */
/*   Updated: 2023/09/27 19:50:15 by asacchin         ###   ########.fr       */
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
