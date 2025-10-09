/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:18:14 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 10:21:07 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (len < ft_strlen(s) && start < ft_strlen(s))
		str = (char *)malloc(len + 1);
	else if (start < ft_strlen(s) && len > ft_strlen(s + start))
		str = (char *)malloc(ft_strlen(s + start) + 1);
	else if (start < ft_strlen(s))
		str = (char *)malloc(ft_strlen(s) + 1);
	else
		return (ft_strdup(""));
	if (!str)
		return (0);
	i = start;
	j = 0;
	while (j < len && i < ft_strlen(s))
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
