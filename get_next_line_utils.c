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

void	create_line(t_list **list, char **line, int length)
{
	int		j;
	t_list	*tmp;

	tmp = *list;
	if (tmp == NULL)
		return ;
	while (tmp)
	{
		j = 0;
		while (tmp->content[j] != '\0')
		{
			if (tmp->content[j] == '\n')
			{
				length++;
				break ;
			}
			length++;
			j++;
		}
		tmp = tmp->next;
	}
	*line = malloc((length + 1) * sizeof(char));
	if (!*line)
		return ;
	(*line)[length] = '\0';
}
