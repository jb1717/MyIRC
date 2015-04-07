##
## Makefile for MyIRC in /home/jibb/rendu/PSU_2014_myirc
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Tue Apr  7 16:05:55 2015 Jean-Baptiste Grégoire
## Last update Tue Apr  7 16:19:15 2015 Jean-Baptiste Grégoire
##

NAME	=	MyIRC

SERVER	=	src/server

CLIENT	=	src/client

$(NAME):
	make --no-print-directory -C $(SERVER)
	make --no-print-directory -C $(CLIENT)

all:	$(NAME)

clean:
	make --no-print-directory -C $(SERVER) clean
	make --no-print-directory -C $(CLIENT) clean

fclean:	clean
	make --no-print-directory -C $(SERVER) fclean
	make --no-print-directory -C $(CLIENT) fclean

re:	fclean all

.PHONY:	re fclean clean all
