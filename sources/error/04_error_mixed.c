/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_error_mixed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 12:45:43 by pfalasch          #+#    #+#             */
/*   Updated: 2023/11/18 23:16:36 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


/* int error_wrong_cmd(t_attr *att)
{
	if (ft_strcmp(att->split_arr[att->y], "|\0") != 0
		&& ft_strcmp(att->split_arr[att->y], ">\0") != 0
		&& ft_strcmp(att->split_arr[att->y], ">>\0") != 0
		&& ft_strcmp(att->split_arr[att->y], "<\0") != 0
		&& ft_strcmp(att->split_arr[att->y], "<<\0") != 0)
		return (1);
	return (0);
} */

/* int error_cmd_first(t_attr *att)
{
	if ((ft_strcmp(att->split_arr[0], "<\0") != 0
			|| ft_strcmp(att->split_arr[0], "<<\0") != 0))
	{
		if (att->y % 2 != 0 && error_wrong_cmd(att) != 0)
		{
			printf("cmd wrong or not required in the subject1\n");
			return (1);
		}
		else if (att->y % 2 == 0)
		{
			printf("questa è att.split_arr: %s\n", att->split_arr[att->y]);
			printf("%d questo è att.y\n", att->y);
			if (error_wrong_cmd(att) != 0)
			{
				printf("error near pipe or redirection. two pipe or redir(?)1\n");
				return (1);
			}
		}
	}
	return (0);
}

int error_redir_first(t_attr *att)
{
	if ((ft_strcmp(att->split_arr[0], "<\0") == 0
			|| ft_strcmp(att->split_arr[0], "<<\0") == 0))
	{
		
		if (att->y % 2 == 0 && error_wrong_cmd(att) != 0)
		{
			printf("cmd wrong or not required in the subject2\n");
			return (1);
		}
		else if (att->y % 2 != 0)
		{
			if (error_wrong_cmd(att) != 0)
			{
				printf("error near pipe or redirection. two pipe or redir(?)2\n");
				return (1);
			}
		}
	}
	return (0);
} */
void check_to_do(char *s, t_attr *att)
{
	if ((s[0] == '>' && s[1] == '\0')
		|| (s[0] == '>' && s[1] == '>' && s[2] == '\0')
		|| (s[0] == '<' && s[1] == '\0')
		|| (s[0] == '<' && s[1] == '<' && s[2] == '\0'))
	{
		att->flag_to_do = 1;
	}
	else
		att->flag_to_do = 0;
}

int check_next_str_err(char *s2)
{
	if (s2[0] == '|')
	{
		printf("parse error near `|'\n");
		return (1);
	}
	else if (s2[0] == '>')
	{
		printf("parse error near `>'\n");
		return (1);
	}
	else if (s2[0] == '<')
	{
		printf("parse error near `<'\n");
		return (1);
	}
	else
		return (0);
}

int check_error_cmd(char *s1)
{
	if (s1[0] == '>' && ((s1[1] == '>' && s1[2] != '\0') || (s1[1] != '\0')))
	{
		printf("parse error near `>'\n");
		return (1);
	}
	else if (s1[0] == '<'
		&& ((s1[1] == '<' && s1[2] != '\0') || (s1[1] != '\0')))
	{
		printf("parse error near `<'\n");
		return (1);
	}
	else
		return (0);
}

int mixed_error(t_attr *att)
{
	int error1;
	int error2;

	error2 = 0;
	check_to_do(att->split_arr[att->y], att);
	if (att->flag_to_do == 1 && att->y % 2 == 0)
	{
		error1 = check_error_cmd(att->split_arr[att->y]);
		if (att->split_arr[att->y + 1][0] != '\0')
		{
			error2 = check_next_str_err(att->split_arr[att->y + 1]);
		}
	}
	else if (att->flag_to_do == 0 && att->y % 2 != 0)
	{
		error1 = check_error_cmd(att->split_arr[att->y]);
		if (att->split_arr[att->y + 1][0] != '\0')
		{
			error2 = check_next_str_err(att->split_arr[att->y + 1]);
		}
	}
	if (error2 == 1 || error1 == 1)
		return (1);
	else
		return (0);
}
