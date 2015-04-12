/*
** chan.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sat Apr 11 18:20:39 2015 Hugo Prenat
** Last update Sun Apr 12 16:54:57 2015 Hugo Prenat
*/

#include "client.h"

void	add_chan(t_client *client, char *new_chan)
{
  char	**tmp;
  int	i;

  tmp = client->chan;
  i = 0;
  if (client->chan != NULL)
    {
      if ((client->chan = malloc(sizeof(*client->chan) *
				 (strlen((char *)client->chan) + 2)))
	  == NULL)
	return ;
      while (tmp[i] != NULL)
	{
	  client->chan[i] = tmp[i];
	  i++;
	}
    }
  else
    if ((client->chan = malloc(sizeof(*client->chan) * 2)) == NULL)
      return ;
  client->chan[i] = strdup(new_chan);
  client->chan[++i] = NULL;
  free(tmp);
  create_msg(client, new_chan);
}

void	remove_chan(t_client *client, char *old_chan)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (client->chan[i])
    {
      if (strcmp(client->chan[i], old_chan) == 0)
	{
	  gtk_notebook_remove_page(GTK_NOTEBOOK(client->notebook), i);
	  free(client->chan[i]);
	}
      else
	{
	  client->chan[j] = client->chan[i];
	  client->messages[j] = client->messages[i];
	  j++;
	}
      i++;
    }
  client->chan[j] = NULL;
  client->messages[j] = NULL;
  i = 0;
}

int	get_chan(t_client *client, char *chan)
{
  int	i;

  i = 0;
  while (client->chan[i])
    {
      if (strcmp(client->chan[i], chan) == 0)
	return (i);
      i++;
    }
  if (client->chan[i] && strcmp(client->chan[i], chan) == 0)
    return (i);
  return (-1);
}
