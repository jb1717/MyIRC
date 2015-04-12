/*
** network.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sat Apr 11 00:33:56 2015 Hugo Prenat
** Last update Sun Apr 12 04:21:01 2015 Hugo Prenat
*/

#include "client.h"

void	check_content(t_client *client, char *buff, int ret)
{
  int	i;

  i = 0;
  buff[ret - 1] = '\n';
  buff[ret] = '\0';
  if ((i = get_chan(client, "General")) != -1)
    {
      put_text_in_entry(client->messages[i], buff, ret - 1);
      put_text_in_entry(client->messages[i], "\n", 1);
    }
}

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
	check_content(client, buff, ret);
      }
  return (TRUE);
}

int	connect_to_serv(t_client *client, const gchar *line)
{
  int	fd;
  char	*ip;
  int	port;
  int	pos;

  pos = 0;
  port = 6667;
  ip = strdup(&line[8]);
  while (line[pos] && line[pos] != ':')
    pos++;
  if (line[pos] == ':' && (size_t)(pos + 1) != strlen(line))
    {
      port = atoi(&line[pos + 1]);
      ip[pos - 8] = '\0';
    }
  if ((fd = inet__get_sock(ip, port, "TCP", AF_INET)) != -1)
    put_text_in_entry(client->messages[0], "Connected to server \n", 21);
  free(ip);
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
    client->fd = connect_to_serv(client, line);
  else
    find_cmd(client, (char *)line);
  gtk_entry_set_text(GTK_ENTRY(entry), "");
}
