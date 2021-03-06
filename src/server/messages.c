/*
** messages.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Fri Apr 10 09:21:17 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 23:26:21 2015 Jean-Baptiste Grégoire
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
  if (tmp[len - 1] == '\n')
    tmp[len - 1] = '\0';
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

void		try_client(t_server *s, t_list *begin,
			   char **dests, char **param)
{
  t_list	*it;
  t_client	*cl;

  it = begin;
  while (it)
    {
      cl = it->data;
      if (is_in(cl->login, dests, 0))
	{
	  if (param[2])
	    send_message(cl, s->input);
	}
      it = it->next;
    }
}

void		try_chan(t_server *s, t_list *begin,
			 char **dests, char **param)
{
  t_list	*it;
  t_list	*it_cl;
  t_client	*cl;
  t_chan	*ch;

  it = begin;
  while (it)
    {
      ch = it->data;
      if (is_in(ch->name, dests, 0))
	{
	  if (param[2])
	    {
	      it_cl = ch->client_list;
	      while (it_cl)
		{
		  cl = it_cl->data;
		  send_message(cl, s->input);
		  it_cl = it_cl->next;
		}
	    }
	}
      it = it->next;
    }
}

int		message_func(t_server *s, t_client *client, char **param)
{
  char		**dests;
  char		*tmp;
  char		*new;

  if ((dests = parse_args(param[1], 0, ",")) == NULL)
    return (-1);
  if ((tmp = calloc(sizeof(char), 1024)) == NULL)
    return (-1);
  if (param[1] == NULL || param[2] == NULL)
    return (-1);
  snprintf(tmp, 1023, ":%s PRIVMSG %s :%s\r\n", client->login, param[1],
	   s->input + (param[2] - param[0]));
  if ((new = realloc(tmp, strlen(tmp) + 1)) == NULL)
    new = tmp;
  free(s->input);
  s->input = new;
  try_client(s, s->client_list, dests, param);
  try_chan(s, s->chan_list, dests, param);
  return (0);
}
