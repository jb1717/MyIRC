/*
** func_call.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Thu Apr  9 22:20:34 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 22:31:45 2015 Jean-Baptiste Grégoire
*/

#include "server.h"

t_func const		*get_func_tab()
{
  static const t_func	tab[] = {{"nick", &nick_func, 2},
				 {"user ", &user_func, 4},
				 {"users", &users_func, 0},
				 {"privmsg", &message_func, 2},
				 {"list", &list_func, 1},
				 {"join", &join_func, 1},
				 {"part", &part_func, 1},
				 {"quit", &quit_func, 0},
				 {NULL, NULL, 0}};

  return (tab);
}

int			check_logged(t_client *client, char *input)
{
  if (!is_logged(client) && strncasecmp("nick", input, 4) != 0 &&
      (strncasecmp("user", input, 4) != 0 || input[4] == 's'))
    {
      send_rpl(client, 451);
      return (-1);
    }
  return (0);
}

int			call_func(t_server *s, t_client *client, char *input)
{
  int			i;
  t_func const		*func_tab;
  char			**params;

  i = 0;
  func_tab = get_func_tab();
  while (func_tab[i].name)
    {
      if (strncasecmp(func_tab[i].name, input, strlen(func_tab[i].name)) == 0)
	{
	  if (check_logged(client, input) ==  -1)
	    return (0);
	  if ((s->input = strdup(input)) == NULL)
	    return (-1);
	  params = parse_args(input, func_tab[i].nb_args, " \t\r\n");
	  func_tab[i].func(s, client, params);
	  free(s->input);
	  s->input = NULL;
	  break ;
	}
      i++;
    }
  return (0);
}

int		cmp_elem__client(void *elem1, void *elem2)
{
  t_client	*c1;
  t_client	*c2;

  c1 = (t_client *)elem1;
  c2 = (t_client *)elem2;
  if (c1->fd == c2->fd)
    return (1);
  return (0);
}
