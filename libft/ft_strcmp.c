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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	count;

	count = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (s1[count] != '\0' && s2[count] != '\0')
	{
		if (s1[count] != s2[count])
			return (-1);
		count++;
	}
	return (0);
}
