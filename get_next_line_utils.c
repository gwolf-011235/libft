/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:20:13 by gwolf             #+#    #+#             */
/*   Updated: 2022/11/16 10:36:12 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		if (((unsigned char *)s)[i] == (unsigned char) c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	while (n--)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_lstclear_plus(t_buf_node **head, bool fclear)
{
	t_buf_node	*tmp;

	if (*head)
	{
		while (*head)
		{
			tmp = (*head)->next;
			if (!fclear && (*head) && (*head)->has_nl)
			{
				free(*head);
				*head = tmp;
				break ;
			}
			free(*head);
			(*head) = tmp;
		}
	}
	return (NULL);
}

t_buf_node	*ft_lstadd_buf(t_buf_node **head)
{
	t_buf_node	*new_node;

	new_node = malloc(sizeof(t_buf_node));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		(*head)->tail = *head;
		return (new_node);
	}
	(*head)->tail->next = new_node;
	(*head)->tail = new_node;
	new_node->tail = new_node;
	return (new_node);
}
