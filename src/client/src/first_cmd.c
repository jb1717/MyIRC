/*
** first_cmd.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sat Apr 11 01:55:42 2015 Hugo Prenat
** Last update Sun Apr 12 03:27:55 2015 Hugo Prenat
*/

#include "client.h"

void	nick_cmd(t_client *client, char *line)
{
  char	*buff;

  if ((buff = malloc(sizeof(*buff) * (strlen(line) + 3))) == NULL)
    return ;
  memset(buff, 0, strlen(line) + 3);
  sprintf(buff, "NICK %s\r\n", &line[6]);
  send(client->fd, buff, strlen(buff), MSG_DONTWAIT);
  free(buff);
}

void	user_cmd(t_client *client, char *line)
{
  char	*buff;

  if ((buff = malloc(sizeof(*buff) * (strlen(line) + 3))) == NULL)
    return ;
  memset(buff, 0, strlen(line) + 3);
  sprintf(buff, "USER %s\r\n", &line[6]);
  send(client->fd, buff, strlen(buff), MSG_DONTWAIT);
  free(buff);
}

void	join_cmd(t_client *client, char *line)
{
  char	*buff;

  if ((buff = malloc(sizeof(*buff) * (strlen(line) + 3))) == NULL)
    return ;
  memset(buff, 0, strlen(line) + 3);
  sprintf(buff, "JOIN %s\r\n", &line[6]);
  send(client->fd, buff, strlen(buff), MSG_DONTWAIT);
  free(buff);
  if (get_chan(client, &line[6]) == -1)
    add_chan(client, &line[6]);
}

void	part_cmd(t_client *client, char *line)
{
  char	*buff;

  if ((buff = malloc(sizeof(*buff) * (strlen(line) + 3))) == NULL)
    return ;
  memset(buff, 0, strlen(line) + 3);
  sprintf(buff, "PART %s\r\n", &line[6]);
  send(client->fd, buff, strlen(buff), MSG_DONTWAIT);
  free(buff);
  remove_chan(client, &line[6]);
}

void	msg_cmd(t_client *client, char *line)
{
  char	*buff;

  if ((buff = malloc(sizeof(*buff) * (strlen(line) + 7))) == NULL)
    return ;
  memset(buff, 0, strlen(line) + 7);
  sprintf(buff, "PRIVMSG %s\r\n", &line[5]);
  send(client->fd, buff, strlen(buff), MSG_DONTWAIT);
  free(buff);
}
