/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 04:08:09 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/13 18:02:02 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "../push_swap.h"

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

int				found_newline(t_list *list);
t_list			*find_lst_node(t_list *list);
char			*get_line(t_list *list);
void			copy_str(t_list *list, char *str);
int				len_to_newline(t_list *list);
void			polish_list(t_list **list);
char			*get_next_line(int fd);
void			dealloc(t_list **list, t_list *clean_node, char *buf);
void			create_list(t_list **list, int fd);
void			free_list(t_list **list);

#endif