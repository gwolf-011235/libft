/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_in_place.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 12:55:36 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/27 13:04:58 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

static int	convert_num(int num, char *str)
{
	int	i;

	i = 0;
	str[i++] = num % 10 + '0';
	num /= 10;
	while (num > 0)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	return (i);
}

int	ft_itoa_in_place(int num, char *str)
{
	int		i;
	bool	is_negative;

	if (num == INT_MIN)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (12);
	}
	if (num < 0)
	{
		is_negative = true;
		num = -num;
	}
	else
		is_negative = false;
	i = convert_num(num, str);
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (i);
}
