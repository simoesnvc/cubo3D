/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:24:39 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 14:37:19 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trim_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[i] && s1[j])
	{
		if (set[i] == s1[j])
		{
			j++;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

static size_t	trim_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1);
	while (set[i] && j != 0)
	{
		if (set[i] == s1[j - 1])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	total;
	char	*str;

	start = trim_start(s1, set);
	if (s1[start] == 0)
		return (ft_strdup(""));
	total = ft_strlen(s1) - start;
	j = trim_end(s1, set);
	i = 0;
	total = total - (ft_strlen(s1) - j);
	str = ft_calloc(total + 1, 1);
	while (start < j)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	return (str);
}
