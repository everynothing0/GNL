/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-voog <cde-voog@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:28:55 by cde-voog          #+#    #+#             */
/*   Updated: 2023/05/18 15:32:29 by cde-voog         ###   ########.fr       */
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
	tmp = 
}
char	*get_line(int  fd, char *save)
{
	int		cnt_str;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 2);
	if (!buff)
		return (NULL);
	cnt_str = 1;
	buff[0] = '\0';

}
