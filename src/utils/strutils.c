/*
** strutils.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/utils
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Tue Apr  7 16:37:45 2015 Jean-Baptiste Grégoire
** Last update Wed Apr  8 21:52:48 2015 Jean-Baptiste Grégoire
*/

#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

char	*strchr_n(char *str, char c, int n)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (n == 1 && str[i] == c)
	return (&(str[i]));
      if (str[i] == c)
	n--;
      i++;
    }
  return (NULL);
}

void	replace_all_occ(char *str, char c, char d)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	str[i] = d;
      i++;
    }
}

char            *m_strcat(char *dest, char *src)
{
  char          *res;
  int           len;

  len = (dest ? strlen(dest) : 0) + (src ? strlen(src) : 0);
  if ((res = realloc(dest, sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  if (!dest)
    strcpy(res, src);
  else
    res = strcat(res, src);
  return (res);
}
