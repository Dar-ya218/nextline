/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:02:33 by dabochko          #+#    #+#             */
/*   Updated: 2024/03/19 18:47:31 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*read_to_node(int fd, int *byte_read);
int		find_newline(t_list *node);
void	create_list(t_list **list, int fd);
void	list_to_line(t_list *byte_list, char **line);
void	create_line(t_list **byte_buff, char **line, int i);
void	clean_list(t_list **list);
void	pass_over_node(t_list *list, t_list **pass_over);
void	free_list(t_list *list);

#endif