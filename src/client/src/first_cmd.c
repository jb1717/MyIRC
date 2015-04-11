/*
** first_cmd.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sat Apr 11 01:55:42 2015 Hugo Prenat
** Last update Sat Apr 11 02:20:10 2015 Hugo Prenat
*/

#include "client.h"

void	nick_cmd(t_client *client, char *line)
{
  char	*buff;

  if ((buff = malloc(sizeof(*buff) * (strlen(line) + 3))) == NULL)
    return ;
  memset(buff, 0, strlen(line) + 3);
  sprintf(buff, "NICK %s\r\n", &line[5]);
  send(client->fd, buff, strlen(buff), MSG_DONTROUTE);
  free(buff);
}
