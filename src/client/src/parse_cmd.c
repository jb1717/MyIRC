/*
** parse_cmd.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Sun Apr 12 04:23:30 2015 Hugo Prenat
** Last update Sun Apr 12 23:28:19 2015 Hugo Prenat
*/

#include "client.h"

void	fill_nick(int exc, int dot, char *nick, char *buff)
{
  int	i;

  i = 0;
  while (i != exc - dot)
    {
      nick[i] = buff[i + dot];
      i++;
    }
}

char	*get_nick_from_msg(char *buff)
{
  int	dot;
  int	exc;
  char	*nick;

  dot = 0;
  exc = 0;
  nick = NULL;
  while (buff[dot] && buff[dot] != ':')
    dot++;
  if (buff[dot++] == ':')
    while (buff[exc] && buff[exc] != ' ')
      exc++;
  else
    return (NULL);
  if (buff[exc] == ' ')
    {
      if ((nick = calloc((exc - dot + 1), sizeof(*nick))) == NULL)
	return (NULL);
      fill_nick(exc, dot, nick, buff);
    }
  return (nick);
}

char	*get_chan_from_msg(char *buff)
{
  char	*chan;
  char	*first;
  char	*end;

  first = index(buff, ' ') + 1;
  chan = index(first, ' ') + 1;
  end = index(chan, ' ');
  end[0] = '\0';
  return (chan);
}

char	*get_msg_from_msg(char *buff)
{
  char	*first;
  char	*msg;

  if (strcocc(buff, ":") < 2)
    return (index(buff, ':') + 1);
  first = index(buff, ':') + 1;
  msg = index(first, ':') + 1;
  return (msg);
}
