/*
** auth.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Thu Apr  9 03:33:32 2015 Jean-Baptiste Grégoire
** Last update Sat Apr 11 19:16:58 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

int		nick_func(UNUSED(t_server *s), t_client *client, char **param)
{
  if (param[1] == NULL)
    return (-1);
  strncpy(client->login, param[1],
	  (strlen(param[1]) < 32 ? strlen(param[1]) : 31));
  return (0);
}

int		user_func(UNUSED(t_server *s), t_client *client, char **param)
{
  if (param[1] == NULL)
    return (-1);
  strncpy(client->user, param[1],
	  (strlen(param[1]) < 32 ? strlen(param[1]) : 31));
  return (0);
}

int		list_func(t_server *s, t_client *client, char **param)
{
  t_list	*it;
  t_chan	*ch;

  it = s->chan_list;
  send_rpl(client, 321, "The MSN server", client->user);
  while (it)
    {
      ch = it->data;
      if (param[1])
	{
	  if (strstr(ch->name, param[1]))
	    send_rpl(client, 322, "The MSN server", ch->name);
	}
      else
	send_rpl(client, 322, "The MSN server", ch->name);
      it = it->next;
    }
  send_rpl(client, 323, "The MSN server");
  return (0);
}

int		users_func(UNUSED(t_server *s), t_client *client, UNUSED(char **param))
{
  t_list	*it;
  t_list	*it_cl;
  t_chan	*ch;
  t_client	*cl;

  it = client->chan_list;
  send_rpl(client, 392, "The MSN server", client->user, "chepakoimetr");
  while (it)
    {
      ch = it->data;
      it_cl = ch->client_list;
      while (it_cl)
	{
	  cl = it_cl->data;
	  printf("-- %d --\n", cl->fd);
	  printf("++ %s ++\n", cl->login);
	  send_rpl(client, 393, "The MSN server", cl->login);
	  it_cl = it_cl->next;
	}
      it = it->next;
    }
  send_rpl(client, 394, "The MSN server");
  return (0);
}
