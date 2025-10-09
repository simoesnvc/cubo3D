/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:22:18 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 13:33:52 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (s1[count] != '\0' && count < n)
	{
		if (s1[count] != s2[count])
			break ;
		count++;
	}
	if (count == n)
		return (0);
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
