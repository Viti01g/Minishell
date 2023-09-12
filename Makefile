NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic
THR = -lpthread
INCLUDES = /headers/minishell.h /libft/libft.h
SOURCES_E = /sources_executer/*.c
SOURCES_P = /sources_parser/*.c
SOURCES_S = /sources_shell/*.c
MAIN = main.c
LIBFT = libft/libft_b.a
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean fclean f re

$(NAME): $(LIBFT) $(OBJECTS) $(MAIN) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) $(MAIN) $(THR) -o $(NAME)
$(LIBFT):
	make bonus -C libft/
all = $(NAME)
clean:
	/bin/rm -rf $(OBJECTS)
	make clean -C libft/
fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(LIBFT)
f: fclean
re: fclean all
