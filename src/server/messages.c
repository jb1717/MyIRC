/*
** messages.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Fri Apr 10 09:21:17 2015 Jean-Baptiste Grégoire
** Last update Fri Apr 10 18:17:00 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

void		send_message(t_client *dest, char *message)
{
  int		sent;
  char		*tmp;
  int		len;

  len = strlen(message);
  if ((tmp = malloc(sizeof(char) * (len + 3))) == NULL)
    return ;
  bzero(tmp, len + 3);
  memcpy(tmp, message, len);
  strcat(tmp, "\r\n");
  if ((sent = send(dest->fd, tmp, len + 3, MSG_DONTWAIT)) == -1)
    {
      free(tmp);
      return ;
    }
  if (sent < len + 3)
    cbuffer__write(&(dest->buf), ((char *)(size_t)tmp + sent), len + 3 - sent);
  free(tmp);
}

int		message_func(t_server *s, UNUSED(t_client *client), char **param)
{
  char		**dests;
  t_list	*it;
  t_client	*cl;

  if ((dests = parse_args(param[1], 0, ",")) == NULL)
    return (-1);
  it = s->client_list;
  while (it)
    {
      cl = it->data;
      if (is_in(cl->login, dests, 0))
	{
	  if (param[2])
	    send_message(cl, s->input + (param[2] - param[0]));
	}
      it = it->next;
    }
  return (0);
}
