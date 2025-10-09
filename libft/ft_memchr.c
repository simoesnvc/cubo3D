/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:22:00 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 10:20:29 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	b;
	unsigned char	*str;

	str = (unsigned char *)s;
	b = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == b)
			return (str);
		str++;
		i++;
	}
	return (0);
}
