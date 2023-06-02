/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-voog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:46:30 by cde-voog          #+#    #+#             */
/*   Updated: 2023/06/02 15:12:11 by cde-voog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *memory)
{
	int		i;
	char	*s;

	i = 0;
	if (!memory[i])
		return (NULL);
	while (memory[i] && memory[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		s[i] = memory[i];
		i++;
	}
	if (memory[i] == '\n')
	{
		s[i] = memory[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_save(char *memory)
{
	char	*s;
	int		c;
	int		i;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i])
	{
		free(memory);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(memory) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (memory[i])
		s[c++] = memory[i++];
	s[c] = '\0';
	free(memory);
	return (s);
}

static char	*ft_read_and_save(int fd, char *memory)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(memory, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(memory);
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		memory = ft_strjoin(memory, buff);
	}
	free(buff);
	return (memory);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[257];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	save[fd] = ft_read_and_save(fd, save[fd]);
	if (!save[fd])
		return (NULL);
	line = ft_get_line(save[fd]);
	save[fd] = ft_save(save[fd]);
	return (line);
}
