/*
** auth.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Thu Apr  9 03:33:32 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 23:22:15 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

int		is_logged(t_client *client)
{
  if (strlen(client->login) == 0)
    return (0);
  return (1);
}

int		nick_func(t_server *s, t_client *client, char **param)
{
  t_list	*it;
  t_client	*cl;

  if (param[1] == NULL)
    return (-1);
  it = s->client_list;
  while (it)
    {
      cl = it->data;
      if (strcmp(cl->login, param[1]) == 0)
	{
	  send_rpl(client, 436, param[1]);
	  return (0);
	}
      it = it->next;
    }
  if (strlen(client->login) > 0)
    send_rpl(client, 1, client->login, "NICK", param[1]);
  else
    welcome_msg(client);
  bzero(client->login, 32);
  strncpy(client->login, param[1],
	  (strlen(param[1]) < 32 ? strlen(param[1]) : 31));
  return (0);
}

int		user_func(UNUSED(t_server *s), t_client *client, char **param)
{
  if (param[1] == NULL)
    return (-1);
  if (strlen(client->user))
    {
      send_rpl(client, 462);
      return (0);
    }
  strncpy(client->user, param[1],
	  (strlen(param[1]) < 32 ? strlen(param[1]) : 31));
  if (param[4])
    strncpy(client->terminalID, param[4],
	    (strlen(param[1]) < 32 ? strlen(param[1]) : 31));
  if (is_logged(client))
    welcome_msg(client);
  return (0);
}

int		list_func(t_server *s, t_client *client, char **param)
{
  t_list	*it;
  t_chan	*ch;

  it = s->chan_list;
  send_rpl(client, 321, "The MSN server");
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

int		users_func(UNUSED(t_server *s), t_client *client,
			   UNUSED(char **param))
{
  t_list	*it;
  t_list	*it_cl;
  t_chan	*ch;
  t_client	*cl;

  it = client->chan_list;
  send_rpl(client, 392, "The MSN server");
  while (it)
    {
      ch = it->data;
      it_cl = ch->client_list;
      while (it_cl)
	{
	  cl = it_cl->data;
	  send_rpl(client, 393, "The MSN server", cl->login);
	  it_cl = it_cl->next;
	}
      it = it->next;
    }
  send_rpl(client, 394, "The MSN server");
  return (0);
}
