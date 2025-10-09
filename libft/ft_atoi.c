/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:21:39 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 10:20:07 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	signal;
	int	i;

	i = 0;
	num = 0;
	signal = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
		return (-1);
	else if (nptr[i] == '+')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
		return (-1);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
		if ((nptr[i] < '0' || nptr[i] > '9')
			&& (nptr[i] != 0 && nptr[i] != '\n'))
			return (-1);
	}
	return (num * signal);
}
