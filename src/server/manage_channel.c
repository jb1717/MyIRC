/*
** manage_channel.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Sat Apr 11 22:03:02 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 01:28:47 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

int		join_func(t_server *s, t_client *client, char **param)
{
  add_client_to_chan(s, client, param[1]);
  return (0);
}

static void	remove_link_from_chan(t_chan *chan, t_client *client)
{
  t_list	*it;
  t_list	*prev;
  t_client	*cl;

  it = chan->client_list;
  prev = it;
  while (it)
    {
      cl = it->data;
      if (cl->fd == client->fd)
	{
	  if (prev != it)
	    prev->next = prev->next->next;
	  else
	    chan->client_list = chan->client_list->next;
	  it->next = NULL;
	  return ;
	}
      if (it != chan->client_list)
	prev = prev->next;
      it = it->next;
    }
}

static void	remove_link_from_client(t_client *client, t_chan *chan)
{
  t_list	*it;
  t_list	*prev;
  t_chan	*ch;

  it = client->chan_list;
  prev = it;
  while (it)
    {
      ch = it->data;
      if (strcmp(ch->name, chan->name) == 0)
	{

	  if (prev != it)
	    prev->next = prev->next->next;
	  else
	    client->chan_list = client->chan_list->next;
	  it->next = NULL;
	  return ;
	}
      if (it != chan->client_list)
	prev = prev->next;
      it = it->next;
    }
}

int		part_func(t_server *s, t_client *client, char **param)
{
  t_list	*it_chan;
  t_chan	*ch;

  it_chan = client->chan_list;
  while (it_chan)
    {
      ch = it_chan->data;
      if (strcmp(param[1], ch->name) == 0)
	{
	  remove_link_from_chan(ch, client);
	  list__delete(&(client->chan_list), ch, NULL);
	}
      if (list__len(ch->client_list) == 0)
	{
	  list__delete(&(s->chan_list), ch, NULL);
	  return (0);
	}
      it_chan = it_chan->next;
    }
  return (0);
}
