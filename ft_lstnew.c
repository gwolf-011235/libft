#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*new_node;

	if (!content)
		return (NULL);
	new_node = malloc(sizeof(t_list));
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
