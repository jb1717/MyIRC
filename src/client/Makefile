##
## Makefile<client> for MyIRC in /home/jibb/rendu/PSU_2014_myirc/src
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Tue Apr  7 16:20:25 2015 Jean-Baptiste Grégoire
## Last update Sun Apr 12 23:36:49 2015 Hugo Prenat
##

DEBUG		= 	no

NAME		=	client

SRC		=	src/main.c		\
			src/init.c		\
			src/network.c		\
			src/first_cmd.c		\
			src/list_cmd.c		\
			src/parse_cmd.c		\
			src/chan.c		\
			src/utils.c		\
			../utils/strutils.c	\
			../interface/inet.c

OBJDIR		=	obj/

OBJ		=	$(SRC:.c=.o)
#$(patsubst %.c, $(OBJDIR)%.o, $(SRC))

RM		=	rm -f

CC		=	gcc

GTKCFLAGS	=	$(shell pkg-config --cflags gtk+-3.0)

INCLUDES	=	-Iincludes/

INCLUDES	+=	-I../../includes/

CFLAGS		=	-W -Wall -Wextra $(INCLUDES) $(GTKCFLAGS)

LDFLAGS		=	$(shell pkg-config --libs gtk+-3.0)

ifeq ($(DEBUG),yes)

CFLAGS 		+= 	-g3

else

CFLAGS		+= 	-O3

endif

FIRST		:=	$(shell test -d $(OBJDIR) || mkdir $(OBJDIR))

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHNOY:		re fclean clean all
