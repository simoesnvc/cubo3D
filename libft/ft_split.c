/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:01:44 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 13:51:28 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_strs(char	const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i] != 0)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static char	**cpy(char **split, char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	j;

	j = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != 0)
			{
				split[j][count] = s[i];
				i++;
				count++;
			}
			j++;
			count = 0;
		}
		if (s[i] == c)
			i++;
	}
	return (split);
}

static char	**args(char **split, char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	j;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != 0)
			{
				i++;
				count++;
			}
			split[j] = ft_calloc(count + 1, 1);
			j++;
			count = 0;
		}
		if (s[i] == c)
			i++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = ft_calloc(count_strs(s, c) + 1, sizeof(char **));
	if (!split)
		return (0);
	if (count_strs(s, c) == 0)
	{
		split[0] = 0;
		return (split);
	}
	if (c == 0)
	{
		split[0] = ft_strdup(s);
		return (split);
	}
	split = args(split, s, c);
	return (cpy(split, s, c));
}
