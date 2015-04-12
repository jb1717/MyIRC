/*
** utils.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Apr 12 03:47:35 2015 Hugo Prenat
** Last update Sun Apr 12 04:04:00 2015 Hugo Prenat
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
