/*
** main.cpp for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Tue Apr  7 18:34:02 2015 Hugo Prenat
** Last update Sun Apr 12 22:11:59 2015 Hugo Prenat
*/

#include "client.h"

void	unknowncmd(t_client *client, char *line)
{
  char	*buff;
  int	size_buff;
  int	cur_chan;

  if (line[0] == '/')
    return ;
  cur_chan = gtk_notebook_get_current_page(GTK_NOTEBOOK(client->notebook));
  size_buff = (strlen(line) + 12 + strlen(client->chan[cur_chan]));
  if ((buff = malloc(sizeof(*buff) * size_buff)) == NULL)
    return ;
  memset(buff, 0, strlen(line) + 11);
  sprintf(buff, "PRIVMSG %s %s\r\n", client->chan[cur_chan], line);
  send(client->fd, buff, strlen(buff), MSG_DONTWAIT);
  free(buff);
}

void		find_cmd(t_client *client, char *line)
{
  int		i;
  char		good;
  static t_func	cmd[] = {{"/nick", &nick_cmd}, {"/list", &list_cmd},
			 {"/join", &join_cmd}, {"/part", &part_cmd},
			 {"/msg", &msg_cmd}, {"/send_file", &send_cmd},
			 {"/accept_file", &recv_cmd}, {"/users", &users_cmd},
			 {NULL, NULL}};

  i = 0;
  good = 0;
  while (good == 0 && cmd[i].str != NULL)
    {
      if (strncmp(cmd[i].str, line, strlen(cmd[i].str)) == 0)
	{
	  cmd[i].func(client, line);
	  good++;
	}
      i++;
    }
  if (good == 0)
    unknowncmd(client, line);
  return ;
}

void		put_text_in_entry(GtkWidget *box, char *str, int size)
{
  GtkTextBuffer	*text_buffer;
  GtkTextIter	it;

  text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(box));
  gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(text_buffer), &it);
  gtk_text_buffer_insert(text_buffer, &it, str, size);
  gtk_text_buffer_get_end_iter(GTK_TEXT_BUFFER(text_buffer), &it);
  gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(box), &it, 0.0, FALSE, 0, 0);
}

int		main(int argc, char **argv)
{
  t_client	client;

  gtk_init(&argc, &argv);
  init("Client", 550, 500, &client);
  gtk_widget_show_all(client.window);
  gtk_main();
  if (client.fd != -1)
    close(client.fd);
  return (0);
}
