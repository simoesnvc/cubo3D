/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:11:29 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 11:08:44 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const	*s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	j;
	char			*str;

	j = ft_strlen((char *)s);
	str = ft_calloc(j + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < j)
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	return (str);
}
