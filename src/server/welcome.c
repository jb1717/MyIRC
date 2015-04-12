/*
** welcome.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Sun Apr 12 11:32:16 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 11:42:18 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

void		welcome_msg(t_client *client)
{
  send_rpl(client, 11, client->login);
  send_rpl(client, 12, client->login);
  send_rpl(client, 13, client->login);
}
