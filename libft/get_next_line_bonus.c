/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:38:44 by pfalasch          #+#    #+#             */
/*   Updated: 2023/09/23 15:39:25 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*outline;
	static char	*fixed_str[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	fixed_str[fd] = readnsave(fd, fixed_str[fd]);
	if (!fixed_str[fd])
		return (NULL);
	outline = ft_gline(fixed_str[fd]);
	fixed_str[fd] = save_rest(fixed_str[fd]);
	return (outline);
}

char	*readnsave(int fd, char *str)
{
	char	*sample;
	int		bytesread;

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
