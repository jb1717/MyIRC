/*
** list.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/utils
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 01:36:07 2015 Jean-Baptiste Grégoire
** Last update Wed Apr  8 01:45:17 2015 Jean-Baptiste Grégoire
*/

#include "list.h"

void		list__add(t_client **list, t_client *elem)
{
  t_client	*it;
  t_client	*save;
  char		stop;

  if (*list == NULL)
    {
      elem->next = *list;
      *list = elem;
      return ;
    }
  stop = 1;
  it = *list;
  while (it && stop)
    {
      if (it->next && it->next->addr < elem->addr)
  	it = it->next;
      else
  	stop = 0;
    }
  save = it->next;
  it->next = elem;
  elem->next = save;
}

void		list__delete(t_client **list, t_client *elem)
{
  t_client	*it;
  t_client	*prev;

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

size_t		list__len(t_client *begin)
{
  t_client	it;
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
