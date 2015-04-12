/*
** error.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Fri Apr 10 20:35:28 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 15:04:38 2015 Jean-Baptiste Grégoire
*/

#include "server.h"
#include "replies.h"

t_rpl const		*get_rpl_tab()
{
  static const t_rpl	tab[] = {{392, RPL_USERSTART},
				 {393, RPL_USERS},
				 {394, RPL_ENDOFUSERS},
				 {395, RPL_NOUSERS},
				 {321, RPL_LISTSTART},
				 {322, RPL_LIST},
				 {323, RPL_LISTEND},
				 {353, RPL_NAMREPLY},
				 {366, RPL_ENDOFNAMES},
				 {462, ERR_ALREADYREG},
				 {451, ERR_NOTREG},
				 {1, RPL_GEN_CMD},
				 {11, RPL_INFO_1},
				 {12, RPL_INFO_2},
				 {13, RPL_INFO_3},
				 {436, ERR_NICKCOLLI},
				 {0, NULL}};

  return (tab);
}

void			send_rpl(t_client *dest, int n, ...)
{
  va_list		arg;
  int			i;
  t_rpl	const		*tab;
  char			buf[RPL_BUF_SIZE];

  i = 0;
  tab = get_rpl_tab();
  va_start(arg, n);
  bzero(buf, RPL_BUF_SIZE);
  while (tab[i].n)
    {
      if (tab[i].n == n)
	{
	  vsprintf(buf, tab[i].msg, arg);
	  send_message(dest, buf);
	}
      i++;
    }
  va_end(arg);
}
