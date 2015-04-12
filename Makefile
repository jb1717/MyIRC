##
## Makefile for MyIRC in /home/jibb/rendu/PSU_2014_myirc
##
## Made by Jean-Baptiste Grégoire
## Login   <jibb@epitech.net>
##
## Started on  Tue Apr  7 16:05:55 2015 Jean-Baptiste Grégoire
## Last update Sun Apr 12 15:15:46 2015 Jean-Baptiste Grégoire
##

BIN1	= 	server

BIN2	= 	client

SERVER	=	src/server/

CLIENT	=	src/client/

LINK	= 	ln -fs

RM	= 	rm -f

all:
	make -C $(SERVER)
	$(LINK) $(SERVER)$(BIN1) $(BIN1)
	make -C $(CLIENT)
	$(LINK) $(CLIENT)$(BIN2) $(BIN2)

server:
	make -C $(SERVER)
	$(LINK) $(SERVER)$(BIN1) $(BIN1)

client:
	make -C $(CLIENT)
	$(LINK) $(CLIENT)$(BIN2) $(BIN2)

clean:
	make -C $(SERVER) clean
	make -C $(CLIENT) clean

fclean:
	make -C $(SERVER) fclean
	make -C $(CLIENT) fclean
	$(RM) $(BIN1)
	$(RM) $(BIN2)

re:	fclean all

.PHONY:	re fclean clean all
