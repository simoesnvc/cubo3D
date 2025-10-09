/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:51:03 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/10/01 13:17:49 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s || !*s)
		return (0);
	while (s[count] && s[count] != '\n')
		count++;
	if (s[count] == '\n')
		count++;
	return (count);
}

char	*ft_strhandle(char *str, char *txt)
{
	size_t	i;
	char	*line;

	line = (char *)malloc(ft_strlen(str) + ft_strlen(txt) + 1);
	if (!line)
		return (0); 
	i = 0;
	while (str && str[i])
	{
		line[i] = str[i];
		i++;
	}
	while (*txt)
	{
		line[i] = *txt;
		i++;
		if (*txt++ == '\n')
			break ;
	}
	line[i] = 0;
	free (str);
	return (line);
}

int	ft_reset_buffer(char *txt, int i)
{
	char	*copy;
	char	*temp;

	temp = txt;
	copy = txt;
	return (ft_copy(copy, temp, i));
}

int	ft_copy(char *copy, char *temp, int i)
{
	while (*copy)
	{
		if (*copy == '\n')
		{
			i = 1;
			*copy++ = 0;
			break ;
		}
		*copy++ = 0;
	}
	if (i == 1)
	{
		while (*copy)
		{
			*temp++ = *copy;
			*copy++ = 0;
		}
	}
	return (i);
}
