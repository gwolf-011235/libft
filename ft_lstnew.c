#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list	*head;

	if (!content)
		return (NULL);
	head = malloc(sizeof(t_list));
	head->content = content;
	head->next = NULL;
	return (head);
}
