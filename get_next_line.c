/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-voog <cde-voog@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:28:55 by cde-voog          #+#    #+#             */
/*   Updated: 2023/05/29 17:29:08 by cde-voog         ###   ########.fr       */
/*                                                   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, char *memory)
{
	int		cnt;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 2);
	if (!buff)
		return (NULL);
	cnt = 1;
	buff[0] = '\0';
	while (cnt != 0 && !ft_strchr(buff, '\n'))
	{
		cnt = read(fd, buff, BUFFER_SIZE);
		if (cnt == -1)
		{
			free(memory);
			free(buff);
			return (NULL);
		}
		buff[cnt] = '\0';
		memory = ft_strjoin(memory, buff);
	}
	free(buff);
	return (memory);
}

static char	*cut_line(char *memory)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	if (!memory[len])
		return (NULL);
	while (memory[len] && memory[len] != '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] == '\n')
	{
		line[i] = memory[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*res(char *memory)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	while (memory[len] && memory[len] != '\n')
		len++;
	if (memory[len] == 0)
	{
		free (memory);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(memory) - len) + 1);
	if (!res)
		return (NULL);
	i = 0;
	len++;
	while (memory[len])
		res[i++] = memory[len++];
	res[i] = '\0';
	free(memory);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memory;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	memory = get_line(fd, memory);
	if (memory == NULL)
		return (NULL);
	line = cut_line(memory);
	memory = res(memory);
	return (line);
}
