NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./headers/minishell.h -I ./libft/libft.h
#DEBUG = -g3 -fsanitize=address
RM = rm -f
SRC = main.c ../signals/signal.c init_utils.c init_vars.c ../builtins/env.c ../builtins/pwd.c ../builtins/exit.c ../builtins/cd.c ../builtins/echo.c \
		../builtins/export.c ../builtins/unset.c ../builtins/exec_builtins.c \

INCLUDES = ./headers/minishell.h ./libft/libft.h
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SIG_DIR = ./signals/
BUI_DIR = ./builtins/
SRC_DIR = ./src/
OBJ_DIR = ./obj/

OBJ_FILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# READLINE
RLINE_INC	= -I/sgoinfre/students/$(USER)/homebrew/opt/readline/include
RLINE_L		= -lreadline -L /sgoinfre/students/$(USER)/homebrew/opt/readline/lib

# COLOURS
GREEN = \033[0;32m
COLOR_OFF = \033[0m

# RULES
all: $(OBJ_DIR) $(LIBFT_DIR) $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(RLINE_INC) -c $< -o $@

# basic library compiled
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT) $(RLINE_L) -o $(NAME)
	@echo "$(GREEN)#### minishell ####$(COLOR_OFF)"
	@echo "    -Has been compiled ✅"

# all .o files removed
clean:
	@$(RM) $(OBJ)
	@make clean -C libft
	@rm -rf $(OBJ_DIR)

# library .a file removed
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft
	@rm -rf $(OBJ_DIR)

re:	fclean all

.PHONY:	all clean fclean re