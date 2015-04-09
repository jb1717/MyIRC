/*
** utils.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Wed Apr  8 21:22:42 2015 Jean-Baptiste Grégoire
** Last update Wed Apr  8 23:44:59 2015 Jean-Baptiste Grégoire
*/

#ifndef UTILS_H_
# define UTILS_H_

# define READ_SIZE	4096

int	write_data(int fd, char *data);
char	*strchr_n(char *str, char c, int n);
char	*m_strcat(char *dest, char *src);
char	*read_input(int fd);
void	replace_all_occ(char *str, char c, char d);

#endif /* !UTILS */
