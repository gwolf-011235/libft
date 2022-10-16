#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int		length;
	t_list	*temp;

	length = 0;
	temp = lst;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	return (length);
}
