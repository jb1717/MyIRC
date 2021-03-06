/*
** interface.c for myftp in /home/jibb/rendu/PSU_2014_myftp
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Tue Mar 10 11:47:41 2015 Jean-Baptiste Grégoire
** Last update Fri Apr 10 16:08:04 2015 Jean-Baptiste Grégoire
*/

#include "utils.h"

static int	check()
{
  if (READ_SIZE < 2)
    {
      printf("Please set a BUF_SIZE above 2\n");
      return (-1);
    }
  return (0);
}

static int	end_input(char *str)
{
  int		i;

  i = strlen(str) - 1;
  if (str[i] == '\n')
    {
      str[i] = '\0';
      return (1);
    }
  return (0);
}

char		*read_input(int fd)
{
  char		buffer[READ_SIZE + 1];
  char		*dest;
  int		ret;

  if (check() == -1)
    return (NULL);
  bzero(buffer, READ_SIZE + 1);
  ret = 1;
  dest = NULL;
  while ((ret = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[ret] = '\0';
      if ((dest = m_strcat(dest, buffer)) == NULL)
	return (my_free(dest));
      if (end_input(dest))
	return (dest);
    }
  if (ret == -1)
    return (my_free(dest));
  return (dest);
}

int		write_data(int fd, char *data)
{
  if (!data)
    return (0);
  if (write(fd, data, strlen(data)) == -1)
    return (-1);
  return (0);
}

char		**parse_args(char *param, int nb_args, char *delim)
{
  int           i;
  char          *tmp;
  char		**tab;

  if (nb_args == 0)
    nb_args = strcocc(param, delim);
  nb_args += 1;
  if ((tab = malloc(sizeof(char *) * (nb_args + 1))) == NULL)
    return (NULL);
  bzero(tab, sizeof(char *) * (nb_args + 1));
  i = 0;
  tmp = strtok(param, delim);
  while (tmp && i < nb_args)
    {
      tab[i] = tmp;
      tmp = strtok(NULL, delim);
      i++;
    }
  return (tab);
}
