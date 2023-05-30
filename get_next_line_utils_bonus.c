/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-voog <cde-voog@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:30:09 by cde-voog          #+#    #+#             */
/*   Updated: 2023/05/29 20:31:51 by cde-voog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != '\0')
		res[i++] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	ft_strchr(const char *s, int c)
{
	int		cnt;
	char	car;

	car = c;
	cnt = 0;
	while (s[cnt] != car)
	{
		if (s[cnt] == '\0')
			return (NULL);
		cnt++;
	}
	return ((char *)s + cnt);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
