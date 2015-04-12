/*
** client.h for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Wed Apr  8 16:43:56 2015 Hugo Prenat
** Last update Sun Apr 12 23:25:22 2015 Hugo Prenat
*/

#ifndef CLIENT_H
# define CLIENT_H

# include <stdlib.h>
# include <gtk/gtk.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <string.h>
# include "utils.h"

# define UNUSED		__attribute__((unused))
# define BUFF_SIZE	4096

typedef struct	s_client
{
  int		fd;
  GtkWidget	*window;
  GtkWidget	*notebook;
  GtkWidget	*entry;
  GtkWidget	**messages;
  char		**chan;
  char		*nick;
}		t_client;

typedef struct	s_func
{
  const char    *str;
  void          (*func)();
}		t_func;

/*
** Init Functions
*/

void		init(char *, int, int, t_client *);
void		create_msg(t_client *, char *);
void		create_entry(GtkWidget *, t_client *);
void		create_interface(t_client *);

/*
** Write functions
*/

void		write_sock(GtkWidget *, gpointer);
void		put_text_in_entry(GtkWidget *, char *, int);

/*
** Network functions
*/

gboolean	check_socket(t_client *);
int		inet__get_sock(char *, int, char *, int);
int		connect_to_serv(t_client *, const gchar *);

/*
** Chan functions
*/

void		add_chan(t_client *, char *);
void		remove_chan(t_client *, char *);
int		get_chan(t_client *, char *);

/*
** Client cmd
*/

void		find_cmd(t_client *, char *);
void		nick_cmd(t_client *, char *);
void		list_cmd(t_client *, char *);
void		join_cmd(t_client *, char *);
void		part_cmd(t_client *, char *);
void		users_cmd(t_client *, char *);
void		msg_cmd(t_client *, char *);
void		send_cmd(t_client *, char *);
void		recv_cmd(t_client *, char *);

/*
** Parse functions
*/

char		*get_nick_from_msg(char *);
char		*get_chan_from_msg(char *);
char		*get_msg_from_msg(char *);

/*
** Utils
*/

void		add_msgbox(t_client *, GtkWidget *);
int		is_log(t_client *);
int		known_command(char *);
void		disconnect_client(t_client *);

#endif /* !CLIENT_H */
