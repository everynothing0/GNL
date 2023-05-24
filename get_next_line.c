/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-voog <cde-voog@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:28:55 by cde-voog          #+#    #+#             */
/*   Updated: 2023/05/25 00:43:42 by cde-voog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_null(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		ptr = NULL;
	}
}

char	*join_line(int location, char **buff)
{
	char	*res;
	char	*tmp;

	tmp = NULL;
	if (location <= 0)
	{
		if (**buff == '\0')
		{
			free(*buff);
			*buff = NULL;
			return (NULL);
		}
		res = *buff;
		*buff = NULL;
		return (res);
	}
	tmp = ft_substr(*buffer, newline, BUFFER_SIZE);
	res = *buffer;
	res[newline] = 0;
	*buffer = tmp;
	return (res);

}

/*char	*read_line(int  fd, char *save)
{
	int		cnt_str;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 2);
	if (!buff)
		return (NULL);
	cnt_str = 1;
	buff[0] = '\0';

}*/

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD + 1];
	char		*read_ret;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	read_ret = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (read_ret == NULL)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	res = read_line(fd, &buff[fd], read_ret);
	free_null(&read_ret);
	return (res);
}
int	main(void)
{
}
