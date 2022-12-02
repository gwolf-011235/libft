/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:49:13 by gwolf             #+#    #+#             */
/*   Updated: 2022/10/23 16:12:18 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the function ’f’ on each character of the string passed as argument, 
** passing its index as first argument. Each character is passed by address 
** to ’f’ to be modified if necessary */
void	ft_striteri(char const *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	char	*temp;

	if (!s || !f)
		return ;
	temp = (char *) s;
	i = 0;
	while (*temp)
	{
		f(i, temp);
		temp++;
		i++;
	}
}
