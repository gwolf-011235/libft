/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwolf <gwolf@student.42vienna.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:20:13 by gwolf             #+#    #+#             */
/*   Updated: 2023/11/11 10:07:18 by gwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_clear_all_buffers(t_buf_node *cluster[CLUSTER_SIZE])
{
	size_t	i;

	i = 0;
	while (i < CLUSTER_SIZE)
	{
		ft_lstclear_plus(&cluster[i], true);
		i++;
	}
	return (NULL);
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
