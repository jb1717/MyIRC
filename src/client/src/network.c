/*
** network.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sat Apr 11 00:33:56 2015 Hugo Prenat
** Last update Sat Apr 11 02:38:09 2015 Hugo Prenat
*/

#include "client.h"

gboolean		check_socket(t_client *client)
{
  fd_set		readfds;
  struct timeval	timeout;
  int			ret;
  char			buff[BUFF_SIZE + 1];

  if (client->fd == -1)
    return (TRUE);
  FD_ZERO(&readfds);
  FD_SET(client->fd, &readfds);
  timeout.tv_sec = 0;
  timeout.tv_usec = 1;
  memset(buff, 0, BUFF_SIZE + 1);
  if (select(client->fd + 1, &readfds, NULL, NULL, &timeout) != -1)
    if (FD_ISSET(client->fd, &readfds))
      {
	ret = read(client->fd, buff, BUFF_SIZE);
	put_text_in_entry(client->messages, buff, ret - 2);
	put_text_in_entry(client->messages, "\n", 1);
      }
  return (TRUE);
}

int	connect_to_serv(const gchar *line)
{
  int	fd;
  char	*ip;
  int	port;
  int	pos;

  pos = 0;
  port = 6667;
  while (line[pos] && line[pos] != ':')
    pos++;
  if (line[pos] == ':' && (size_t)(pos + 1) != strlen(line))
    port = atoi(&line[pos + 1]);
  ip = (char *)&line[8];
  fd = inet__get_sock(ip, port, "TCP", AF_INET);
  return (fd);
}

void		write_sock(GtkWidget *entry, gpointer ptr)
{
  const gchar	*line;
  t_client	*client;

  client = ptr;
  line = gtk_entry_get_text(GTK_ENTRY(entry));
  if (!line)
    return ;
  if (client->fd == -1 && strncmp("/server", line, 7) != 0)
    {
      gtk_entry_set_text(GTK_ENTRY(entry), "");
      return ;
    }
  else if (strncmp("/server", line, 7) == 0)
    client->fd = connect_to_serv(line);
  else
    find_cmd(client, (char *)line);
  gtk_entry_set_text(GTK_ENTRY(entry), "");
}
