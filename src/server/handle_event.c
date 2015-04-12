/*
** handle_event.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 15:55:45 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 13:08:46 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

void		get_input(t_server *s, t_client *client)
{
  char		*input;

  if ((input = read_input(client->fd)) == NULL)
    {
      quit_func(s, client, NULL);
      return ;
    }
  call_func(s, client, input);
}

void		set_output(t_client *client)
{
  char		*tmp;
  int		sent;

  if ((tmp = cbuffer__read(&(client->buf), BUF_READ)) == NULL)
    return ;
  if ((sent = send(client->fd, tmp, BUF_READ, MSG_DONTWAIT)) == -1)
    return ;
  if (sent < BUF_READ)
    cbuffer__put_back(&(client->buf), (char *)((size_t)tmp + sent),
		      BUF_READ - sent);
}

void		add_new_client(t_server *s)
{
  t_client	*new;

  if ((new = malloc(sizeof(t_client))) == NULL)
    return ;
  bzero(new, sizeof(t_client));
  if ((new->fd = accept(s->serv_sock, NULL, NULL)) == -1)
    return ;
  new->state = READY;
  new->perms = USER;
  new->next = NULL;
  FD_SET(new->fd, &(s->active_fd_read));
  s->bfd = MAX(s->bfd, new->fd);
  cbuffer__init(&(new->buf));
  add_client_to_chan(s, new, "#General");
  list__push_back(&(s->client_list), new);
}

int		handle_event(t_server *s, fd_set *rfds, fd_set *wfds)
{
  t_list	*it;
  t_client	*client;

  it = s->client_list;
  if (FD_ISSET(s->serv_sock, rfds))
    add_new_client(s);
  while (it)
    {
      client = it->data;
      if (FD_ISSET(client->fd, wfds))
	set_output(client);
      if (FD_ISSET(client->fd, rfds))
	get_input(s, client);
      it = it->next;
    }
  return (0);
}
