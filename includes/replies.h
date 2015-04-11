/*
** error.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Fri Apr 10 20:56:27 2015 Jean-Baptiste Grégoire
** Last update Fri Apr 10 22:03:31 2015 Jean-Baptiste Grégoire
*/

#ifndef REPLIES_H_
# define REPLIES_H_

# include <stdarg.h>

# define RPL_BUF_SIZE	256

/*
** USER
*/
# define RPL_USERSTART	"392 %s :%s %s"
# define RPL_USERS	"393 %s :%s"
# define RPL_ENDOFUSERS	"394 %s :End of users"
# define RPL_NOUSERS	"395 %s :Nobody logged in"

#endif /* !REPLIES_H_ */
