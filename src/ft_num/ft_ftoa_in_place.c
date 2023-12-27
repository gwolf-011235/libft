/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_in_place.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:10:11 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/27 13:18:14 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"

static int	convert_num(float fractional_part, char *str, int precision)
{
	int	i;

	i = 0;
	while (precision-- > 0)
	{
		fractional_part *= 10;
		str[i++] = (int)fractional_part + '0';
		fractional_part -= (int)fractional_part;
	}
	return (i);
}

int	ft_ftoa_in_place(float num, char *str, int precision)
{
	int		integer_part;
	float	fractional_part;
	int		i;

	integer_part = (int)num;
	fractional_part = num - integer_part;
	if (fractional_part < 0 && integer_part == 0)
	{
		str[0] = '-';
		str[1] = '0';
		i = 2;
	}
	else
		i = ft_itoa_in_place(integer_part, str);
	if (fractional_part < 0)
		fractional_part = -fractional_part;
	str[i++] = '.';
	i += convert_num(fractional_part, str + i, precision);
	str[i] = '\0';
	return (i);
}
