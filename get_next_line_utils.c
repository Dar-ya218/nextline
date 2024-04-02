#include "get_next_line.h"

void	free_list(t_list *list)
{
	t_list	*temp;

	if (!list)
		return ;
	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
	list = NULL;
}