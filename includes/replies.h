/*
** error.h for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src/server
**
** Made by Jean-Baptiste Grégoire
** Login   <jibb@epitech.net>
**
** Started on  Fri Apr 10 20:56:27 2015 Jean-Baptiste Grégoire
** Last update Sun Apr 12 23:19:15 2015 Jean-Baptiste Grégoire
*/

#ifndef REPLIES_H_
# define REPLIES_H_

# include <stdarg.h>

# define RPL_BUF_SIZE	256

# define RPL_GEN_CMD	":irc.myirc.org %s %s :%s"

/*
** USERS
*/
# define RPL_USERSTART	":irc.myirc.org 392 %s :Users:"
# define RPL_USERS	":irc.myirc.org 393 %s :%s"
# define RPL_ENDOFUSERS	":irc.myirc.org 394 %s :End of users"
# define RPL_NOUSERS	":irc.myirc.org 395 %s :Nobody logged in"

/*
** LIST
*/
# define RPL_LISTSTART	":irc.myirc.org 321 %s :Channel:"
# define RPL_LIST	":irc.myirc.org 322 %s :%s"
# define RPL_LISTEND	":irc.myirc.org 323 %s :End of /LIST"

/*
** JOIN
*/
# define RPL_NAMREPLY	":irc.myirc.org 353 %s"
# define RPL_ENDOFNAMES	":irc.myirc.org 366 %s :End of /NAMES list"
# define RPL_TOPIC	":irc.myirc.org 332 %s :%s"

/*
** AUTH
*/
# define ERR_ALREADYREG	":irc.myirc.org 462 :You may not reregister"
# define ERR_NOTREG	":irc.myirc.org 451 :You have not registered"
# define RPL_INFO_1	":irc.myirc.org 001 %s :Welcome to the MSN server"
# define RPL_INFO_2	":irc.myirc.org 002 %s :This server is running \
on the version 0.1"
# define RPL_INFO_3	":irc.myirc.org 003 %s USERS :are supported by \
this server"
# define ERR_NICKCOLLI	":irc.myirc.org 436 %s :Ignored. Nickname collision, \
please choose another one"

#endif /* !REPLIES_H_ */
