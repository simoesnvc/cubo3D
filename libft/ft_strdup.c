/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:07:33 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 10:20:41 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	str = (char *)malloc(i * sizeof(char) + 1);
	if (!str)
		return (0);
	while (i > 0)
	{
		s--;
		i--;
	}
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
