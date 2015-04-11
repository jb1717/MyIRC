/*
** auth.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Thu Apr  9 03:33:32 2015 Jean-Baptiste Grégoire
** Last update Fri Apr 10 22:36:37 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

int		nick_func(UNUSED(t_server *s), t_client *client, char **param)
{
  strncpy(client->login, param[1],
	  (strlen(param[1]) < 32 ? strlen(param[1]) : 31));
  return (0);
}

int		user_func(t_server *s, t_client *client, char **param)
{
  t_list	*it;
  t_client	*cl;

  strncpy(client->user, param[1],
	  (strlen(param[1]) < 32 ? strlen(param[1]) : 31));
  send_rpl(client, 393, "The MSN server", client->user, "chepakoimetr");
  if (s->client_list->next)
    {
      it = s->client_list;
      while (it)
	{
	  cl = it->data;
	  send_rpl(client, 393, cl->user);
	  it = it->next;
	}
    }
  else
    send_rpl(client, 395, "The MSN server");
  send_rpl(client, 394, "The MSN server");
  return (0);
}
