/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:45:35 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/10/01 12:44:00 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	txt[BUFFER_SIZE + 1];
	char		*str;
	int			i;

	str = 0;
	i = 0;
	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
		return (0);
	while (*txt || (read(fd, txt, BUFFER_SIZE)) > 0)
	{
		str = ft_strhandle(str, txt);
		if (ft_reset_buffer(txt, i))
			break ;
	}
	return (str);
}

/* int main()
{
	int fd = open("test2.txt", O_RDONLY);
	char	*str;
	str = get_next_line(fd);
	printf("RESULT %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("RESULT %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("RESULT %s\n", str);
	free (str);
	str = get_next_line(fd);
	printf("RESULT %s\n", str);
	free (str);
	close(fd);
} */