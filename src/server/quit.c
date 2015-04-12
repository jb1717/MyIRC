/*
** quit.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Fri Apr 10 02:25:12 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 23:26:49 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

void		leave_all_chanel(t_server *s, t_client *client)
{
  t_list	*it;
  t_chan	*ch;

  it = client->chan_list;
  while (it)
    {
      ch = it->data;
      list__delete(&(ch->client_list), client, NULL);
      if (list__len(ch->client_list) == 0)
	list__delete(&(s->chan_list), ch, NULL);
      it = it->next;
    }
}

int		quit_func(t_server *s, t_client *client, UNUSED(char **param))
{
  t_client	*del;

  if ((del = list__delete(&(s->client_list), client, NULL)) == NULL)
    return (0);
  leave_all_chanel(s, del);
  del->next = NULL;
  FD_CLR(del->fd, &(s->active_fd_read));
  FD_CLR(del->fd, &(s->active_fd_write));
  close(del->fd);
  free(del);
  return (0);
}
