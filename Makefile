
NAMES = server
NAMEC = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = server.c client.c 
cli = client.c 
ser = server.c
Util = utils.c 
OBJ = $(SRC: .c=.o)

all: $(NAMES) $(NAMEC)

 $(NAME):
	@$(CC) $(CFLAGS) $(SRC) $(Util) -o $(NAMEC) $(NAMES)
	
server:
	@$(CC) $(CFLAGS) $(ser) $(Util) -o $(NAMES)
client:
	@$(CC) $(CFLAGS) $(cli) $(Util) -o $(NAMEC)


clean:
	@$(RM) $(NAMEC) $(NAMES)

fclean: clean
	@$(RM) $(NAMEC) $(NAMES)

re: fclean all