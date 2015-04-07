##
## Makefile<client> for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Tue Apr  7 16:20:25 2015 Jean-Baptiste Grégoire
## Last update Tue Apr  7 16:23:27 2015 Jean-Baptiste Grégoire
##

DEBUG		= 	no

NAME		=	client

SRC		=	main.c

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CC		=	gcc

INCLUDES	=	includes/

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
