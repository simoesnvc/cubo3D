/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:22:06 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/20 15:34:02 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memdest_higher(size_t n, char *dub_src, char *dub_dest)
{
	n = n - 1;
	while (n > 0)
	{
		dub_dest[n] = dub_src[n];
		n--;
	}
	dub_dest[0] = dub_src[0];
	return (dub_dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dub_dest;
	char	*dub_src;
	size_t	i;

	dub_src = (char *)src;
	dub_dest = (char *)dest;
	i = 0;
	if (n == 0)
		return (dest);
	if (dub_dest > dub_src)
		dub_dest = memdest_higher(n, dub_src, dub_dest);
	else
	{
		if (!src)
			return (dest);
		while (i < n)
		{
			dub_dest[i] = dub_src[i];
			i++;
		}
	}
	return (dest);
}
