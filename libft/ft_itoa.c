/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdoutor- <jdoutor-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:50:42 by jdoutor-          #+#    #+#             */
/*   Updated: 2024/06/13 13:50:40 by jdoutor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(long int n)
{
	long int	count;

	count = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*num;
	int			size;
	int			signal;
	long int	n1;

	signal = 0;
	n1 = n;
	size = n_len(n1);
	if (n1 < 0)
	{
		signal = 1;
		n1 = n1 * -1;
	}
	num = ft_calloc((size + signal + 1), sizeof(char));
	if (!num)
		return (0);
	size = size - 1;
	while (size >= 0)
	{
		num[size-- + signal] = (n1 % 10) + 48;
		n1 = (n1 - (n1 % 10)) / 10;
	}
	if (signal == 1)
		num[0] = '-';
	return (num);
}
