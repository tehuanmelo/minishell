NAME = minishell
SRCFILES =\
main.c
vpath %.c src
OBJPATH = obj/
LIBFT = inc/libft
OBJ = $(patsubst %.c, $(OBJPATH)%.o, $(SRCFILES))
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
# CFLAGS = -Wall -Werror -Wextra -g3 
# CFLAGS = -Wall -Werror -Wextra -pthread -g3 -fsanitize=address
# CFLAGS = -Wall -Werror -Wextra -pthread -g3 -fsanitize=thread

.SILENT:

all:	$(MAKELIBFT) $(OBJPATH) $(NAME)

$(MAKELIBFT):
	cd $(LIBFT) && $(MAKE)

$(OBJPATH):
	mkdir $(OBJPATH)

$(NAME):	$(OBJ)
	cd $(LIBFT) && $(MAKE)	
	$(CC) $(CFLAGS) $^ $(LIBFT)/libft.a -o $@ -lreadline
	echo "\033[30;43;1;3mCompilation done successfully!\033[0m"

$(OBJPATH)%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJPATH)
	cd $(LIBFT) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd $(LIBFT) && $(MAKE) fclean

re:		fclean all