/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:22:20 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 10:20:54 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] != 0)
	{
		t = 0;
		while (big[i] == little[t] && i < len)
		{
			i++;
			t++;
		}
		i = i - t + 1;
		if (little[t] == 0)
			return ((char *)(big + i - 1));
	}
	return (0);
}
