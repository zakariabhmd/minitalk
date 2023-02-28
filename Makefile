
NAMES = server
NAMEC = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = server_bonus.c client_bonus.c 
cli = client_bonus.c 
ser = server_bonus.c
Util = utils_bonus.c 
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