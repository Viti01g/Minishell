# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uliherre <uliherre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 19:37:36 by ulherrer          #+#    #+#              #
#    Updated: 2022/07/17 20:50:28 by uliherre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
NAME_BONUS = libft_b.a

CC = gcc -std=c89 #clang -std=c89
CFLAGS = -Wall -Wextra -Werror -pedantic

INCLUDE = libft.h

SOURCES = \
ft_atoi.c \
ft_atol.c \
ft_itoa.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isxdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_isupper.c \
ft_islower.c \
ft_toupper.c \
ft_tolower.c \
ft_bzero.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_calloc.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_striteri.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_puterror.c \
ft_strrev.c \
ft_time_diff.c \
ft_time_now.c

SOURCES_BONUS = \
ft_lstadd_back_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstclear_bonus.c \
ft_lstdelone_bonus.c \
ft_lstiter_bonus.c \
ft_lstlast_bonus.c \
ft_lstmap_bonus.c \
ft_lstnew_bonus.c \
ft_lstsize_bonus.c

ALL_SOURCES = $(SOURCES) $(SOURCES_BONUS)

OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)
ALL_OBJECTS = $(OBJECTS) $(OBJECTS_BONUS)

.PHONY: all clean fclean f re

$(NAME): $(OBJECTS) $(INCLUDE)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

$(NAME_BONUS): $(OBJECTS) $(OBJECTS_BONUS) $(INCLUDE)
	ar rc $(NAME_BONUS) $(OBJECTS) $(OBJECTS_BONUS)
	ranlib $(NAME_BONUS)
	cp $(NAME_BONUS) $(NAME)

all: $(NAME)
bonus: $(NAME_BONUS)
clean:
	/bin/rm -rf $(ALL_OBJECTS)
fclean: clean
	/bin/rm -rf $(NAME) $(NAME_BONUS)
f: fclean
re: fclean all
