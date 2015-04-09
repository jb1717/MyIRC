##
## Makefile for MyIRC in /home/jibb/rendu/PSU_2014_myirc
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Tue Apr  7 16:05:55 2015 Jean-Baptiste Grégoire
## Last update Wed Apr  8 23:49:06 2015 Jean-Baptiste Grégoire
##

NAME	=	MyIRC

SERVER	=	src/server

CLIENT	=	src/client

$(NAME):
	make -C $(SERVER)
	make -C $(CLIENT)

all:	$(NAME)

$(SERVER):
	make -C $(SERVER)

$(CLIENT):
	make -C $(CLIENT)

clean:
	make -C $(SERVER) clean
	make -C $(CLIENT) clean

fclean:	clean
	make -C $(SERVER) fclean
	make -C $(CLIENT) fclean

re:	fclean all

.PHONY:	re fclean clean all
