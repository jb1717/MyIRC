/*
** network.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sat Apr 11 00:33:56 2015 Hugo Prenat
** Last update Sun Apr 12 23:36:34 2015 Hugo Prenat
*/

#include "client.h"

void	put_output_on_screen(t_client *client, char *chan,
			     char *str, char *msg)
{
  int	i;

  i = 0;
  if ((i = get_chan(client, chan)) != -1)
    {
      put_text_in_entry(client->messages[i], str, strlen(str));
      put_text_in_entry(client->messages[i], msg, strlen(msg) - 3);
    }
  else
    {
      if (known_command(chan) == 0)
	{
	  put_text_in_entry(client->messages[0], str, strlen(str));
	  put_text_in_entry(client->messages[0], msg, strlen(msg));
	}
    }
}

void	check_content(t_client *client, char *buff)
{
  char	*str;
  char	*msg;
  char	*nick;
  char	*chan;

  if (strcocc(buff, ":") < 1)
    return ;
  msg = get_msg_from_msg(buff);
  if ((nick = get_nick_from_msg(buff)) == NULL)
    nick = strdup("server");
  if ((str = malloc(sizeof(*str) * (strlen(nick) + 4))) == NULL)
    return ;
  memset(str, 0, strlen(nick) + 4);
  sprintf(str, "<%s> ", nick);
  chan = get_chan_from_msg(buff);
  put_output_on_screen(client, chan, str, msg);
  free(nick);
  free(str);
}

gboolean		check_socket(t_client *client)
{
  fd_set		readfds;
  struct timeval	timeout;
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
	if (read(client->fd, buff, BUFF_SIZE) <= 0)
	  {
	    disconnect_client(client);
	    return (TRUE);
	  }
	check_content(client, buff);
      }
  return (TRUE);
}

int	connect_to_serv(t_client *client, const gchar *line)
{
  int	fd;
  char	*ip;
  int	port;
  int	pos;

  if (client->fd != -1)
    disconnect_client(client);
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
    put_text_in_entry(client->messages[0], "Connected to server\n", 20);
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
      put_text_in_entry(client->messages[0], "Not connected to server\n", 24);
      gtk_entry_set_text(GTK_ENTRY(entry), "");
      return ;
    }
  else if (strncmp("/server", line, 7) == 0)
    client->fd = connect_to_serv(client, line);
  else
    find_cmd(client, (char *)line);
  gtk_entry_set_text(GTK_ENTRY(entry), "");
}
