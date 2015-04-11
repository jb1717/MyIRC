/*
** list.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/utils
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 01:36:07 2015 Jean-Baptiste Grégoire
** Last update Sat Apr 11 21:42:47 2015 Jean-Baptiste Grégoire
*/

#include "list.h"

t_list		*list__new(void *elem, size_t size)
{
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if ((new->data = malloc(size)) == NULL)
    return (NULL);
  memcpy(new->data, elem, size);
  new->next = NULL;
  return (new);
}

void		list__push_back(t_list **list, void *elem)
{
  t_list	*it;
  t_list	*new;

  if ((new = malloc(sizeof(t_list))) == NULL)
    return ;
  new->data = elem;
  new->next = NULL;
  if (*list == NULL)
    {
      *list = new;
      return ;
    }
  it = *list;
  while (it->next)
    it = it->next;
  it->next = new;
}

void		*list__get_element(t_list *begin, int pos)
{
  int		i;
  t_list	*it;
  size_t	len;

  len = list__len(begin);
  if (begin == NULL || (int)len <= pos)
    return (NULL);
  if (pos < 0)
    pos = len - pos;
  if (pos < 0)
    return (NULL);
  i = 0;
  it = begin;
  while (i < pos && it)
    {
      it = it->next;
      i++;
    }
  return (it->data);
}

void		*list__delete(t_list **list, void *elem,
			     int (*cmp_func)(void *elem1, void *elem2))
{
  t_list	*it;
  t_list	*prev;

  if (!(*list))
    return (NULL);
  it = *list;
  prev = it;
  while (it)
    {
      if ((cmp_func && cmp_func(it->data, elem)) ||
	  (cmp_func == NULL && elem == it->data))
	{
	  if (prev != it)
	    prev->next = prev->next->next;
	  else
	    *list = (*list)->next;
	  it->next = NULL;
	  return (elem);
	}
      if (it != *list)
	prev = prev->next;
      it = it->next;
    }
  return (NULL);
}

size_t		list__len(t_list *begin)
{
  t_list	*it;
  size_t	i;

  it = begin;
  i = 0;
  while (it)
    {
      it = it->next;
      i++;
    }
  return (i);
}
