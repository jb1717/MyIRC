/*
** inet.c for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/interface
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Tue Apr  7 16:30:16 2015 Jean-Baptiste Grégoire
** Last update Tue Apr  7 16:33:45 2015 Jean-Baptiste Grégoire
*/

#include "interface.h"

int		inet__create_sock(int port, char *protocol, int domain,
				  int max_connexions)
{
  struct protoent       *proto;
  struct sockaddr_in    addr;
  int                   _true;
  int                   sockfd;

  addr.sin_family = domain;
  _true = 1;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(port);
  if ((proto = getprotobyname(protocol)) == NULL)
    return (-1);
  if ((sockfd = socket(domain, SOCK_STREAM, proto->p_proto)) == -1)
    return (-1);
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &_true, sizeof(int))
      == -1)
    return (-1);
  if (bind(sockfd, (const struct sockaddr *)(&addr), sizeof(addr)) == -1)
    return (-1);
  if (listen(sockfd, max_connexions) == -1)
    return (-1);
  return (sockfd);
}

int		inet__get_sock(char *ip, int port, char *protocol, int domain)
{
  struct sockaddr_in    client;
  struct protoent       *proto;
  struct in_addr        inp;
  int                   sockfd;

  client.sin_family = domain;
  if (inet_aton(ip, &inp) == 0)
    return (-1);
  client.sin_addr.s_addr = inp.s_addr;
  client.sin_port = htons(port);
  if ((proto = getprotobyname(protocol)) == NULL)
    return (-1);
  if ((sockfd = socket(domain, SOCK_STREAM, proto->p_proto)) == -1)
    return (-1);
  if (connect(sockfd, (const struct sockaddr *)(&client), sizeof(client))
      == -1)
    {
      close(sockfd);
      return (-1);
    }
  return (sockfd);
}

void		inet__convert_port(uint8_t *p1, uint8_t *p2,
				   int *p, enum e_conversion e)
{
  if (e == SET_PORT)
    *p = *p1 * 256 + *p2;
  else
    {
      *p2 = *p % 256;
      *p1 = (*p - *p2) / 256;
    }
}

void		inet__format_ip_address(char *ip, int port, t_iport *s,
				       enum e_conversion e)
{
  char		*str_port;

  if (e == GET_PORT)
    {
      s->ip = strdup(ip);
      if ((str_port = strchr_n(s->ip, ',', 4)) == NULL)
	return ;
      *str_port = '\0';
      ++str_port;
      replace_all_occ(s->ip, ',', '.');
      s->p1 = atoi(strtok(str_port, ","));
      s->p2 = atoi(strtok(NULL, ","));
      s->port = s->p1 * 256 + s->p2;
    }
  else
    {
      strcpy(s->iport, ip);
      replace_all_occ(s->iport, '.', ',');
      inet__convert_port(&(s->p1), &(s->p2), &port, GET_PORT);
      sprintf(s->iport, "%s,%d,%d", s->iport, s->p1, s->p2);
    }
}
