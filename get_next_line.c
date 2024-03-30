/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:25:51 by dabochko          #+#    #+#             */
/*   Updated: 2024/03/25 17:15:21 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int ft)
{
	char	*line;
	static t_lis *list;

	ine = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free_list(list);
		list = NULL;
		return (NULL);
	}
	create_list(&list, fd);
	if (!list)
		return (NULL);
	list_to_line(list, &line);
	if (line[0] == '\0' || !line)
	{
		free_list(list);
		list = NULL;
		free(line);
		return (NULL);
	}
	clean_list(&list);
	return (line);
}

t_list	*read_to_node(int fd, int *read_count)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = malloc(BUFFER_SIZE + 1);
	if (!node->content)
	{
		free(node);
		return (NULL);
	}
	/* La función read lee BUFFER_SIZE bytes del archivo fd en node->content,
	y luego almacena el número de bytes leídos en read_count. Como
	read_count es un puntero, esto modifica la variable original que se
	pasó a read_to_node. */
	*read_count = read(fd, node->content, BUFFER_SIZE);
	if (*read_count < 0)
	{
		free(node->content);
		free(node);
		return (NULL);
	}
	node->content[*read_count] = '\0';
	node->next = NULL;
	return (node);
}

void	create_list(t_list **list, int fd)
{
	t_list	*node;
	t_list	*head;
	int		read_count;

	read_count = 1;
	if (!*list)
		*list = read_to_node(fd, &read_count);
	if (*list == NULL)
		return ;
	head = *list;
	while (read_count > 0 && !find_newline(*list))
	{
		node = read_to_node(fd, &read_count);
		if (!node)
		{
			free_list(head);
			*list = NULL;
			return ;
		}
		(*list)->next = node;
		*list = (*list)->next;
	}
	*list = head;
}

void	list_to_line(t_list *list, char **line)
{
	int	i;
	int	j;

	i = 0;
	if (!list)
		return ;
	create_line(&list, line, 0);
	if (!*line)
		return ;
	while (list && *line)
	{
		j = 0;
		while (list->content[j] && list->content[j] != '\n')
		{
			(*line)[i] = list->content[j];
			i++;
			j++;
		}
		if (list->content[j] == '\n')
			(*line)[i] = list->content[j];
		list = list->next;
	}
}

void	clean_list(t_list **list)
{
	t_list	*pass_over;
	t_list	*last_node;

	last_node = *list;
	if (!last_node)
		return ;
	while (last_node && last_node->next)
		last_node = last_node->next;
	pass_over = malloc(sizeof(t_list));
	if (!pass_over)
	{
		free_list(*list);
		return ;
	}
	pass_over->next = NULL;
	pass_over_node(last_node, &pass_over);
	free_list(*list);
	*list = pass_over;
}