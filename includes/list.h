/*
** list.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/utils
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 01:36:27 2015 Jean-Baptiste Grégoire
** Last update Wed Apr  8 15:18:00 2015 Jean-Baptiste Grégoire
*/

#ifndef LIST_H_
# define LIST_H_

# include <stddef.h>

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

void		list__delete(t_list **list, void *elem, size_t size);
void		list__push_back(t_list **list, t_list *elem);
size_t		list__len(t_list *begin);

#endif /* !LIST_H_ */
