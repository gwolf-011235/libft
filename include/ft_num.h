/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:26:16 by gwolf             #+#    #+#             */
/*   Updated: 2023/12/27 13:05:13 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUM_H
# define FT_NUM_H

# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "ft_str.h"

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_itoa_in_place(int num, char *str);

#endif
