##
## Makefile<server> for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Tue Apr  7 16:20:20 2015 Jean-Baptiste Grégoire
## Last update Sun Apr 12 11:43:08 2015 Jean-Baptiste Grégoire
##

DEBUG		= 	yes

NAME		=	server

SRC		=	main.c			\
			auth.c			\
			func_call.c		\
			handle_event.c		\
			quit.c			\
			messages.c		\
			replies.c		\
			manage_channel.c	\
			welcome.c		\
			../utils/c_buffer.c	\
			../utils/io.c		\
			../utils/list.c		\
			../utils/strutils.c	\
			../utils/free.c		\
			../interface/inet.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CC		=	gcc

INCLUDES	=	../../includes/

CFLAGS		=	-W -Wall -Wextra -I $(INCLUDES)

ifeq ($(DEBUG),yes)
	CFLAGS 	+= -g3
else
	CFLAGS	+= -O3
endif

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHNOY:		re fclean clean all
