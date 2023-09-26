/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-sous <lde-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:23:28 by lde-sous          #+#    #+#             */
/*   Updated: 2023/04/28 20:12:20 by lde-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*get_next_line(int fd, bool is_file)
{
	char		*outline;
	static char	*fixed_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fixed_str = readnsave(fd, fixed_str);
	if (!fixed_str)
		return (NULL);
	outline = ft_gline(fixed_str);
	if (!is_file)
	{
		free (fixed_str);
		return (NULL);
	}
	fixed_str = save_rest(fixed_str);
	if (fixed_str)
	{
		free (fixed_str);
		fixed_str = 0;
	}
	return (outline);
}

char	*readnsave(int fd, char *str)
{
	char	*sample;
	int		bytesread;

	if (ft_strchr_mod(str, '\n'))
		return (str);
	sample = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	bytesread = 1;
	while (!ft_strchr_mod(str, '\n') && bytesread > 0)
	{
		bytesread = read(fd, sample, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(sample);
			free(str);
			return (NULL);
		}
		sample[bytesread] = 0;
		str = str_join_mod(str, sample);
	}
	free(sample);
	return (str);
}

char	*ft_gline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*save_rest(char *str)
{
	int		i;
	int		j;
	char	*saved_trim;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	saved_trim = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (str[i])
		saved_trim[j++] = str[i++];
	free(str);
	return (saved_trim);
}
