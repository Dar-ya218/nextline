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
