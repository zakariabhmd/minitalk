
NAMES = server
NAMEC = client

NAME_SB = server_bonus
NAME_CB = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = server.c client.c 
SRC_B = server_bonus.c client_bonus.c
cli = client.c 
cli_b = client_bonus.c
ser = server.c
ser_b = server_bonus.c
Util = utils.c 
Util_b = utils_bonus.c
OBJ = $(SRC: .c=.o)


all: $(NAMES) $(NAMEC) 
bonus: $(NAME_CB) $(NAME_SB)

 $(NAME):
	@$(CC) $(CFLAGS) $(SRC) $(Util) -o $(NAMEC) $(NAMES)
	@$(CC) $(CFLAGS) $(SRC_B) $(Util_b) -o $(NAME_CB) $(NAME_SB) 

server:
	@$(CC) $(CFLAGS) $(ser) $(Util) -o $(NAMES)
client:
	@$(CC) $(CFLAGS) $(cli) $(Util) -o $(NAMEC)

server_bonus:
	@$(CC) $(CFLAGS) $(ser_b) $(Util_b) -o $(NAME_SB)
client_bonus:
	@$(CC) $(CFLAGS) $(cli_b) $(Util_b) -o $(NAME_CB)

clean:
	@$(RM) $(NAMEC) $(NAMES)

fclean: clean
	@$(RM) $(NAMEC) $(NAMES) $(NAME_SB) $(NAME_CB)

re: fclean all