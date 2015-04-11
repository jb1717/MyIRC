/*
** main.cpp for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Tue Apr  7 18:34:02 2015 Hugo Prenat
** Last update Sat Apr 11 02:33:20 2015 Hugo Prenat
*/

#include "client.h"

void	unknowncmd(t_client *client, char *line)
{
  char	*buff;

  if ((buff = malloc(sizeof(*buff) * (strlen(line) + 3))) == NULL)
    return ;
  memset(buff, 0, strlen(line) + 3);
  sprintf(buff, "%s\r\n", line);
  send(client->fd, buff, strlen(buff), MSG_DONTROUTE);
  free(buff);
}

void		find_cmd(t_client *client, char *line)
{
  int		i;
  char		good;
  static t_func	cmd[] = {{"/nick", &nick_cmd},
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
  gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(box), &it, 0.f, FALSE, 0, 0);
}

int		main(int argc, char **argv)
{
  t_client	client;

  gtk_init(&argc, &argv);
  init("Client", 550, 500, &client);
  gtk_widget_show_all(client.window);
  gtk_main();
  return (0);
}
