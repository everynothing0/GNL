/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-voog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:46:30 by cde-voog          #+#    #+#             */
/*   Updated: 2023/06/01 20:58:08 by cde-voog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, char *memory)
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
			free(buff);
			return (NULL);
		}
		buff[cnt] = '\0';
		memory = ft_strjoin(memory, buff);
	}
	free(buff);
	return (memory);
}

char	*cut_line(char *memory)
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

char	*res(char *memory)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	while (memory[len] && memory[len] != '\n')
		len++;
	if (memory[len] == 0)
	{
		free(memory);
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
	static char	*memory[257];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	memory[fd] = get_line(fd, memory[fd]);
	if (memory[fd] == NULL)
		return (NULL);
	line = cut_line(memory[fd]);
	memory[fd] = res(memory[fd]);
	return (line);
}
