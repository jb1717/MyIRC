/*
** utils.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Apr 12 03:47:35 2015 Hugo Prenat
** Last update Sun Apr 12 23:24:08 2015 Hugo Prenat
*/

#include "client.h"

void		add_msgbox(t_client *client, GtkWidget *new)
{
  GtkWidget	**tmp;
  int		i;

  tmp = client->messages;
  i = 0;
  if (client->messages != NULL)
    {
      if ((client->messages = malloc(sizeof(*client->messages) *
				     (strlen((char *)client->messages) + 2)))
	  == NULL)
	return ;
      while (tmp[i] != NULL)
	{
	  client->messages[i] = tmp[i];
	  i++;
	}
    }
  else
    if ((client->messages = malloc(sizeof(*client->messages) * 2)) == NULL)
      return ;
  client->messages[i] = new;
  client->messages[++i] = NULL;
  free(tmp);
}

int	is_log(t_client *client)
{
  if (client->nick == NULL)
    {
      put_text_in_entry(client->messages[0], "You are not logged\n", 19);
      return (-1);
    }
  return (0);
}

int		known_command(char *cmd)
{
  static char	*cmds[] = {"NICK", "JOIN", "USERS", "PRIVMSG", "LIST", "PART",
			   NULL};
  int		i;

  i = 0;
  while (cmds[i] != NULL)
    {
      if (strcmp(cmds[i], cmd) == 0)
	return (1);
      i++;
    }
  return (0);
}

void	disconnect_client(t_client *client)
{
  int	nbr_pages;

  nbr_pages = gtk_notebook_get_n_pages(GTK_NOTEBOOK(client->notebook));
  while (nbr_pages > 1)
    {
      remove_chan(client, client->chan[nbr_pages - 1]);
      nbr_pages--;
    }
  put_text_in_entry(client->messages[0], "Disconnected from server\n", 25);
  close(client->fd);
  client->fd = -1;
}
