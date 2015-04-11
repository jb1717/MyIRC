/*
** init.c for client in /home/patoche/rendu/Unix/PSU_2014_myirc/src/client
**
** Made by Hugo Prenat
** Login   <prenat_h@epitech.eu>
**
** Started on  Fri Apr 10 16:34:09 2015 Hugo Prenat
** Last update Sat Apr 11 00:38:29 2015 Hugo Prenat
*/

#include "client.h"

void		create_list(GtkWidget *grid, t_client *client)
{
  GtkWidget	*frame;
  GtkWidget	*scroll;

  frame = gtk_frame_new(NULL);
  scroll = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scroll),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  client->list_user = gtk_text_view_new();
  gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(client->list_user), FALSE);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(client->list_user), FALSE);
  gtk_widget_set_size_request(client->list_user, 150, 150);
  gtk_widget_set_vexpand(client->list_user, TRUE);
  gtk_container_add(GTK_CONTAINER (scroll), client->list_user);
  gtk_container_add(GTK_CONTAINER(frame), scroll);
  gtk_container_set_border_width(GTK_CONTAINER(frame), 2);
  gtk_grid_attach(GTK_GRID(grid), frame, 10, 0, 10, 1);
}

void		create_msg(GtkWidget *grid, t_client *client)
{
  GtkWidget	*frame;
  GtkWidget	*scroll;

  frame = gtk_frame_new(NULL);
  scroll = gtk_scrolled_window_new (NULL, NULL);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW (scroll),
				 GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  client->messages = gtk_text_view_new();
  gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(client->messages), FALSE);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(client->messages), FALSE);
  gtk_widget_set_hexpand(client->messages, TRUE);
  gtk_widget_set_vexpand(client->messages, TRUE);
  gtk_container_add(GTK_CONTAINER (scroll), client->messages);
  gtk_container_add(GTK_CONTAINER(frame), scroll);
  gtk_container_set_border_width(GTK_CONTAINER(frame), 2);
  gtk_grid_attach(GTK_GRID(grid), frame, 0, 0, 10, 10);
}

void	create_entry(GtkWidget *grid, t_client *client)
{
  client->entry = gtk_entry_new();
  gtk_widget_set_hexpand(client->entry, TRUE);
  gtk_grid_attach (GTK_GRID(grid), client->entry, 0, 10, 1, 20);
}

void		create_interface(t_client *client)
{
  GtkWidget	*grid;
  GtkWidget	*all_widget;

  grid = gtk_grid_new();
  all_widget = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(client->window), all_widget);
  create_msg(grid, client);
  create_list(grid, client);
  create_entry(grid, client);
  g_signal_connect(G_OBJECT(client->entry), "activate", G_CALLBACK(write_sock),
		   (t_client *)client);
  gtk_box_pack_start(GTK_BOX(all_widget), grid, TRUE, TRUE, 0);
}

void	init(char *name, int width, int length, t_client *client)
{
  client->fd = -1;
  client->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_skip_taskbar_hint(GTK_WINDOW(client->window),  TRUE);
  gtk_window_set_default_size(GTK_WINDOW(client->window), width, length);
  gtk_window_set_title(GTK_WINDOW(client->window), name);
  g_signal_connect(client->window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_container_set_border_width (GTK_CONTAINER(client->window), 5);
  create_interface(client);
  g_timeout_add(1, (GSourceFunc)check_socket, client);
}
