# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngastana  < ngastana@student.42urduliz.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/17 16:01:13 by ngastana          #+#    #+#              #
#    Updated: 2024/03/25 16:41:55 by ngastana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Pipex
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-g3 -fsanitize=address
OBJ_DIR = obj

SRC_FILES = pipex.c \
			split.c \
			utils.c \
			children.c \
			free_exit.c

.SILENT:

CLR_RMV     := \033[0m
GREEN       := \033[1;32m
YELLOW      := \033[0;33m
BLUE        := \033[0;34m
CYAN        := \033[0;36m

OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INCLUDE = pipex.h

all: $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) -c -g $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(GREEN)✓ $(NAME) created ✓\n"

clean:
	rm -rf $(OBJ_DIR)
	@echo "\n${WHITE} ◎ $(BLUE)All objects cleaned successfully\n"


fclean:
	rm -f $(NAME)
	@echo "\n${WHITE} ◎ $(BLUE)Executable cleaned successfully\n"

re: fclean all

.PHONY: all clean fclean re lib