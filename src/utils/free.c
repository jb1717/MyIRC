/*
** free.c for myftp in /home/jibb/rendu/PSU_2014_myftp/interface
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Sun Mar 22 11:11:48 2015 Jean-Baptiste Grégoire
** Last update Sun Mar 22 11:13:16 2015 Jean-Baptiste Grégoire
*/

#include <stdlib.h>

void	*my_free(void *ptr)
{
  free(ptr);
  return (NULL);
}
