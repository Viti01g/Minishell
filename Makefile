NAME = minishell
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I ./headers -I ./libft/libft.h #-g3 -fsanitize=address

RM = rm -f

TKN_SRC = tokenizer.c token_utils.c token_memory.c token_operators.c quotes.c quotes_utils.c delete_quotes.c
SIG_SRC = signal.c signal_child.c signal_parent.c
BUI_SRC = cd.c echo.c env.c exec_builtins.c exit.c export.c pwd.c unset.c export_utils.c
SRC_SRC = init_utils.c init_vars.c main.c utils.c more_utils.c
EXP_SRC = expander.c expander_utils.c
EXE_SRC = exec_utils.c exec.c exec_utils_2.c redir_utils.c more_redir_utils.c more_exec_utils.c check_exec_utils.c heredoc.c her_utils.c
PRS_SRC = is_command.c categorize_arguments.c parser_utils.c

SRC = $(TKN_SRC) $(SIG_SRC) $(SRC_SRC) $(BUI_SRC) $(EXP_SRC) $(EXE_SRC) $(PRS_SRC)

INCLUDES = ./headers/minishell.h ./libft/libft.h
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRC_DIR = ./src/
EXE_DIR = $(SRC_DIR)executor/
EXP_DIR = $(SRC_DIR)expander/
SIG_DIR = $(SRC_DIR)signals/
TKN_DIR = $(SRC_DIR)tokenizer/
BUI_DIR = $(SRC_DIR)builtins/
EXP_DIR = $(SRC_DIR)expander/
PRS_DIR = $(SRC_DIR)parser/
OBJ_DIR = ./obj/

OBJ_FILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# READLINE
RLINE_INC	= -I/sgoinfre/students/$(USER)/homebrew/opt/readline/include
RLINE_L		= -lreadline -L /sgoinfre/students/$(USER)/homebrew/opt/readline/lib

# READLINE
RLINE_INC_2   = -I/usr/local/Cellar/readline/8.2.7/include
RLINE_L_2     = -lreadline -L/usr/local/Cellar/readline/8.2.7/lib

# COLOURS
GREEN = \033[0;32m
COLOR_OFF = \033[0m

# RULES
all: $(OBJ_DIR) $(LIBFT_DIR) $(NAME)

$(LIBFT): $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

#Different folders for the .o

$(OBJ_DIR)%.o: $(TKN_DIR)%.c
	@$(CC) $(CFLAGS) $(RLINE_INC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SIG_DIR)%.c
	@$(CC) $(CFLAGS) $(RLINE_INC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BUI_DIR)%.c
	@$(CC) $(CFLAGS) $(RLINE_INC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(RLINE_INC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(RLINE_INC) -c $< -o $@

$(OBJ_DIR)%.o: $(EXE_DIR)%.c
	@$(CC) $(CFLAGS) $(RLINE_INC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(EXP_DIR)%.c
	@$(CC) $(CFLAGS) $(RLINE_INC) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(PRS_DIR)%.c
	@$(CC) $(CFLAGS) $(RLINE_INC) $(CPPFLAGS) -c $< -o $@

# basic library compiled
$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(DEBUG) $(OBJ) $(LIBFT) $(RLINE_L) $(LDFLAGS) -o $(NAME)
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