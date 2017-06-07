#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/05 19:07:36 by ochayche          #+#    #+#              #
#    Updated: 2017/06/05 19:07:37 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
# CFLAGS = -Wall -Wextra -Werror
SHELL = /bin/sh

LIB_DIR = ../libft
PTF_DIR = ../ft_printf
LIB = 	libft.a
PTF =	libftprintf.a

################################################################################
#	COREWAR
################################################################################
NAME = corewar

#********* -INC
INC_NAME =	corewar.h
INC_DIR =	inc
INC = $(addprefix $(INC_DIR)/, $(INC_NAME))

#********* -OBJ
OBJ_DIR =	.obj
OBJ = $(subst .c,.o,$(subst $(SRC_DIR)/,$(OBJ_DIR)/,$(SRC)))

#********* -SRC
SRC_DIR =	src
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAME))
SRC_NAME =			main.c		\
					destruct.c	\
					init_data.c
# add .c file ---->

################################################################################
#	RULES
################################################################################

.PHONY: all clean fclean re t

all: $(LIB) $(PTF) $(NAME)

$(NAME): $(OBJ) $(INC)
	$(CC) $(CFLAGS) -I./inc/ $(OBJ) -L./$(PTF_DIR) -lftprintf -L./$(LIB_DIR) -lft -o $(NAME)
	

$(LIB):
	@make -C $(LIB_DIR)

$(PTF):
	@make -C $(PTF_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -I./inc/ -c $(CFLAGS) $? -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR)/ clean
	make -C $(PTF_DIR)/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB_DIR)/$(LIB)
	rm -f $(PTF_DIR)/$(PTF)

re: fclean all

r:	$(NAME)
	./$(NAME) -dump