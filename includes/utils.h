/*
** utils.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 21:22:42 2015 Jean-Baptiste Grégoire
** Last update Fri Apr 10 12:56:17 2015 Jean-Baptiste Grégoire
*/

#ifndef UTILS_H_
# define UTILS_H_

# define READ_SIZE	4096

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int	write_data(int fd, char *data);
int	is_in(char *str, char **tab, int flag);
char	*strchr_n(char *str, char c, int n);
char	*m_strcat(char *dest, char *src);
char	*read_input(int fd);
char	**parse_args(char *param, int nb_args, char *delim);
void	replace_all_occ(char *str, char c, char d);
void	*my_free(void *ptr);
size_t	strcocc(char *str, char *accept);

#endif /* !UTILS */
