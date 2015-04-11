/*
** list.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/utils
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 01:36:27 2015 Jean-Baptiste Grégoire
** Last update Sat Apr 11 21:43:31 2015 Jean-Baptiste Grégoire
*/

#ifndef LIST_H_
# define LIST_H_

# include <stddef.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

t_list		*list__new(void *elem, size_t size);
void		list__push_back(t_list **list, void *elem);
void		*list__delete(t_list **list, void *elem,
			     int (*cmp_func)(void *elem1, void *elem2));
void		*list__get_element(t_list *begin, int pos);
size_t		list__len(t_list *begin);

#endif /* !LIST_H_ */
