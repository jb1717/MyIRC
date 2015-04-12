/*
** manage_channel.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Sat Apr 11 22:03:02 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 14:27:10 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

int		join_func(t_server *s, t_client *client, char **param)
{
  if (param[1] == NULL)
    return (0);
  add_client_to_chan(s, client, param[1]);
  send_rpl(client, 1, client->login, "JOIN", param[1]);
  return (0);
}

void		add_new_chan(t_server *s, char *name, t_client *client)
{
  t_chan	*new;

  if ((new = malloc(sizeof(t_chan))) == NULL)
    return ;
  bzero(new, sizeof(t_chan));
  strncpy(new->name, name,
	  (strlen(name) < 32 ? strlen(name) : 31));
  list__push_back(&(new->client_list), client);
  list__push_back(&(s->chan_list), new);
  list__push_back(&(client->chan_list), new);
}

void		add_client_to_chan(t_server *s, t_client *client, char *name)
{
  t_list	*it;
  t_chan	*ch;

  it = s->chan_list;
  while (it)
    {
      ch = it->data;
      if (strcmp(name, ch->name) == 0)
	{
	  list__push_back(&(ch->client_list), client);
	  list__push_back(&(client->chan_list), ch);
	  return ;
	}
      it = it->next;
    }
  add_new_chan(s, name, client);
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

int		part_func(t_server *s, t_client *client, char **param)
{
  t_list	*it_chan;
  t_chan	*ch;

  if (param[1] == NULL)
    return (0);
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
	  send_rpl(client, 1, client->login, "PART", param[1]);
	  return (0);
	}
      it_chan = it_chan->next;
    }
  send_rpl(client, 1, client->login, "PART", param[1]);
  return (0);
}
