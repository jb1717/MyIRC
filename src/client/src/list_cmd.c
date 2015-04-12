/*
** list_cmd.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Apr 12 03:28:05 2015 Hugo Prenat
** Last update Sun Apr 12 03:28:28 2015 Hugo Prenat
*/

#include "client.h"

void	list_cmd(t_client *client, char *line)
{
  char	*buff;

  if ((buff = malloc(sizeof(*buff) * (strlen(line) + 3))) == NULL)
    return ;
  memset(buff, 0, strlen(line) + 3);
  sprintf(buff, "LIST %s\r\n", &line[6]);
  send(client->fd, buff, strlen(buff), MSG_DONTWAIT);
  free(buff);
}

void	users_cmd(t_client *client, UNUSED char *line)
{
  char	*buff;

  if ((buff = malloc(sizeof(*buff) * 8)) == NULL)
    return ;
  memset(buff, 0, 8);
  sprintf(buff, "USERS\r\n");
  send(client->fd, buff, strlen(buff), MSG_DONTWAIT);
  free(buff);
}
