/*
** client.h for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Wed Apr  8 16:43:56 2015 Hugo Prenat
** Last update Sat Apr 11 02:19:23 2015 Hugo Prenat
*/

#ifndef CLIENT_H
# define CLIENT_H

# include <stdlib.h>
# include <gtk/gtk.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <string.h>

# define UNUSED		__attribute__((unused))
# define BUFF_SIZE	4096

typedef struct	s_client
{
  int		fd;
  GtkWidget	*window;
  GtkWidget	*entry;
  GtkWidget	*messages;
  GtkWidget	*list_user;
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
void		create_list(GtkWidget *, t_client *);
void		create_msg(GtkWidget *, t_client *);
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
int		connect_to_serv(const gchar *);

/*
** Client cmd
*/

void		find_cmd(t_client *, char *);
void		nick_cmd(t_client *, char *);

#endif /* !CLIENT_H */
