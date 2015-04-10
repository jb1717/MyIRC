/*
** auth.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Thu Apr  9 03:33:32 2015 Jean-Baptiste Grégoire
** Last update Fri Apr 10 00:04:05 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

int		nick_func(UNUSED(t_server *s), t_client *client, char **param)
{
  strncpy(client->login, param[1],
	  (strlen(param[1]) < 32 ? strlen(param[1]) : 31));
  return (0);
}

int		user_func(UNUSED(t_server *s), t_client *client, char **param)
{
    strncpy(client->user, param[1],
	    (strlen(param[1]) < 32 ? strlen(param[1]) : 31));
    return (0);
}
