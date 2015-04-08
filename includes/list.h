/*
** list.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/utils
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 01:36:27 2015 Jean-Baptiste Grégoire
** Last update Wed Apr  8 02:01:12 2015 Jean-Baptiste Grégoire
*/

#ifndef LIST_H_
# define LIST_H_

# include <stddef.h>

enum			e_state
  {
    READY = 0, SENDING, RECEIVING, WAITING
  };

enum			e_right
  {
    CHANOP = 0, USER
  };

typedef enum e_state	t_state;
typedef enum e_state	t_right;

typedef struct		s_client
{
  int			fd;
  t_state		state;
  t_right		perms;
  char			login[32];
  char			chan[32];
  struct s_client	*next;
}			t_client;

typedef struct		s_chan
{
  char			name[32];
  t_client		*client_list;
}			t_chan;

void			list__delete(t_client **list, t_client *elem);
void			list__add(t_client **list, t_client *elem);
size_t			list__len(t_client *begin);

#endif /* !LIST_H_ */
