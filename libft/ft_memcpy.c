/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:22:04 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 10:20:31 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*edit_dest;
	unsigned char	*move_src;

	i = 0;
	edit_dest = (unsigned char *)dest;
	move_src = (unsigned char *)src;
	while (i < n)
	{
		edit_dest[i] = move_src[i];
		i++;
	}
	return (dest);
}
