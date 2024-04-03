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

int	find_newline(t_list *node)
{
	int	i;

	i = 0;
	if (!node)
		return (0);
	while (node->content[i])
	{
		if (node->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	find_newline(t_list *node)
{
	int	i;

	i = 0;
	if (!node)
		return (0);
	while (node->content[i])
	{
		if (node->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
