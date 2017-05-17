#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochayche <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 18:15:02 by ochayche          #+#    #+#              #
#    Updated: 2017/03/05 22:47:28 by ochayche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME1 = asm
NAME2 = corewar


SRC_PATH = src
INC_PATH = .
OBJ_PATH = .
LIB_PATH = libft
PTF_PATH = ft_printf

SRC_NAME =	main.c \
			

INC_NAME = 

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LIB = 	libft.a
PTF =	libftprintf.a

all: $(LIB) $(PTF) $(NAME)
	
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB_PATH)/$(LIB) $(PTF_PATH)/$(PTF)

$(LIB):
	@make -C $(LIB_PATH)/

$(PTF):
	@make -C $(PTF_PATH)/

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make -C $(LIB_PATH)/ clean
	make -C $(PTF_PATH)/ clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIB_PATH)/$(LIB)
	rm -rf $(PTF_PATH)/$(PTF)

re: fclean all

r: all
	./$(NAME) < test7

bug:
	$(CC) -g $(FLAGS) -o $(NAME) $(SRC) $(LIB_PATH)/$(LIB) $(PTF_PATH)/$(PTF)

debug: bug
	lldb -- $(NAME) -f test02