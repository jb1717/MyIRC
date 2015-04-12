/*
** parse_cmd.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Apr 12 04:23:30 2015 Hugo Prenat
** Last update Sun Apr 12 04:37:17 2015 Hugo Prenat
*/

#include "client.h"

char	*get_nick_from_msg(char *buff)
{
  int	dot;
  int	exc;
  int	i;
  char	*nick;

  dot = 0;
  exc = 0;
  i = 0;
  nick = NULL;
  while (buff[dot] && buff[dot] != ':')
    dot++;
  if (buff[dot] == ':')
    while (buff[exc] && buff[exc] != '!')
      exc++;
  if (buff[exc] == '!')
    {
      if ((nick = calloc((exc - dot + 1), sizeof(*nick))) == NULL)
	return (NULL);
      while (i != exc - dot)
	{
	  nick[i] = buff[i + dot];
	  i++;
	}
    }
  return (nick);
}
