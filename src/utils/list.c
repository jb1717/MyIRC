/*
** list.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/utils
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 01:36:07 2015 Jean-Baptiste Grégoire
** Last update Wed Apr  8 16:11:13 2015 Jean-Baptiste Grégoire
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
}

void		list__push_back(t_list **list, void *elem, size_t size)
{
  t_list	*it;
  t_list	*save;

  if (*list == NULL)
    {
      *list = list__new(elem, size);
      return ;
    }
  it = *list;
  while (it->next)
    it = it->next;
  it->next = list__new(elem, size);
}

void		*list__get_element(t_list *begin, int pos)
{
  unsigned int	i;
  t_list	*it;
  size_t	len;

  len = list__len(begin);
  if (begin == NULL || len <= pos)
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

void		list__delete(t_list **list, void *elem)
{
  t_list	*it;
  t_list	*prev;

  if (!(*list))
    return ;
  it = *list;
  prev = it;
  while (it)
    {
      if (it == elem)
	{
	  if (prev != it)
	    prev->next = prev->next->next;
	  else
	    *list = (*list)->next;
	  it->next = NULL;
	  return ;
	}
      if (it != *list)
	prev = prev->next;
      it = it->next;
    }
}

size_t		list__len(t_list *begin)
{
  t_list	it;
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
