/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:01:17 by gwolf             #+#    #+#             */
/*   Updated: 2022/10/12 10:02:59 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	i = 0;
	buff = (unsigned char *) str;
	while (i < n)
	{
		buff[i] = (unsigned char) c;
		i++;
	}
	return (str);
}
