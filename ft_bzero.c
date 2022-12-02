/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:17:51 by gwolf             #+#    #+#             */
/*   Updated: 2022/10/12 10:18:22 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	i = 0;
	buff = (unsigned char *) str;
	while (i < n)
	{
		buff[i] = 0;
		i++;
	}
}
