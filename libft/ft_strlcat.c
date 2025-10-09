/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:22:12 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 14:15:51 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ld;

	i = 0;
	ld = ft_strlen((const char *)dest);
	if (size < ld || size == 0)
		return (ft_strlen(src) + size);
	dest += ld;
	while (i + ld < size - 1 && src [i])
	{
		*dest = (char)src[i];
		dest++;
		i++;
	}
	*dest = '\0';
	return (ft_strlen(src) + ld);
}

/* size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen((const char *)dst);
	if (dst_len > size || size == 0)
		return (ft_strlen(src) + size);
	dst += dst_len;
	while (i + dst_len < size - 1 && src[i])
		dst++[0] = (char)src[i++];
	dst[0] = 0;
	return (dst_len + ft_strlen(src));
} */